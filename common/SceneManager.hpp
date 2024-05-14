#pragma once
#include "common/utils.hpp"
#include "common/GameObject.hpp"
#include "common/Scene.hpp"
#include "common/Event.hpp"
#include "common/SceneInit.hpp"


class SceneManager {
public:

const unsigned int SCR_WIDTH = 1280;
const unsigned int SCR_HEIGHT = 720;


protected: 
   Node root;
   unsigned int scene_i;
   std::vector<Scene* >s;
   InputManager I_M;
   int gameState=1; // negative = pause // 1=jeu // 2=gameOver // 3=Victory
public:
    SceneManager(){scene_i=0;}

    void changeSceneAndTP(Node* node, Event ev ){
        std::cout << s.size() <<std::endl;
        s[scene_i]->get_node_list()[0]->removeChild(node);
        s[scene_i]->removeNodeFromNodeList(node);
        ev.get_typeEvent()==typeEvent::TP_Scene_Forward ? scene_i++ : ev.get_typeEvent()==typeEvent::TP_Scene_Backward ? scene_i-- : scene_i ;
        node->getData()->set_pos(ev.getPos());
        //std::cout << scene_i <<std::endl;
    }
   
   void event(Node* node, Event ev){
        if(ev.get_typeEvent()==typeEvent::Previous_Camera){
            //std::cout << &I_M.current_cam <<std::endl;
            if(I_M.current_cam == static_cast<Camera*>(s[scene_i]->get_camera_list()[ev.getCP_i()])){//get_CP_i = camera number dans al liste de cam de la scene dans le cas prev et next_camera
                I_M.current_cam = static_cast<Camera*>(s[scene_i]->get_camera_list()[ev.getCP_i()-1]);
                I_M.view--;//std::cout << &I_M.current_cam <<std::endl;
                I_M.current_cam->set_front(s[scene_i]->getNodePlayer()->getData()->getpos()-I_M.current_cam->getpos());
                I_M.current_cam->setEulerAngle(Helper::quatToEuler(LookAt(I_M.current_cam->get_front(),I_M.current_cam->get_up())));
            }
        }
        else if(ev.get_typeEvent()==typeEvent::Next_Camera){
            //std::cout << &I_M.current_cam <<std::endl;
            if(I_M.current_cam == static_cast<Camera*>(s[scene_i]->get_camera_list()[ev.getCP_i()])){
                I_M.current_cam = static_cast<Camera*>(s[scene_i]->get_camera_list()[ev.getCP_i()+1]);//std::cout << &I_M.current_cam <<std::endl;
                I_M.view++;
                I_M.current_cam->set_front(s[scene_i]->getNodePlayer()->getData()->getpos()-I_M.current_cam->getpos());
                I_M.current_cam->setEulerAngle(Helper::quatToEuler(LookAt(I_M.current_cam->get_front(),I_M.current_cam->get_up())));
            }
        }
        else if(ev.get_typeEvent()==typeEvent::TP_Scene_Forward || ev.get_typeEvent()==typeEvent::TP_Scene_Backward ){
            std::cout << &ev<<std::endl;
            changeSceneAndTP(node,ev);
            if(scene_i >= s.size() || scene_i==-1){
                scene_i=0;
            }
            initScene();
            s[scene_i]->get_node_list()[0]->addChild(node);
            //std::cout << s[scene_i]->get_node_list().size()<<std::endl;
            s[scene_i]->get_node_list().push_back(node);
            //std::cout << s[scene_i]->get_node_list().size()<<std::endl;
            s[scene_i]->setNodePlayer(node);
            I_M.current_cam = static_cast<Camera*>(s[scene_i]->get_camera_list()[0]);
            I_M.view = 0;
        }
        else if( ev.get_typeEvent()==typeEvent::Pickable ){//pour le moment Pickable == victory
            gameState = 3;
        }
   }

