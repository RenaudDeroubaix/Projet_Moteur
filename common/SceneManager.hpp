#pragma once
#include "common/utils.hpp"
#include "common/GameObject.hpp"
#include "common/Scene.hpp"
#include "common/Event.hpp"



class SceneManager {
public:

protected: 
   unsigned int scene_i;
   std::vector<Scene* > listScenes;
public:
    SceneManager(){scene_i=0;}
   
   void event(GameObject& go, Event ev){
        if(ev.get_typeEvent()==typeEvent::TP_Scene_Forward || ev.get_typeEvent()==typeEvent::TP_Scene_Backward ){
            ev.changeSceneAndTP(go,scene_i);
        }
        if(scene_i >= listScenes.size() || scene_i==-1){
            scene_i=0;
        }
   }
   void addSceneToList(Scene* s){listScenes.push_back(s);}
   Scene& getCurrentScene(){
    return *listScenes[scene_i];
   }

};