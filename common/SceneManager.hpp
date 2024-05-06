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
public:
    SceneManager(){scene_i=0;}

    void changeSceneAndTP(Node* node, Event ev ){
        s[scene_i]->get_node_list()[0]->removeChild(node);
        s[scene_i]->removeNodeFromNodeList(node);
        ev.get_typeEvent()==typeEvent::TP_Scene_Forward ? scene_i++ : ev.get_typeEvent()==typeEvent::TP_Scene_Backward ? scene_i-- : scene_i ;
        node->getData()->set_pos(ev.getPos());
    }
   
   void event(Node* node, Event ev){
        if(ev.get_typeEvent()==typeEvent::TP_Scene_Forward || ev.get_typeEvent()==typeEvent::TP_Scene_Backward ){
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
        }
   }

   void hasEventHappened(Node* n){
        for(GameObject* eventGO : s[scene_i]->get_event_list()){
            if(n==s[scene_i]->getNodePlayer() && n->getData()->checkCollision(*eventGO)){
                event(n,eventGO->getEvent() );
            }
        }    
   }
   bool DetecterParNPC(GameObject * Player , float deltatime){
    for (GameObject * go : s[scene_i]->get_npc_list())
    {
        
        if (Player->in_champ_de_vision(go)){
            glm::vec3 posAI = go->getpos();
            glm::vec3 posPlayer = Player->getpos();
            glm::vec3 lastfront = glm::normalize(glm::vec3(posPlayer.x, posAI.y, posPlayer.z) - posAI);
            glm::quat rotation = RotationBetweenVectors(go->get_front() , lastfront);
            //glm::quat rotation = RotateTowards( rotationprev , rotationlast , glm::radians(10.f));
            glm::vec3 eulerangle = Helper::quatToEuler(rotation);
            std::cout<<glm::to_string(eulerangle) << std::endl;
            if ( fabs(eulerangle.y) > 0.02f ) go->setVitesse(go->get_front());
            go->rotateeulerYaw(eulerangle);
            
            go->set_front(lastfront);
            go->addVitesse(go->get_front() * deltatime * 0.05f );
            go->getgameObjectInfo().setMovedRecently(true);
            go->update_champ_de_vision();
            //std::cout<< glm::to_string(rotation)<<std::endl;
            //std::cout<< glm::to_string(go->getmodelmat())<<std::endl;
        }
        else{go->reduceVitesse(deltatime * 0.05f);}
       if ( go->checkCollision(*Player))
        {
            
            std::cout<<"colision IA -- Joueur" << std::endl;

        }


    }
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
};