   void hasEventHappened(Node* n){
        for(GameObject* eventGO : s[scene_i]->get_event_list()){
            if(n==s[scene_i]->getNodePlayer() && n->getData()->checkCollision(*eventGO)){ //eventGO->getEvent() != typeEvent::NO_Event && 
                event(n,eventGO->getEvent() );
            }
        }    
   }
   glm::vec3 ObjectInChampDeVision(GameObject * npc) // renvoie le pts le plus proche
   {
       Scene * scene = s[scene_i];
       float min = FLT_MAX;
       glm::vec3 ptsmin;
       for (GameObject* go :  scene->get_obstacle_list())
       {
           glm::vec3 point;
           
           
           
           if (go->in_champ_de_vision(npc , point))
           {
               if (glm::length(npc->getpos() - point) < min ) ptsmin = point;
           }
       }
       
       
       return ptsmin;
   }


   bool DetecterParNPC(GameObject * Player , float deltatime){
    for (GameObject * go : s[scene_i]->get_npc_list())
    {
         glm::vec3 point_detection_player;
         if(Player->in_champ_de_vision(go , point_detection_player)){
            bool b = true;
            glm::vec3 pts_min = ObjectInChampDeVision(go);
           
            if (glm::length(pts_min - go->getpos()) < glm::length(point_detection_player - go->getpos())) 
            {
                
               glm::vec3 minPos = go->getMinBB();
               glm::vec3 maxPos = go->getMaxBB();
               
               //tri 1
               glm::vec3 tri1A(minPos.x, minPos.y, minPos.z);
               glm::vec3 tri1B(maxPos.x, maxPos.y, maxPos.z);
               glm::vec3 tri1C(minPos.x, maxPos.y, minPos.z);
               //tri 2 
               glm::vec3 tri2A(minPos.x, minPos.y, minPos.z);
               glm::vec3 tri2B(maxPos.x, maxPos.y, maxPos.z);
               glm::vec3 tri2C(maxPos.x, minPos.y, maxPos.z);
               
               //tri 3
               glm::vec3 tri3A(maxPos.x, minPos.y, minPos.z);
               glm::vec3 tri3B(minPos.x, minPos.y, maxPos.z);
               glm::vec3 tri3C(maxPos.x, maxPos.y, minPos.z);
               
               //tri 4
               glm::vec3 tri4A(maxPos.x, minPos.y, minPos.z);
               glm::vec3 tri4B(minPos.x, maxPos.y, maxPos.z);
               glm::vec3 tri4C(maxPos.x, maxPos.y, minPos.z);
               
               
               glm::vec3 plan1 = Helper::intersectionDroitePlan(go->getpos() , point_detection_player , tri1A ,tri1B,tri1C);
               glm::vec3 plan2 = Helper::intersectionDroitePlan(go->getpos() , point_detection_player , tri3A ,tri3B,tri3C);
               b = Helper::computeBarycentre(plan1 , tri1A ,tri1B,tri1C) or
               Helper::computeBarycentre(plan1 , tri2A ,tri2B,tri2C) or
               Helper::computeBarycentre(plan2 , tri3A ,tri3B,tri3C) or
               Helper::computeBarycentre(plan2 , tri4A ,tri4B,tri4C);
               b = !b;

                //ajout d'un event npc pour qu'il aill a la position du joueur rapidement avant de retourner au checkpoint
            }
            //std::cout<< dist_detected[0]<<std::endl;
            if (b){

                go->set_speed(0.07f);
                go->getEvent().set_typeEvent(typeEvent::NPC_following_player);
                glm::vec3 posAI = go->getpos();
                glm::vec3 posPlayer = Player->getpos();
                glm::vec3 lastfront = glm::normalize(glm::vec3(posPlayer.x,posAI.y , posPlayer.z) - posAI);
                glm::quat rotation =   RotationBetweenVectors(go->get_front() , lastfront);
                glm::vec3 eulerangle = Helper::quatToEuler(rotation);
                go->setVitesse(go->get_front());
                go->rotateeulerYaw(eulerangle);
                go->set_front(lastfront);
                go->getgameObjectInfo().setMovedRecently(true);
                go->update_champ_de_vision();
                
            }
            if (go->getEvent().get_typeEvent() == NPC_following_player and !b)
            {
                go->getEvent().set_typeEvent(typeEvent::NPC_looking_for_player);
                go->getEvent().setposLastSeen(Player->getpos());
            }
            
//             if (go->getEvent().get_typeEvent() == NPC_return_to_Checkpoint and !b)
//             {
//                 go->getEvent().set_typeEvent(typeEvent::NPC_looking_for_player);
//                 go->getEvent().setposLastSeen(Player->getpos());
//             }
//             
           
            
            //std::cout<< glm::to_string(rotation)<<std::endl;
            //std::cout<< glm::to_string(go->getmodelmat())<<std::endl;
        }
        else if (go->getEvent().get_typeEvent() == typeEvent::NPC_looking_for_player){
            Event* ev = &go->getEvent();
            glm::vec3 posAI = go->getpos(); //pos actuel du npc
            glm::vec3 posCP = ev->getPos(); //pos de l'endroit ou il se dirige
            float distanceToCP = glm::length(posCP - posAI );
            glm::quat rotation;
            glm::vec3 lastfront;
            //std::cout<< distanceToCP<<std::endl;
            if(distanceToCP < 0.6f) //si proche alors on regarde le checkpoint suivant
            {
                lastfront = glm::normalize(glm::vec3(Player->getpos().x ,posAI.y, Player->getpos().z) - posAI); 
                
                go->getEvent().set_typeEvent(typeEvent::NPC_return_to_Checkpoint);

            }
            else{
                lastfront = glm::normalize(glm::vec3(posCP.x, posAI.y , posCP.z) -  posAI); 
            }

             rotation = RotationBetweenVectors(go->get_front() , lastfront);
             glm::vec3 eulerangle = Helper::quatToEuler(rotation);
//             
            go->set_front(lastfront);
            go->setVitesse(go->get_front());
            
        
            
            go->getgameObjectInfo().setMovedRecently(true);
            go->update_champ_de_vision();
            
        }
        else if (go->getEvent().get_typeEvent() == typeEvent::NPC_return_to_Checkpoint){
             Event* ev = &go->getEvent();
             std::vector<glm::vec3> list_cp = ev->get_all_checkpoint();
             glm::vec3 posAI = go->getpos();
             float distanceToCP = FLT_MAX; 
             unsigned int j = 0;
             for (unsigned int i = 0 ; i < list_cp.size() ; i++)
             {          
                 float len = glm::length(list_cp[i] - posAI);
                 if(distanceToCP > len){j = i;}
             }
             ev->setCP_i(j);
             //std::cout<< distanceToCP <<  " :: " << ev->getCP_i()<< std::endl;

             go->getEvent().set_typeEvent( typeEvent::NPC_Checkpoint);
             
             go->set_front(go->get_front());
             
        }
        
        else if (go->getEvent().get_typeEvent() == typeEvent::NPC_Checkpoint and (&go->getEvent())->get_all_checkpoint().size() > 0){
            Event* ev = &go->getEvent();
            glm::vec3 posAI = go->getpos(); //pos actuel du npc
            glm::vec3 posCP = ev->get_posCP(); //pos de l'endroit ou il se dirige
            float distanceToCP = glm::length(posCP - posAI);
            glm::quat rotation;
            glm::vec3 lastfront;
           if(distanceToCP < 0.5f) //si proche alors on regarde le checkpoint suivant
            {
                ev->nextCP();
                posCP = ev->get_posCP();
                lastfront = glm::normalize(glm::vec3(posCP.x, posAI.y , posCP.z) -  posAI); 
                go->setVitesse(go->get_front());

                
            }
            else{
                lastfront = glm::normalize(glm::vec3(posCP.x, posAI.y , posCP.z)-  posAI); 
            }
            
            rotation = RotationBetweenVectors(go->get_front() , lastfront);

            //std::cout<< glm::to_string(rotation) << std::endl;
            glm::vec3 eulerangle = Helper::quatToEuler(rotation);
            go->rotateeulerYaw(eulerangle);
            go->set_front(lastfront);
            go->setVitesse(go->get_front());
            
            go->getgameObjectInfo().setMovedRecently(true);
            go->update_champ_de_vision();
        }
        
       
        //else{go->reduceVitesse(deltatime * 0.05f);}

        if( go->checkCollision(*Player))
        {
            gameState=2;
            //std::cout<<"colision IA -- Joueur" << std::endl;

        }


    }
   }
   void set_light_on_off(GameObject* camera)
   {
        camera->update_champ_de_vision();
        Scene * scene = s[scene_i];
        //std::vector<float> dists = ObjectInChampDeVision(camera);
        //std::sort(dists.begin() , dists.end());

        
        //std::cout << dists[0] << std::endl;
        
        
        for (Node* light :  scene->get_node_light_list())
        {
            GameObject * cubelight = scene->get_data(light);
            glm::vec3 point_detect_cubelight;
           
            if (cubelight->getgameObjectInfo().getIsRendered() and cubelight->in_champ_de_vision(camera , point_detect_cubelight))
            {
            
                //std::cout<< glm::to_string(point_detect_cubelight)<<std::endl;
                GameObject * l = light->getDescendantsData()[1];
                 if (I_M.Input_light_on_off()) l->getgameObjectInfo().setIsLightOn(!l->getgameObjectInfo().getIsLightOn());
            }
            
        }
   }
   

