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
   std::vector<Scene* > s;
   InputManager I_M;
   int gameState=1; // negative = pause // 1=jeu // 2=gameOver // 3=Victory
public:
    SceneManager(){scene_i=0;}

    void changeSceneAndTP(Node* node, Event ev ){
        s[scene_i]->get_node_list()[0]->removeChild(node);
        s[scene_i]->removeNodeFromNodeList(node);
        ev.get_typeEvent()==typeEvent::TP_Scene_Forward ? scene_i++ : ev.get_typeEvent()==typeEvent::TP_Scene_Backward ? scene_i-- : scene_i ;
        node->getData()->set_pos(ev.getPos());
        std::cout << scene_i <<std::endl;
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
           
           if (go->in_champ_de_vision( npc , point))
           {
               if ( glm::length(npc->getpos() - point) < min ) ptsmin = point;
           }
       }
       
       
       return ptsmin;
   }
   glm::vec3 ObjectInChampDeVision(GameObject * npc) // renvoie le pts le plus proche
   {
       Scene * scene = s[scene_i];
       float min = FLT_MAX;
       glm::vec3 ptsmin;
       for (GameObject* go :  scene->get_obstacle_list())
       {
           glm::vec3 point;
           
           if (go->in_champ_de_vision( npc , point))
           {
               if ( glm::length(npc->getpos() - point) < min ) ptsmin = point;
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
           
            if (glm::length(pts_min - go->getpos()) < glm::length(point_detection_player - go->getpos())  ) b = false;
            //std::cout<< dist_detected[0]<<std::endl;
            if (b){
                
                go->getEvent().set_typeEvent(typeEvent::NPC_following_player);
                glm::vec3 posAI = go->getpos();
                glm::vec3 posPlayer = Player->getpos();
                glm::vec3 lastfront = glm::normalize(glm::vec3(posPlayer.x, posAI.y, posPlayer.z) - posAI);
                glm::quat rotation =   RotationBetweenVectors(go->get_front() , lastfront);
                glm::vec3 eulerangle = Helper::quatToEuler(rotation);
                if ( fabs(eulerangle.y) > 0.05) go->setVitesse(go->get_front() * deltatime * 4.f );
                else go->addVitesse(go->get_front() * deltatime * 0.05f );
                go->rotateeulerYaw(eulerangle);
                go->set_front(lastfront);
                go->getgameObjectInfo().setMovedRecently(true);
                go->update_champ_de_vision();
                
            }
            else {
                go->getEvent().set_typeEvent(typeEvent::NPC_return_to_Checkpoint);
            }
            //std::cout<< glm::to_string(rotation)<<std::endl;
            //std::cout<< glm::to_string(go->getmodelmat())<<std::endl;
        }
        if (go->getEvent().get_typeEvent() == typeEvent::NPC_return_to_Checkpoint){
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
            
        }
        
        if (go->getEvent().get_typeEvent() == typeEvent::NPC_Checkpoint and (&go->getEvent())->get_all_checkpoint().size() > 0){
            Event* ev = &go->getEvent();
            glm::vec3 posAI = go->getpos(); //pos actuel du npc
            glm::vec3 posCP = ev->get_posCP(); //pos de l'endroit ou il se dirige
            float distanceToCP = glm::length(posCP - posAI);
            //if(distanceToCP < 1) {go->setVitesse(glm::vec3(0.03f)); }
            if(distanceToCP < 0.2) //si proche alors on regarde le checkpoint suivant
            {
                ev->nextCP();
                posCP = ev->get_posCP();
                go->setVitesse(glm::vec3(0.f));
                
                
            } 
            
                   
            glm::vec3 lastfront = glm::normalize(glm::vec3(posCP.x, posAI.y, posCP.z) - posAI); 
            glm::quat rotation = RotateTowards(LookAt(go->get_front() , go->get_up())  , RotationBetweenVectors(go->get_front() , lastfront) , glm::radians(360.f));
            //std::cout<< glm::to_string(rotation) << std::endl;
            glm::vec3 eulerangle = Helper::quatToEuler(rotation);
            go->rotateeulerYaw(eulerangle);
            go->set_front(lastfront);
            go->addVitesse(go->get_front() * deltatime * 0.05f);
            
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
   Scene& getCurrentScene(){
    return *s[scene_i];
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
    void resetCurrentScene(){s[scene_i]->set_reset_s(false);scene_i=0;makeScene_0(s[scene_i], SCR_WIDTH, SCR_HEIGHT);;gameState=1;}

};
