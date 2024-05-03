#pragma once
#include "common/Scene.hpp"

void makeScene_0(Scene* s, const unsigned int SCR_WIDTH, const unsigned int SCR_HEIGHT){
    //s->deletescene();

    //////////////ROOM 
    Node* sol = makeRoom(*s,36,60,6,glm::vec3(1.0f),0);   
   
   //////////////PLAYER
    Node* player = s->make_node_cube(0);
    s->setNodePlayer(player);
    s->get_data(player)->set_color(glm::vec3(0.1f , 0.1f, 1.f)); 
    float playerScale=0.5;
    s->scalenode(player , glm::vec3(playerScale));
    s->translatenode(player, glm::vec3(0.0 , playerScale/2.0, -29.4));
    s->get_data(player)->getgameObjectInfo().setHasPhysics(true);
    s->get_data(player)->calculateBoundingBox();
    s->get_data(player)->setMasse(40.f);
    sol->addChild(player);


    ///////////////////// premier NPC couloir haut
    Node* npc = s->make_node_npc(0);
    float npcScale=1.0;
    float npcHauteur=1.0;
    s->get_data(npc)->set_front(glm::vec3(.0,0.0,-1.0));
    s->scalenode(npc , glm::vec3(npcScale , npcScale*npcHauteur , npcScale));
    s->translatenode(npc, glm::vec3(13.0 , (npcScale*npcHauteur)/2.f, 1.0));
    ChampVision CVnpc2 = ChampVision(s->get_data(npc)->getpos() , s->get_data(npc)->get_front() , 1.f * s->get_data(npc)->getscale()  , 60.f * s->get_data(npc)->getscale(), 1.f * s->get_data(npc)->getscale()); // rayon , hauteur , rayon au sol
    s->get_data(npc)->setChampVision(CVnpc2);
    s->get_data(npc)->set_color(glm::vec3(0.8f , 0.1f, 0.1f)); 
    sol->addChild(npc);

    ///////////////////// NPC bloque porte
    Node* npc2 = s->make_node_npc(0);
    s->get_data(npc2)->set_front(glm::vec3(-1,0.0,0.0));
    s->scalenode(npc2 , glm::vec3(npcScale , npcScale*npcHauteur , npcScale));
    s->translatenode(npc2, glm::vec3(7.5 , (npcScale*npcHauteur)/2.f, 16.0));
    ChampVision CV = ChampVision(s->get_data(npc2)->getpos() , s->get_data(npc2)->get_front() , 1.f * s->get_data(npc2)->getscale()  , 60.f * s->get_data(npc2)->getscale(), 1.f * s->get_data(npc2)->getscale()); // rayon , hauteur , rayon au sol
    s->get_data(npc2)->setChampVision(CV);
    s->get_data(npc2)->set_color(glm::vec3(0.8f , 0.1f, 0.1f)); 
    sol->addChild(npc2);

    /////////////CAM1 position haut gauche
    Node* SecurityCam1 = s->make_node_camera(false,SCR_WIDTH , SCR_HEIGHT,0);
    s->get_data(SecurityCam1)->set_pos(glm::vec3(17.4 , 4.8 , -29.4 ));
    s->get_data(SecurityCam1)->set_front(glm::normalize(s->get_data(player)->getpos() - s->get_data(SecurityCam1)->getpos()));
    Helper::setViewtowardFront(s->get_data(SecurityCam1));
    Camera * c1 = static_cast<Camera*>( s->get_data(SecurityCam1));
    c1->setFOV(45.0);
    sol->addChild(SecurityCam1);

    /////////////CAM2 position centre bas
    Node* SecurityCam2 = s->make_node_camera(false,SCR_WIDTH , SCR_HEIGHT,0);
    s->get_data(SecurityCam2)->set_pos(glm::vec3(-17.4 , 4.8 ,0.0));
    s->get_data(SecurityCam2)->set_front(glm::normalize(glm::vec3(0.f) - s->get_data(SecurityCam2)->getpos()));
    Helper::setViewtowardFront(s->get_data(SecurityCam2));
    Camera * c2 = static_cast<Camera*>( s->get_data(SecurityCam2));
    c2->setFOV(45.0);
    sol->addChild(SecurityCam2);
    
    /////////////CAM3 position haut droit sur une cloiture
    Node* SecurityCam3 = s->make_node_camera(false,SCR_WIDTH , SCR_HEIGHT,0);
    s->get_data(SecurityCam3)->set_pos(glm::vec3(8.4 , 3.8 ,23.4));
    s->get_data(SecurityCam3)->set_front(glm::normalize(s->get_data(player)->getpos() - s->get_data(SecurityCam3)->getpos()));
    Helper::setViewtowardFront(s->get_data(SecurityCam3));
    Camera * c3 = static_cast<Camera*>( s->get_data(SecurityCam3));
    c3->setFOV(45.0);
    sol->addChild(SecurityCam3);

    /////////////Obstacle boite milieu 
    Node* obstacle1 = s->make_node_cube(0);
    s->get_data(obstacle1)->set_color(glm::vec3(0.8f , 0.8f, 0.1f)); 
    float obstacle1Scale=4.0;
    s->scalenode(obstacle1 ,  glm::vec3(obstacle1Scale/2.0 , obstacle1Scale , obstacle1Scale));
    s->translatenode(obstacle1, glm::vec3(-6.0 , obstacle1Scale/2.0, 16.0));
    sol->addChild(obstacle1);

    Node* obstacle2 = s->make_node_cube(0);
    s->get_data(obstacle2)->set_color(glm::vec3(0.8f , 0.8f, 0.1f)); 

    ////////////Cloison
    Node* cloison1= s->make_node_mur(7.5, 6.0, 0);
    s->rotatenode(cloison1, 90.f, glm::vec3(1.0, 0.0, 0.0));
    s->translatenode(cloison1,glm::vec3(-14.5,2.5  ,-18.0));
    sol->addChild(cloison1);

    Node* cloison2= s->make_node_mur(16.0, 6.0, 0);
    s->rotatenode(cloison2, 90.f, glm::vec3(1.0, 0.0, 0.0));
    s->translatenode(cloison2,glm::vec3(1.0, 2.5   ,-18.0));
    sol->addChild(cloison2);

    Node* cloison3= s->make_node_mur(8.0, 2.5, 0);
    s->rotatenode(cloison3, 90.f, glm::vec3(1.0, 0.0, 0.0));
    s->translatenode(cloison3,glm::vec3(-8.0, 4.5  ,-18.0));
    sol->addChild(cloison3);

    Node* cloison4= s->make_node_mur(11, 6.0, 0);
    s->rotatenode(cloison4, 90.f, glm::vec3(1.0, 0.0, 0.0));
    s->translatenode(cloison4,glm::vec3(13.5, 2.5   ,10.0));
    sol->addChild(cloison4);

    Node* cloison5= s->make_node_mur(6.0, 14.0, 0);
    s->rotatenode(cloison5, 90.f, glm::vec3(0.0, 0.0, 1.0));
    s->translatenode(cloison5,glm::vec3(8.5, 2.5   ,11.0));
    sol->addChild(cloison5);

    Node* cloison6= s->make_node_mur(6.0, 18.0, 0);
    s->rotatenode(cloison6, 90.f, glm::vec3(0.0, 0.0, 1.0));
    s->translatenode(cloison6,glm::vec3(8.5, 2.5   ,-9.5));
    sol->addChild(cloison6);

    Node* cloison7= s->make_node_mur(2.5, 18.0, 0);
    s->rotatenode(cloison7, 90.f, glm::vec3(0.0, 0.0, 1.0));
    s->translatenode(cloison7,glm::vec3(8.5, 4.5 ,0.5));
    sol->addChild(cloison7);

    Node* cloison8= s->make_node_mur(6.0, 8.0, 0);
    s->rotatenode(cloison8, 90.f, glm::vec3(0.0, 0.0, 1.0));
    s->translatenode(cloison8,glm::vec3(8.5, 2.5   ,27));
    sol->addChild(cloison8);

    Node* cloison9= s->make_node_mur(2.5, 8.0, 0);
    s->rotatenode(cloison9, 90.f, glm::vec3(0.0, 0.0, 1.0));
    s->translatenode(cloison9,glm::vec3(8.5, 4.5 ,20.0));
    sol->addChild(cloison9);

    s->get_data(cloison1)->set_color(glm::vec3(0.8f , 0.8f, 0.8f)); 
    s->get_data(cloison2)->set_color(glm::vec3(0.8f , 0.8f, 0.8f)); 
    s->get_data(cloison3)->set_color(glm::vec3(0.8f , 0.8f, 0.8f)); 
    s->get_data(cloison4)->set_color(glm::vec3(0.8f , 0.8f, 0.8f)); 
    s->get_data(cloison5)->set_color(glm::vec3(0.8f , 0.8f, 0.8f)); 
    s->get_data(cloison6)->set_color(glm::vec3(0.8f , 0.8f, 0.8f)); 
    s->get_data(cloison7)->set_color(glm::vec3(0.8f , 0.8f, 0.8f)); 
    s->get_data(cloison8)->set_color(glm::vec3(0.8f , 0.8f, 0.8f)); 
    s->get_data(cloison9)->set_color(glm::vec3(0.8f , 0.8f, 0.8f)); 

    float eventScale = 3.0;
    Node* eventPorte=s->make_node_event(typeEvent::TP_Scene_Forward,glm::vec3(0.f,playerScale/2.0,0.f), 0);
    s->scalenode(eventPorte,glm::vec3(0.2,eventScale, eventScale));
    s->translatenode(eventPorte, glm::vec3(17.4, eventScale/2.0 ,20.0));
    sol->addChild(eventPorte);

    s->initscene();
    s->calculateBoundingBoxRecursive(sol);
}