    int getGameState(){return gameState;}
    void setGameState(unsigned int value){ gameState = value;}
    void pause(){
        if(gameState>0)gameState=-gameState;
    }
    void unpause(){
        if(gameState<0)gameState=-gameState;
    }
   unsigned int getScene_i(){return scene_i;}
    std::vector<Scene* >& getSceneList(){return s;}
   void addSceneToList(Scene* scene){s.push_back(scene);}
   Scene * getCurrentScene(){
    return s[scene_i];
   }
   Node getRoot(){return root;}

   InputManager& getInputManager(){return I_M;}

   void makeScene(){
        switch(scene_i) {
            case 0: 
                if(s[scene_i]->get_node_list().size()==0){makeScene_0(s[scene_i], SCR_WIDTH, SCR_HEIGHT);}
                break;
            case 1:
                if(s[scene_i]->get_node_list().size()==0){makeScene_1(s[scene_i], SCR_WIDTH, SCR_HEIGHT);}
                break;
            case 2:
            // if(s[scene_i]->get_node_list().size()==0){makeScene_2(s[scene_i], SCR_WIDTH, SCR_HEIGHT);}
                break;
            case 3:
            // if(s[scene_i]->get_node_list().size()==0){makeScene_3(s[scene_i], SCR_WIDTH, SCR_HEIGHT);}
                break;
            default:
                std::cerr << "Invalid scene number!" << std::endl;
        }
    }
    void initScene(){makeScene();}
     void resetGame( std::vector<GLuint> & programID_list){
        for (Scene * S : s){
            S->deletescene();
            delete(S);
    
        }
        s.clear();

        scene_i =0;
        Scene*  s1 = new Scene();
        s1->setprogIdList(programID_list);
        addSceneToList(s1);
        initScene();

        Scene * s2 = new Scene();
        s2->setprogIdList(programID_list);
        addSceneToList(s2);

        gameState=1;

     }

     void deleteAllScene(){
        for (Scene * S : s){
            S->deletescene();
    
        }
     }

};
