#pragma once
#include "common/utils.hpp"
#include "common/GameObject.hpp"

typedef enum {TP_Scene_Forward, TP_Scene_Backward} typeEvent;

class Event {
public:

protected: 
    typeEvent type_evenement;
    glm::vec3 pos;
    bool is_repetable=true;
public:
    Event(){}
    Event( typeEvent event, glm::vec3 p) :type_evenement(event), pos(p) {}

    void changeSceneAndTP(GameObject& go,unsigned int& scene_i );
    typeEvent get_typeEvent();

};