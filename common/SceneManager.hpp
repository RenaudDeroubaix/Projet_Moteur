#pragma once
#include "common/utils.hpp"
#include "common/GameObject.hpp"
#include "common/Scene.hpp"
#include "common/Event.hpp"



class SceneManager {
public:

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
            s[scene_i]->get_node_list()[0]->addChild(node);
             std::cout << s[scene_i]->get_node_list().size()<<std::endl;
            s[scene_i]->get_node_list().push_back(node);
            std::cout << s[scene_i]->get_node_list().size()<<std::endl;
            s[scene_i]->setNodePlayer(node);
            I_M.current_cam = static_cast<Camera*>(s[scene_i]->get_camera_list()[0]);
        }
   }

   void hasEventHappened(Node* n){
        for(GameObject* eventGO : s[scene_i]->get_event_list()){
            if(n->getData()->checkCollision(*eventGO)){
                event(n,eventGO->getEvent() );
            }
        }    
   }
   void addSceneToList(Scene* scene){s.push_back(scene);}
   Scene& getCurrentScene(){
    return *s[scene_i];
   }
   Node getRoot(){return root;}

   InputManager& getInputManager(){return I_M;}

};