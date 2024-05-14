#pragma once
#include "common/Scene.hpp"

void makeScene_1(Scene* s, const unsigned int SCR_WIDTH, const unsigned int SCR_HEIGHT){
    //s->resetscene();

    Node* sol = makeRoom(*s,36,53,7,glm::vec3(1.0f),0); 



     /////////////LIGHT 
    Node* lumiere1 = s->make_node_light(true,false, 0);
    sol->addChild(lumiere1);

    s->setposnode(lumiere1 , glm::vec3(16.f , 2.f , -0.f));
    s->setcolornode(lumiere1 , glm::vec3(1.f , 0.4f , 0.4f)); 
/*
    Node* lumiere1cube = s->make_node_cube(0);
    sol->addChild(lumiere1cube);
    s->get_data(lumiere1cube)->set_pos(glm::vec3(16.f , 2.f , 0.f));
    s->get_data(lumiere1cube)->set_color(glm::vec3(1.f , 0.4f , 0.5f));
*/
    
    Node* lumiere2 = s->make_node_light(true,false, 0);
    sol->addChild(lumiere2);
    s->setposnode(lumiere2 , glm::vec3(-10.5f , 2.f , -14.f ));
    s->setcolornode(lumiere2 ,glm::vec3(0.3f , 1.f , 0.3f));  

    Node* lumiere4 = s->make_node_light(true,false, 0);
    sol->addChild(lumiere4);
    s->setposnode(lumiere4 , glm::vec3(-16.f , 4.5f , 20.f ));
    s->setcolornode(lumiere4 ,glm::vec3(1.f , 1.f , 1.f)); 

     Node* lumiere5 = s->make_node_light(true,false, 0);
    sol->addChild(lumiere5);
    s->setposnode(lumiere5 , glm::vec3(-2.f , 4.5f , 4.f ));
    s->setcolornode(lumiere5 ,glm::vec3(1.f , 1.f , 1.f)); 

    Node* lumiere6 = s->make_node_light(true,false, 0);
    sol->addChild(lumiere6);
    s->setposnode(lumiere6 , glm::vec3(-2.f , 4.5f , -2.f ));
    s->setcolornode(lumiere6 ,glm::vec3(1.f , 1.f , 1.f)); 

    Node* lumiere7 = s->make_node_light(true,false, 0);
    sol->addChild(lumiere7);
    s->setposnode(lumiere7 , glm::vec3(16.f , 4.5f , -23.f ));
    s->setcolornode(lumiere7 ,glm::vec3(1.f , 1.f , 1.f)); 

    Node* lumiere8 = s->make_node_light(true,false, 0);
    sol->addChild(lumiere8);
    s->setposnode(lumiere8 , glm::vec3(12.f , 4.5f , 24.f ));
    s->setcolornode(lumiere8 ,glm::vec3(1.f , 1.f , 1.f)); 
/*
       Node* lumiere2cube = s->make_node_cube(0);
    sol->addChild(lumiere2cube);
    s->get_data(lumiere2cube)->set_pos(glm::vec3(-16.f , 2.f , 0.f));
    s->get_data(lumiere2cube)->set_color(glm::vec3(0.3f , 1.0f , 0.3f));
    */

    Node* lumiere3 = s->make_node_light(false,true , 0);
    sol->addChild(lumiere3);
    s->get_data(lumiere3)->set_color(glm::vec3(1.f)); 
    s->get_data(lumiere3)->set_front(glm::normalize(glm::vec3(0.5f ,-1.f , 0.f )));

     //////////////PLAYER
     float playerScale=0.40;
     /*
    //Node* player = s->make_node_mesh("../src/maillages/Cubone/pkm.off",0);
    Node* player = s->make_node_cube(0);
    s->setNodePlayer(player);
    s->get_data(player)->set_color(glm::vec3(0.1f , 0.1f, 1.f)); 
    s->scalenode(player , glm::vec3(playerScale));
    s->translatenode(player, glm::vec3(17.0 , playerScale/2.0, -23.0));
    s->get_data(player)->getgameObjectInfo().setHasPhysics(true);
   // s->get_data(player)->calculateBoundingBox();
    s->get_data(player)->setMasse(40.f);
    sol->addChild(player); 
    */

     /////////////CAM1 
    Node* SecurityCam1 = s->make_node_camera(true,SCR_WIDTH , SCR_HEIGHT,0);
    s->get_data(SecurityCam1)->set_pos(glm::vec3(-17.25, 5.5 , -25.25));
    s->get_data(SecurityCam1)->set_front(glm::normalize(glm::vec3(17.0 , playerScale/2.0, -23.0) - s->get_data(SecurityCam1)->getpos()));
    Helper::setViewtowardFront(s->get_data(SecurityCam1));
    Camera * c1 = static_cast<Camera*>( s->get_data(SecurityCam1));
    c1->setFOV(45.0);
    c1->setlimit_yaw_min(0.f);
    c1->setlimit_yaw_max(90.f);
    c1->setlimit_pitch_min(0.f);
    c1->setlimit_pitch_max(90.f);
    sol->addChild(SecurityCam1);

    /////////////CAM2
    Node* SecurityCam2 = s->make_node_camera(true,SCR_WIDTH , SCR_HEIGHT,0);
    s->get_data(SecurityCam2)->set_pos(glm::vec3(-17.25, 5.5 ,14.0));
    //s->get_data(SecurityCam2)->set_front(glm::normalize(s->get_data(player)->getpos() - s->get_data(SecurityCam2)->getpos()));
    //Helper::setViewtowardFront(s->get_data(SecurityCam2));
    Camera * c2 = static_cast<Camera*>( s->get_data(SecurityCam2));
    c2->setFOV(45.0);
    c2->setlimit_yaw_min(-180.f);
    c2->setlimit_yaw_max(180.f);
    c2->setlimit_pitch_min(0.f);
    c2->setlimit_pitch_max(90.f);
    sol->addChild(SecurityCam2);

        /////////////CAM3
    Node* SecurityCam3 = s->make_node_camera(true,SCR_WIDTH , SCR_HEIGHT,0);
    s->get_data(SecurityCam3)->set_pos(glm::vec3(17.25, 5.5 , 20.0));
    //s->get_data(SecurityCam3)->set_front(glm::normalize(s->get_data(player)->getpos() - s->get_data(SecurityCam3)->getpos()));
    //Helper::setViewtowardFront(s->get_data(SecurityCam3));
    Camera * c3 = static_cast<Camera*>( s->get_data(SecurityCam3));
    c3->setFOV(45.0);
    c3->setlimit_yaw_min(-180.f);
    c3->setlimit_yaw_max(180.f);
    c3->setlimit_pitch_min(0.f);
    c3->setlimit_pitch_max(90.f);
    sol->addChild(SecurityCam3);

    /////////////CAM4
    Node* SecurityCam4 = s->make_node_camera(true,SCR_WIDTH , SCR_HEIGHT,0);
    s->get_data(SecurityCam4)->set_pos(glm::vec3(0.75, 5.5 , 0.75));
    //s->get_data(SecurityCam4)->set_front(glm::normalize(s->get_data(player)->getpos() - s->get_data(SecurityCam4)->getpos()));
    //Helper::setViewtowardFront(s->get_data(SecurityCam4));
    Camera * c4 = static_cast<Camera*>( s->get_data(SecurityCam4));
    c4->setFOV(45.0);
    c4->setlimit_yaw_min(-180.f);
    c4->setlimit_yaw_max(180.f);
    c4->setlimit_pitch_min(0.f);
    c4->setlimit_pitch_max(90.f);
    sol->addChild(SecurityCam4);


    ///////////////mur interne roation sur x : longeur hauteur // rotation sur z : hauteur longeur
    Node* cloison1= s->make_node_mur(18, 7.0, 0);
    s->rotatenode(cloison1, 90.f, glm::vec3(1.0, 0.0, 0.0));
    s->translatenode(cloison1,glm::vec3(9.0,3.0 ,-20.0));
    s->get_data(cloison1)->set_color(glm::vec3(0.5f)); 
    sol->addChild(cloison1);

    Node* cloison2= s->make_node_mur(7.0, 35.0, 0);
    s->rotatenode(cloison2, 90.f, glm::vec3(0.0, 0.0, 1.0));
    s->translatenode(cloison2,glm::vec3(0.5, 3.0 ,-3.0));
    s->get_data(cloison2)->set_color(glm::vec3(0.5f)); 
    sol->addChild(cloison2);

    Node* cloison3= s->make_node_mur(8.0, 7.0, 0);
    s->rotatenode(cloison3, 90.f, glm::vec3(1.0, 0.0, 0.0));
    s->translatenode(cloison3,glm::vec3(-3.0,3.0 ,0.0));
    s->get_data(cloison3)->set_color(glm::vec3(0.5f)); 
    sol->addChild(cloison3);

     Node* cloison4= s->make_node_mur(10.0, 7.0, 0);
    s->rotatenode(cloison4, 90.f, glm::vec3(1.0, 0.0, 0.0));
    s->translatenode(cloison4,glm::vec3(-13.0,3.0 ,0.0));
    s->get_data(cloison4)->set_color(glm::vec3(0.5f)); 
    sol->addChild(cloison4);

    Node* cloison5= s->make_node_mur(3.0, 3.0, 0);
    s->rotatenode(cloison5, 90.f, glm::vec3(1.0, 0.0, 0.0));
    s->translatenode(cloison5,glm::vec3(-7.5, 5.0 ,0.0));
    s->get_data(cloison5)->set_color(glm::vec3(0.5f)); 
    sol->addChild(cloison5);

    Node* cloison6= s->make_node_mur(7.0,11.0, 0);
    s->rotatenode(cloison6, 90.f, glm::vec3(0.0, 0.0, 1.0));
    s->translatenode(cloison6,glm::vec3(0.5, 3.0 ,21.0));
    s->get_data(cloison6)->set_color(glm::vec3(0.5f)); 
    sol->addChild(cloison6);

    Node* cloison7= s->make_node_mur(3.0, 3.5, 0);
    s->rotatenode(cloison7, 90.f, glm::vec3(0.0, 0.0, 1.0));
    s->translatenode(cloison7,glm::vec3(0.5, 5.0 ,15.0));
    s->get_data(cloison7)->set_color(glm::vec3(0.5f)); 
    sol->addChild(cloison7);

    ///////trigger changement de cam
    Node* changeCam1_0= s->make_node_event(typeEvent::Previous_Camera,3.0,7.0, 1 ,0);
    s->rotatenode(changeCam1_0, 90.f, glm::vec3(1.0, 0.0, 0.0));
    s->translatenode(changeCam1_0,glm::vec3(-7.50, 3.0  ,-0.05));
    sol->addChild(changeCam1_0);

    Node* changeCam0_1= s->make_node_event(typeEvent::Next_Camera,3.0,7.0, 0 ,0);
    s->rotatenode(changeCam0_1, 90.f, glm::vec3(1.0, 0.0, 0.0));
    s->translatenode(changeCam0_1,glm::vec3(-7.5, 3.0 ,0.05));
    sol->addChild(changeCam0_1);

    Node* changeCam2_1= s->make_node_event(typeEvent::Previous_Camera,7.0,3.0, 2 ,0);
    s->rotatenode(changeCam2_1, 90.f, glm::vec3(0.0, 0.0, 1.0));
    s->translatenode(changeCam2_1,glm::vec3(0.495, 3.0  ,15.0));
    sol->addChild(changeCam2_1);

    Node* changeCam1_2= s->make_node_event(typeEvent::Next_Camera,7.0,3.0, 1 ,0);
    s->rotatenode(changeCam1_2, 90.f, glm::vec3(0.0, 0.0, 1.0));
    s->translatenode(changeCam1_2,glm::vec3(0.505, 3.0 ,15.0));
    sol->addChild(changeCam1_2);

    Node* changeCam3_2= s->make_node_event(typeEvent::Previous_Camera,6.0,7.0, 3 ,0);
    s->rotatenode(changeCam3_2, 90.f, glm::vec3(1.0, 0.0, 0.0));
    s->translatenode(changeCam3_2,glm::vec3(9.0, 3.0  ,10.05));
    sol->addChild(changeCam3_2);

    Node* changeCam2_3= s->make_node_event(typeEvent::Next_Camera,6.0,7.0,2 ,0);
    s->rotatenode(changeCam2_3, 90.f, glm::vec3(1.0, 0.0, 0.0));
    s->translatenode(changeCam2_3,glm::vec3(9.0, 3.0 ,9.95));
    sol->addChild(changeCam2_3);


    ////Cube obstacle
    Node* obstacle1 = s->make_node_cube(0);
    s->get_data(obstacle1)->set_color(glm::vec3(0.8f , 0.8f, 0.1f)); 
    s->scalenode(obstacle1 ,  glm::vec3(4.0, 1.5 , 10.0));
    s->translatenode(obstacle1, glm::vec3(-10.50 , 1.5/2.0, -13.0));
    sol->addChild(obstacle1);

    Node* obstacle2 = s->make_node_cube(0);
    s->get_data(obstacle2)->set_color(glm::vec3(0.8f , 0.8f, 0.1f)); 
    s->scalenode(obstacle2 ,  glm::vec3(2.50, 5.0 , 2.5));
    s->translatenode(obstacle2, glm::vec3(-15.5 , 5.0/2.0, 8.0));
    sol->addChild(obstacle2);

    Node* obstacle3 = s->make_node_cube(0);
    s->get_data(obstacle3)->set_color(glm::vec3(0.8f , 0.8f, 0.1f)); 
    s->scalenode(obstacle3 ,  glm::vec3(2.50, 5.0 , 2.50));
    s->translatenode(obstacle3, glm::vec3(-2.5 , 5.0/2.0, 8.0));
    sol->addChild(obstacle3);

    Node* obstacle4 = s->make_node_cube(0);
    s->get_data(obstacle4)->set_color(glm::vec3(0.8f , 0.8f, 0.1f)); 
    s->scalenode(obstacle4 ,  glm::vec3(6.0, 3.0 , 2.5));
    s->translatenode(obstacle4, glm::vec3(3.5 , 3.0/2.0, 11.0));
    sol->addChild(obstacle4);

    Node* obstacle5 = s->make_node_cube(0);
    s->get_data(obstacle5)->set_color(glm::vec3(0.8f , 0.8f, 0.1f)); 
    s->scalenode(obstacle5 ,  glm::vec3(6.0, 3, 2.5));
    s->translatenode(obstacle5, glm::vec3(14.5, 3/2.0, 9.0));
    sol->addChild(obstacle5);

    ////////enemy

    Node* npc = s->make_node_npc(0);
    float npcScale=1.50;
    float npcHauteur=1.0;
    
    s->get_data(npc)->set_front(glm::vec3(.0,0.0,-1.0));
    s->scalenode(npc , glm::vec3(npcScale , npcScale*npcHauteur , npcScale));
    s->translatenode(npc, glm::vec3(-5.0 , (npcScale*npcHauteur)/2.f  , -2.0));
    ChampVision CVnpc = ChampVision(s->get_data(npc)->getpos() , s->get_data(npc)->get_front() , 1.f * s->get_data(npc)->getscale()  , 60.f * s->get_data(npc)->getscale(), 1.f * s->get_data(npc)->getscale()); // rayon , hauteur , rayon au sol
    s->get_data(npc)->setChampVision(CVnpc);
    s->get_data(npc)->set_color(glm::vec3(0.8f , 0.1f, 0.1f));

    Event ev(typeEvent::NPC_Checkpoint);
    std::vector<glm::vec3> cp_vec;
    cp_vec.push_back(s->get_data(npc)->getpos());
    cp_vec.push_back(glm::vec3(-5.0 , (npcScale*npcHauteur)/2.f, -21.0));
    cp_vec.push_back(glm::vec3(-16.0 , (npcScale*npcHauteur)/2.f, -21.0));
    cp_vec.push_back(glm::vec3(-16.0 , (npcScale*npcHauteur)/2.f, -2.0));
    ev.setCheckpoint(cp_vec);
    s->get_data(npc)->setEvent(ev);

    sol->addChild(npc);

    Node* npc2 = s->make_node_npc(0);
    
    s->get_data(npc2)->set_front(glm::vec3(-1.0,0.0,0.0));
    s->scalenode(npc2 , glm::vec3(npcScale , npcScale*npcHauteur , npcScale));
    s->translatenode(npc2, glm::vec3(-2.5 , (npcScale*npcHauteur)/2.f  , 5.0));
    ChampVision CVnpc2 = ChampVision(s->get_data(npc2)->getpos() , s->get_data(npc2)->get_front() , 1.f * s->get_data(npc2)->getscale()  , 20.f * s->get_data(npc2)->getscale(), 1.f * s->get_data(npc2)->getscale()); // rayon , hauteur , rayon au sol
    s->get_data(npc2)->setChampVision(CVnpc2);
    s->get_data(npc2)->set_color(glm::vec3(0.8f , 0.1f, 0.1f));

    Event ev2(typeEvent::NPC_Checkpoint);
    std::vector<glm::vec3> cp_vec2;
    cp_vec2.push_back(s->get_data(npc2)->getpos());
    cp_vec2.push_back(glm::vec3(-15.50 , (npcScale*npcHauteur)/2.f, 5.0));
    ev2.setCheckpoint(cp_vec2);
    s->get_data(npc2)->setEvent(ev2);

    sol->addChild(npc2);

    Node* npc3 = s->make_node_npc(0);
    
    s->get_data(npc3)->set_front(glm::vec3(1.0,0.0,0.0));
    s->scalenode(npc3 , glm::vec3(npcScale , npcScale*npcHauteur , npcScale));
    s->translatenode(npc3, glm::vec3(-15.50 , (npcScale*npcHauteur)/2.f  , 11.0));
    ChampVision CVnpc3 = ChampVision(s->get_data(npc3)->getpos() , s->get_data(npc3)->get_front() , 1.f * s->get_data(npc3)->getscale()  , 20.f * s->get_data(npc3)->getscale(), 1.f * s->get_data(npc3)->getscale()); // rayon , hauteur , rayon au sol
    s->get_data(npc3)->setChampVision(CVnpc3);
    s->get_data(npc3)->set_color(glm::vec3(0.8f , 0.1f, 0.1f));

    Event ev3(typeEvent::NPC_Checkpoint);
    std::vector<glm::vec3> cp_vec3;
    cp_vec3.push_back(s->get_data(npc3)->getpos());
    cp_vec3.push_back(glm::vec3(-2.5 , (npcScale*npcHauteur)/2.f, 11.0));
    ev3.setCheckpoint(cp_vec3);
    s->get_data(npc3)->setEvent(ev3);

    sol->addChild(npc3);

    Node* npc4 = s->make_node_npc(0);
    
    s->get_data(npc4)->set_front(glm::vec3(1.0,0.0,0.0));
    s->scalenode(npc4 , glm::vec3(npcScale , npcScale*npcHauteur , npcScale));
    s->translatenode(npc4, glm::vec3(2.5 , (npcScale*npcHauteur)/2.f  , 8.0));
    ChampVision CVnpc4 = ChampVision(s->get_data(npc4)->getpos() , s->get_data(npc4)->get_front() , 1.f * s->get_data(npc4)->getscale()  , 20.f * s->get_data(npc4)->getscale(), 1.f * s->get_data(npc4)->getscale()); // rayon , hauteur , rayon au sol
    s->get_data(npc4)->setChampVision(CVnpc4);
    s->get_data(npc4)->set_color(glm::vec3(0.8f , 0.1f, 0.1f));
    sol->addChild(npc4);

    Node* npc5 = s->make_node_npc(0);
    
    s->get_data(npc5)->set_front(glm::vec3(-1.0,0.0,0.0));
    s->scalenode(npc5 , glm::vec3(npcScale , npcScale*npcHauteur , npcScale));
    s->translatenode(npc5, glm::vec3(15.0 , (npcScale*npcHauteur)/2.f  , 6.0));
    ChampVision CVnpc5 = ChampVision(s->get_data(npc5)->getpos() , s->get_data(npc5)->get_front() , 1.f * s->get_data(npc5)->getscale()  , 20.f * s->get_data(npc5)->getscale(), 1.f * s->get_data(npc5)->getscale()); // rayon , hauteur , rayon au sol
    s->get_data(npc5)->setChampVision(CVnpc5);
    s->get_data(npc5)->set_color(glm::vec3(0.8f , 0.1f, 0.1f));
    sol->addChild(npc5);

    
    Node* npc6 = s->make_node_npc(0);
    
    s->get_data(npc6)->set_front(glm::vec3(0.0,0.0,-1.0));
    s->scalenode(npc6 , glm::vec3(npcScale , npcScale*npcHauteur , npcScale));
    s->translatenode(npc6, glm::vec3(2.5 , (npcScale*npcHauteur)/2.f  , 24.0));
    ChampVision CVnpc6 = ChampVision(s->get_data(npc6)->getpos() , s->get_data(npc6)->get_front() , 1.f * s->get_data(npc6)->getscale()  , 10.f * s->get_data(npc6)->getscale(), 1.f * s->get_data(npc6)->getscale()); // rayon , hauteur , rayon au sol
    s->get_data(npc6)->setChampVision(CVnpc6);
    s->get_data(npc6)->set_color(glm::vec3(0.8f , 0.1f, 0.1f));
    sol->addChild(npc6);

    Node* npc7 = s->make_node_npc(0);
    
    s->get_data(npc7)->set_front(glm::vec3(0.0,0.0,-1.0));
    s->scalenode(npc7 , glm::vec3(npcScale , npcScale*npcHauteur , npcScale));
    s->translatenode(npc7, glm::vec3(5.5 , (npcScale*npcHauteur)/2.f  , 24.0));
    ChampVision CVnpc7 = ChampVision(s->get_data(npc7)->getpos() , s->get_data(npc7)->get_front() , 1.f * s->get_data(npc7)->getscale()  , 6.f * s->get_data(npc7)->getscale(), 1.f * s->get_data(npc7)->getscale()); // rayon , hauteur , rayon au sol
    s->get_data(npc7)->setChampVision(CVnpc7);
    s->get_data(npc7)->set_color(glm::vec3(0.8f , 0.1f, 0.1f));
    sol->addChild(npc7);

        /////////////Mesh
        /*
    Node* chair1 = s->make_node_mesh("../src/maillages/Chair/chair.off",0);
    s->get_data(chair1)->set_color(glm::vec3(0.8f , 0.8f, 0.1f)); 
    float chairScale=4.0;
    s->rotatenode(chair1, 90.f, glm::vec3(0.0, 1.0, 0.0));
    s->scalenode(chair1 ,  glm::vec3(chairScale , chairScale , chairScale));
    s->translatenode(chair1, glm::vec3(-2.0 , 0.0, -16.0));

    sol->addChild(chair1);

     Node* chair2 = s->make_node_mesh("../src/maillages/Chair/chair.off",0);
    s->get_data(chair2)->set_color(glm::vec3(0.8f , 0.8f, 0.4f)); 
    s->rotatenode(chair2, 90.f, glm::vec3(0.0, 1.0, 0.0));
    s->scalenode(chair2 ,  glm::vec3(chairScale , chairScale , chairScale));
    s->translatenode(chair2, glm::vec3(-2.0 , 0.0, -13.0));

    sol->addChild(chair2);
*/
    Node* eventVictoire=s->make_node_event(typeEvent::Pickable,0);
     s->translatenode(eventVictoire, glm::vec3(9.0 , 0.0, -13.0));
    sol->addChild(eventVictoire);
    

    s->initscene();
    s->calculateBoundingBoxRecursive(sol);



}


