#include "Event.hpp"

void Event::changeSceneAndTP(GameObject& go,unsigned int& scene_i ){
        type_evenement==typeEvent::TP_Scene_Forward ? scene_i++ : type_evenement==typeEvent::TP_Scene_Backward ? scene_i-- : scene_i ;
        go.set_pos(pos);
    }

typeEvent Event::get_typeEvent(){
    return type_evenement;
}