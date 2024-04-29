#pragma once
#include "common/utils.hpp"


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
    glm::vec3 getPos(){return pos;}
    typeEvent get_typeEvent();

};