void makeScene_0(Scene* s, const unsigned int SCR_WIDTH, const unsigned int SCR_HEIGHT){
    //s->resetscene();

    //////////////ROOM 
    Node* sol = makeRoom(*s,36,60,6,glm::vec3(1.0f),0);   
    Node* protection = s->make_node_cube(0);
    s->scalenode(protection , glm::vec3(36.0,1.0,60.0));
    s->translatenode(protection , glm::vec3(0.0,-0.51,0.0));
    sol->addChild(protection);
    /////////////LIGHT 
    
    /////// light1
    Node* lumiere1 = s->make_node_light(true,false , 0);
    sol->addChild(lumiere1);
    s->setposnode(lumiere1 , glm::vec3(13.f , 4.5f , -23.f));
    s->setcolornode(lumiere1 , glm::vec3(1.f , 0.4f , 0.4f)); 
    sol->addChild(lumiere1);
    /////// light2
    Node* lumiere2 = s->make_node_light(true,false , 0);    
    s->setposnode(lumiere2 , glm::vec3(1.f , 4.5f , 20.f) );
    s->setcolornode(lumiere2 , glm::vec3(0.4f , 1.f , 0.4f) ); 
    sol->addChild(lumiere2);

    Node* lumiere4 = s->make_node_light(true,false , 0);    
    s->setposnode(lumiere4 , glm::vec3(-17.f , 4.5f , -24.f) );
    s->setcolornode(lumiere4 , glm::vec3(1.f) ); 
    sol->addChild(lumiere4);

    Node* lumiere5 = s->make_node_light(true,false , 0);    
    s->setposnode(lumiere5 , glm::vec3(13.f , 4.5f , 1.f) );
    s->setcolornode(lumiere5 , glm::vec3(1.f) ); 
    sol->addChild(lumiere5);

    Node* lumiere6 = s->make_node_light(true,false , 0);    
    s->setposnode(lumiere6 , glm::vec3(-16.f , 4.5f , 26.f) );
    s->setcolornode(lumiere6 , glm::vec3(1.f) ); 
    sol->addChild(lumiere6);

    Node* lumiere7 = s->make_node_light(true,false , 0);    
    s->setposnode(lumiere7 , glm::vec3(13.f , 4.5f , 26.f) );
    s->setcolornode(lumiere7 , glm::vec3(1.f) ); 
    sol->addChild(lumiere7);

    Node* lumiere8 = s->make_node_light(true,false , 0);    
    s->setposnode(lumiere8 , glm::vec3(-16.f , 4.5f , -14.f) );
    s->setcolornode(lumiere8 , glm::vec3(1.f) ); 
    sol->addChild(lumiere8);
    
    Node* lumiere3 = s->make_node_light(false , true , 0);
    sol->addChild(lumiere3);
    s->get_data(lumiere3)->set_color(glm::vec3(1.f)); 
    s->get_data(lumiere3)->set_front(glm::normalize(glm::vec3(1.f ,-1.f , 0.f )));
    sol->addChild(lumiere3);

    
    
    
    
    //Node* lumiere2 = s->make_node_light(0);
//     sol->addChild(lumiere2);
//     s->get_data(lumiere2)->set_pos(glm::vec3(-15.f , 4.f , 10.f ));
//     s->get_data(lumiere2)->set_color(glm::vec3(0.6f , 1.f , 0.6f));    
//      Node* lumiere1 = s->make_node_light(0);
//      sol->addChild(lumiere1);
//      s->get_data(lumiere1)->set_pos(glm::vec3(20.f , 4.f , -10.f ));
//      s->get_data(lumiere1)->set_color(glm::vec3(0.6f , 1.f , 0.6f)); 
//     Node* lumiere3 = s->make_node_light(0);
//      sol->addChild(lumiere3);
//      s->get_data(lumiere3)->set_pos(glm::vec3(-15.f , 4.f , 10.f ));
//      s->get_data(lumiere3)->set_color(glm::vec3(0.6f , 1.f , 0.6f)); 
    
//     Node* lumiere2 = s->make_node_light();
//     sol->addChild(lumiere2);
//     s->get_data(lumiere2)->set_pos(glm::vec3(16.f , 4.0f , 0.f ));
// 
   
//     Node* lumiere1cube = s->make_node_cube(0);
//     sol->addChild(lumiere1cube);
//     s->get_data(lumiere1cube)->set_pos(glm::vec3(-10.f , 4.f , 20.f ));
//     s->get_data(lumiere1cube)->set_color(glm::vec3(1.f ));
    
   //////////////PLAYER
    //Node* player = s->make_node_mesh("../src/maillages/Cubone/pkm.off",0);
    Node* player = s->make_node_cube(0);
    s->setNodePlayer(player);
    s->get_data(player)->set_color(glm::vec3(0.1f , 0.1f, 1.f)); 
    float playerScale=0.4;
    s->scalenode(player , glm::vec3(playerScale));
    s->translatenode(player, glm::vec3(0.0 , playerScale/2.0, -29.4));
    s->get_data(player)->getgameObjectInfo().setHasPhysics(true);
   // s->get_data(player)->calculateBoundingBox();
    s->get_data(player)->setMasse(40.f);
    sol->addChild(player);


    ///////////////////// premier NPC couloir haut
    //Node* npc = s->make_node_npc_mesh("../src/maillages/Gorilla/gorilla.off",0);
    Node* npc = s->make_node_npc(0);
    float npcScale=1.50;
    float npcHauteur=1.0;
    
    s->get_data(npc)->set_front(glm::vec3(.0,0.0,-1.0));
    s->scalenode(npc , glm::vec3(npcScale , npcScale*npcHauteur , npcScale));
    s->translatenode(npc, glm::vec3(13.0 , (npcScale*npcHauteur)/2.f  , 1.0));
    ChampVision CVnpc2 = ChampVision(s->get_data(npc)->getpos() , s->get_data(npc)->get_front() , 1.f * s->get_data(npc)->getscale()  , 60.f * s->get_data(npc)->getscale(), 1.f * s->get_data(npc)->getscale()); // rayon , hauteur , rayon au sol
    s->get_data(npc)->setChampVision(CVnpc2);
    s->get_data(npc)->set_color(glm::vec3(0.8f , 0.1f, 0.1f));

    Event ev(typeEvent::NPC_Checkpoint);
    std::vector<glm::vec3> cp_vec;
    cp_vec.push_back(s->get_data(npc)->getpos());
    cp_vec.push_back(glm::vec3(13.0 , (npcScale*npcHauteur)/2.f, -15.0));
    ev.setCheckpoint(cp_vec);
    s->get_data(npc)->setEvent(ev);

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
    Node* SecurityCam1 = s->make_node_camera(true,SCR_WIDTH , SCR_HEIGHT,0);
    s->get_data(SecurityCam1)->set_pos(glm::vec3(17.4 , 4.8 , -29.4 ));
    s->get_data(SecurityCam1)->set_front(glm::normalize(s->get_data(player)->getpos() - s->get_data(SecurityCam1)->getpos()));
    Helper::setViewtowardFront(s->get_data(SecurityCam1));
    Camera * c1 = static_cast<Camera*>( s->get_data(SecurityCam1));
    c1->setlimit_yaw_min(-90.f);
    c1->setlimit_yaw_max(0.f);
    c1->setlimit_pitch_min(0.f);
    c1->setlimit_pitch_max(90.f);
    c1->setFOV(45.0);
    sol->addChild(SecurityCam1);

    /////////////CAM2 position centre bas
    Node* SecurityCam2 = s->make_node_camera(true,SCR_WIDTH , SCR_HEIGHT,0);
    s->get_data(SecurityCam2)->set_pos(glm::vec3(-17.4 , 4.8 ,0.0));
    s->get_data(SecurityCam2)->set_front(glm::normalize(glm::vec3(0.f) - s->get_data(SecurityCam2)->getpos()));
    Helper::setViewtowardFront(s->get_data(SecurityCam2));
    Camera * c2 = static_cast<Camera*>( s->get_data(SecurityCam2));
    c2->setFOV(45.0);
    c2->setlimit_yaw_min(-180.f);
    c2->setlimit_yaw_max(180.f);
    c2->setlimit_pitch_min(0.f);
    c2->setlimit_pitch_max(90.f);
    sol->addChild(SecurityCam2);
    
    /////////////CAM3 position haut droit sur une cloiture
    Node* SecurityCam3 = s->make_node_camera(true,SCR_WIDTH , SCR_HEIGHT,0);
    s->get_data(SecurityCam3)->set_pos(glm::vec3(8.4 , 3.8 ,23.4));
    s->get_data(SecurityCam3)->set_front(glm::normalize(s->get_data(player)->getpos() - s->get_data(SecurityCam3)->getpos()));
    Helper::setViewtowardFront(s->get_data(SecurityCam3));
    Camera * c3 = static_cast<Camera*>( s->get_data(SecurityCam3));
    c3->setFOV(45.0);
    c3->setlimit_yaw_min(-180.f);
    c3->setlimit_yaw_max(180.f);
    c3->setlimit_pitch_min(0.f);
    c3->setlimit_pitch_max(90.f);
    sol->addChild(SecurityCam3);

    /////////////Obstacle boite milieu 
    Node* obstacle1 = s->make_node_cube(0);
    s->get_data(obstacle1)->set_color(glm::vec3(0.8f , 0.8f, 0.1f)); 
    float obstacle1Scale=4.0;
    s->scalenode(obstacle1 ,  glm::vec3(obstacle1Scale/2.0 , obstacle1Scale , obstacle1Scale));
    s->translatenode(obstacle1, glm::vec3(-6.0 , obstacle1Scale/2.0, 16.0));
    sol->addChild(obstacle1);

  //  Node* obstacle2 = s->make_node_cube(0);
  //  s->get_data(obstacle2)->set_color(glm::vec3(0.8f , 0.8f, 0.1f)); 

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

    Node* changeCam1_0= s->make_node_event(typeEvent::Previous_Camera,6.0,6.0,1 ,0);
    s->rotatenode(changeCam1_0, 90.f, glm::vec3(1.0, 0.0, 0.0));
    s->translatenode(changeCam1_0,glm::vec3(-9.0, 2.5  ,-18.05));
    sol->addChild(changeCam1_0);

    Node* changeCam0_1= s->make_node_event(typeEvent::Next_Camera,6.0,6.0,0 ,0);
    s->rotatenode(changeCam0_1, 90.f, glm::vec3(1.0, 0.0, 0.0));
    s->translatenode(changeCam0_1,glm::vec3(-9.0, 2.5  ,-17.95));
    sol->addChild(changeCam0_1);

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

    Node* cloison7= s->make_node_mur(2.5, 8.0, 0);
    s->rotatenode(cloison7, 90.f, glm::vec3(0.0, 0.0, 1.0));
    s->translatenode(cloison7,glm::vec3(8.5, 4.5 , 1.5));
    sol->addChild(cloison7);

    Node* changeCam1_0b= s->make_node_event(typeEvent::Previous_Camera,7.0,8.0, 1 ,0);
    s->rotatenode(changeCam1_0b, 90.f, glm::vec3(0.0, 0.0, 1.0));
    s->translatenode(changeCam1_0b,glm::vec3(8.505, 2.5  ,1.5));
    sol->addChild(changeCam1_0b);

    Node* changeCam0_1b= s->make_node_event(typeEvent::Next_Camera,7.0,8.0, 0 ,0);
    s->rotatenode(changeCam0_1b, 90.f, glm::vec3(0.0, 0.0, 1.0));
    s->translatenode(changeCam0_1b,glm::vec3(8.495, 2.5  ,1.5));
    sol->addChild(changeCam0_1b);


    Node* cloison8= s->make_node_mur(6.0, 8.0, 0);
    s->rotatenode(cloison8, 90.f, glm::vec3(0.0, 0.0, 1.0));
    s->translatenode(cloison8,glm::vec3(8.5, 2.5   ,27));
    sol->addChild(cloison8);

    Node* cloison9= s->make_node_mur(2.5, 8.0, 0);
    s->rotatenode(cloison9, 90.f, glm::vec3(0.0, 0.0, 1.0));
    s->translatenode(cloison9,glm::vec3(8.5, 4.5 ,20.0));
    sol->addChild(cloison9);

        Node* changeCam2_1= s->make_node_event(typeEvent::Previous_Camera,7.0,8.0, 2 ,0);
    s->rotatenode(changeCam2_1, 90.f, glm::vec3(0.0, 0.0, 1.0));
    s->translatenode(changeCam2_1,glm::vec3(8.495, 3.0  ,20.f));
    sol->addChild(changeCam2_1);

    Node* changeCam1_2= s->make_node_event(typeEvent::Next_Camera,7.0,8.0, 1 ,0);
    s->rotatenode(changeCam1_2, 90.f, glm::vec3(0.0, 0.0, 1.0));
    s->translatenode(changeCam1_2,glm::vec3(8.505, 3.0 ,20.f));
    sol->addChild(changeCam1_2);

    s->get_data(cloison1)->set_color(glm::vec3(1.f)); 
    s->get_data(cloison2)->set_color(glm::vec3(1.f)); 
    s->get_data(cloison3)->set_color(glm::vec3(1.f)); 
    s->get_data(cloison4)->set_color(glm::vec3(1.f));
    s->get_data(cloison5)->set_color(glm::vec3(1.f));
    s->get_data(cloison6)->set_color(glm::vec3(1.f));
    s->get_data(cloison7)->set_color(glm::vec3(1.f)); 
    s->get_data(cloison8)->set_color(glm::vec3(1.f));
    s->get_data(cloison9)->set_color(glm::vec3(1.f)); 

    float eventScale = 3.0;
    Node* eventPorte=s->make_node_event(typeEvent::TP_Scene_Forward,glm::vec3(17.f,playerScale/2.0,-23.f), 0);
    s->scalenode(eventPorte,glm::vec3(0.2,eventScale, eventScale));
    s->translatenode(eventPorte, glm::vec3(17.4, eventScale/2.0 ,20.0));
    sol->addChild(eventPorte);

   // Node* eventVictoire=s->make_node_event(typeEvent::Pickable,0);
   // sol->addChild(eventVictoire);

    s->initscene();
    s->calculateBoundingBoxRecursive(sol);
}

void makeScene_test(Scene* s, const unsigned int SCR_WIDTH, const unsigned int SCR_HEIGHT){
    //s->resetscene();

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

void makeScene_test2(Scene* s, const unsigned int SCR_WIDTH, const unsigned int SCR_HEIGHT){
    //s->resetscene();
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
