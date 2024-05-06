#pragma once
#include "common/utils.hpp"


typedef enum {TP_Scene_Forward, TP_Scene_Backward,NPC_Checkpoint} typeEvent;

class Event {
public:

protected: 
    typeEvent type_evenement;
    glm::vec3 pos;
    bool is_repetable=true;
    std::vector<glm::vec3> checkpoint;
    unsigned int CP_i=0;

public:
    Event(){}
    Event( typeEvent event, glm::vec3 p) :type_evenement(event), pos(p) {}
    Event( typeEvent event) :type_evenement(event) {}
    glm::vec3 getPos(){return pos;}
    typeEvent get_typeEvent();
    void nextCP(){
        CP_i++;
        CP_i = CP_i % checkpoint.size();
    }
    void setCheckpoint(std::vector<glm::vec3> cp){checkpoint = cp;}
    unsigned int getCP_i(){return CP_i;}
    glm::vec3 get_posCP(){return checkpoint[CP_i];}

};