void makeScene_1(Scene* s, const unsigned int SCR_WIDTH, const unsigned int SCR_HEIGHT){
    //s->deletescene();

    Node* sol = makeRoom(*s,50,50,10,glm::vec3(2.0f), 0);  
    float cubeScale=0.5;
    
    Node* SecurityCam1 = s->make_node_camera(true,SCR_WIDTH , SCR_HEIGHT, 0);
    Node* SecurityCam2 = s->make_node_camera(false,SCR_WIDTH , SCR_HEIGHT, 0);
    s->get_data(SecurityCam1)->set_pos(glm::vec3(-1.0 , 1 , -1 ));
    s->get_data(SecurityCam2)->set_pos(glm::vec3(0 , 0.9 ,0));

    Node* event=s->make_node_event(typeEvent::TP_Scene_Backward,glm::vec3(4.f,cubeScale/2.0,4.f), 0);
    s->scalenode(event,glm::vec3(cubeScale/3.0));
    s->translatenode(event, glm::vec3(4.0,cubeScale/6.0, 4.0));
    sol->addChild(event);

    sol->addChild(SecurityCam1);
    sol->addChild(SecurityCam2);
   
    s->initscene();
    s->calculateBoundingBoxRecursive(sol);
}

void makeScene_2(Scene* s, const unsigned int SCR_WIDTH, const unsigned int SCR_HEIGHT){
    //s->deletescene();
    Node* sol = makeRoom(*s,50,25,10,glm::vec3(5.0f), 0);   
   
    Node* cube = s->make_node_cube(0);
    s->setNodePlayer(cube);
    s->get_data(cube)->set_color(glm::vec3(0.1f , 0.3f, 1.f)); 
    s->scalenode(cube , glm::vec3(0.5f , 0.5f , 0.5f));

    float cubeScale=0.5;
    s->scalenode(cube , glm::vec3(cubeScale));
    s->translatenode(cube, glm::vec3(0.0 , cubeScale/2.0, -3.0));

    Node* npc = s->make_node_npc(0);
    ChampVision CV = ChampVision(s->get_data(npc)->getpos() , s->get_data(npc)->get_front() , 1.f * s->get_data(npc)->getscale()  , 10.f * s->get_data(npc)->getscale(), 1.f * s->get_data(npc)->getscale()); // rayon , hauteur , rayon au sol
    s->get_data(npc)->setChampVision(CV);

    s->get_data(npc)->set_color(glm::vec3(0.3f , 1.f, 0.5f)); 
    float npcScale=1.0;
    //s->scalenode(npc , glm::vec3(npcScale , npcScale , npcScale));
    s->translatenode(npc, glm::vec3(1.0 , npcScale/2.f, 1.0));

    s->get_data(cube)->getgameObjectInfo().setHasPhysics(true);
    s->get_data(cube)->calculateBoundingBox();
    s->get_data(cube)->setMasse(40.f);
    Node* SecurityCam1 = s->make_node_camera(true,SCR_WIDTH , SCR_HEIGHT, 0);
    Node* SecurityCam2 = s->make_node_camera(false,SCR_WIDTH , SCR_HEIGHT, 0);
    s->get_data(SecurityCam1)->set_pos(glm::vec3(-2.5 , 1.3 , -2.5 ));
    s->get_data(SecurityCam2)->set_pos(glm::vec3(0 , 0.9 ,0));
    sol->addChild(cube);
    sol->addChild(npc);
    sol->addChild(SecurityCam1);
    sol->addChild(SecurityCam2);

    Node* event=s->make_node_event(typeEvent::TP_Scene_Forward,glm::vec3(0.f,cubeScale/2.0,0.f), 0);
    s->scalenode(event,glm::vec3(cubeScale/3.0));
    s->translatenode(event, glm::vec3(1.5,cubeScale/6.0, 3.0));
    sol->addChild(event);

    
    s->initscene();
    s->calculateBoundingBoxRecursive(sol);
}
