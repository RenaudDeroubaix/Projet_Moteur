#pragma once
#include "common/utils.hpp"


typedef enum {NO_Event,TP_Scene_Forward, TP_Scene_Backward, NPC_Checkpoint, NPC_return_to_Checkpoint ,NPC_following_player, Next_Camera, Previous_Camera, Pickable} typeEvent;

class Event {
public:

protected: 
    typeEvent type_evenement;
    glm::vec3 pos;
    bool is_repetable=true;
    std::vector<glm::vec3> checkpoint{};
    unsigned int CP_i=0;//indice du checkpoint su NPC_checkpoint sinon numero de camera dans la liste de la scene


public:
    Event(){type_evenement = typeEvent::NO_Event;}
    Event( typeEvent event, glm::vec3 p) :type_evenement(event), pos(p) {}
    Event( typeEvent event) :type_evenement(event) {}
    Event( typeEvent event, unsigned int num_cam) :type_evenement(event),CP_i(num_cam) {}
    glm::vec3 getPos(){return pos;}
    typeEvent get_typeEvent();
    void set_typeEvent(typeEvent type){type_evenement = type;}
    void nextCP(){
        if(type_evenement == typeEvent::NPC_Checkpoint){
            CP_i++;
            CP_i = CP_i % checkpoint.size();
        }
    }
    void setCP_i(unsigned int value){CP_i = value;}
    void setCheckpoint(std::vector<glm::vec3> cp){checkpoint = cp;}
    std::vector<glm::vec3> & get_all_checkpoint(){return checkpoint;}
    unsigned int getCP_i(){return CP_i;}
    //glm::vec3 get_posCP(){std::cout<< CP_i << " || " <<checkpoint.size() - 1 << std::endl; return checkpoint[CP_i];}

};
