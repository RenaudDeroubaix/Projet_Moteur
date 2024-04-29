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
public:
    SceneManager(){scene_i=0;}

    void changeSceneAndTP(GameObject* go, Event ev ){
        ev.get_typeEvent()==typeEvent::TP_Scene_Forward ? scene_i++ : ev.get_typeEvent()==typeEvent::TP_Scene_Backward ? scene_i-- : scene_i ;
        go->set_pos(ev.getPos());
    }
   
   void event(GameObject* go, Event ev){
        if(ev.get_typeEvent()==typeEvent::TP_Scene_Forward || ev.get_typeEvent()==typeEvent::TP_Scene_Backward ){
            changeSceneAndTP(go,ev);
        }
        if(scene_i >= s.size() || scene_i==-1){
            scene_i=0;
        }
   }

   void hasEventHappened(GameObject* go){
        for(GameObject* eventGO : s[scene_i]->get_event_list()){
            if(go->checkCollision(*eventGO)){
                event(go,eventGO->getEvent() );
            }
        }    
   }
   void addSceneToList(Scene* scene){s.push_back(scene);}
   Scene& getCurrentScene(){
    return *s[scene_i];
   }
   Node getRoot(){return root;}

};