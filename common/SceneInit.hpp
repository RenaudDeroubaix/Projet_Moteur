#pragma once
#include "common/Scene.hpp"

void makeScene_0(Scene* s, const unsigned int SCR_WIDTH, const unsigned int SCR_HEIGHT){
    //s->deletescene();
    Node* sol = makeRoom(*s,50,25,10,glm::vec3(5.0f));   
   
    Node* cube = s->make_node_cube();
    s->setNodePlayer(cube);
    s->get_data(cube)->set_color(glm::vec3(0.1f , 0.3f, 1.f)); 
    s->scalenode(cube , glm::vec3(0.5f , 0.5f , 0.5f));

    float cubeScale=0.5;
    s->scalenode(cube , glm::vec3(cubeScale));
    s->translatenode(cube, glm::vec3(0.0 , cubeScale/2.0, -3.0));

    Node* npc = s->make_node_npc();
    ChampVision CV = ChampVision(s->get_data(npc)->getpos() , s->get_data(npc)->get_front() , 1.f * s->get_data(npc)->getscale()  , 3.f * s->get_data(npc)->getscale(), 1.f * s->get_data(npc)->getscale()); // rayon , hauteur , rayon au sol
    s->get_data(npc)->setChampVision(CV);

    s->get_data(npc)->set_color(glm::vec3(0.3f , 1.f, 0.5f)); 
    s->scalenode(npc , glm::vec3(0.5f , 0.5f , 0.5f));
    s->translatenode(npc, glm::vec3(1.0 , 0.25f, 1.0));

    s->get_data(cube)->getgameObjectInfo().setHasPhysics(true);
    s->get_data(cube)->calculateBoundingBox();
    s->get_data(cube)->setMasse(40.f);
    Node* SecurityCam1 = s->make_node_camera(true,SCR_WIDTH , SCR_HEIGHT);
    Node* SecurityCam2 = s->make_node_camera(false,SCR_WIDTH , SCR_HEIGHT);
    s->get_data(SecurityCam1)->set_pos(glm::vec3(-1.0 , 1 , -1 ));
    s->get_data(SecurityCam2)->set_pos(glm::vec3(0 , 0.9 ,0));
    sol->addChild(cube);
    sol->addChild(npc);
    sol->addChild(SecurityCam1);
    sol->addChild(SecurityCam2);

    Node* event=s->make_node_event(typeEvent::TP_Scene_Forward,glm::vec3(0.f,cubeScale/2.0,0.f));
    s->scalenode(event,glm::vec3(cubeScale/3.0));
    s->translatenode(event, glm::vec3(1.5,cubeScale/6.0, 3.0));
    sol->addChild(event);


    s->initscene();
    s->calculateBoundingBoxRecursive(sol);
    s->loadtexturesinscene();
}

void makeScene_1(Scene* s, const unsigned int SCR_WIDTH, const unsigned int SCR_HEIGHT){
    //s->deletescene();

    Node* sol = makeRoom(*s,50,50,10,glm::vec3(2.0f));  
   float cubeScale=0.5;
    
    Node* SecurityCam1 = s->make_node_camera(true,SCR_WIDTH , SCR_HEIGHT);
    Node* SecurityCam2 = s->make_node_camera(false,SCR_WIDTH , SCR_HEIGHT);
    s->get_data(SecurityCam1)->set_pos(glm::vec3(-1.0 , 1 , -1 ));
    s->get_data(SecurityCam2)->set_pos(glm::vec3(0 , 0.9 ,0));

    Node* event=s->make_node_event(typeEvent::TP_Scene_Backward,glm::vec3(4.f,cubeScale/2.0,4.f));
    s->scalenode(event,glm::vec3(cubeScale/3.0));
    s->translatenode(event, glm::vec3(4.0,cubeScale/6.0, 4.0));
    sol->addChild(event);

    sol->addChild(SecurityCam1);
    sol->addChild(SecurityCam2);
   
    s->initscene();
    s->calculateBoundingBoxRecursive(sol);
    s->loadtexturesinscene();
}


