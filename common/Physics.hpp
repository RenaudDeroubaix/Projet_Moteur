#pragma once
#include "common/utils.hpp"
#include "Scene.hpp"

class Physics {
protected:
    float gravity = 9.81;

public:
    Physics(){}   
    float getForceDeGravite(float masse){
        return masse * gravity;
    }
    void applyVitesse(GameObject* go){
        go->setOldPos();
        go->setVitesse(go->getVitesse());
        // float vitesseMax = go->getscale() * 4.0;
        // vitesse.x = vitesse.x > vitesseMax ? vitesseMax : vitesse.x < -vitesseMax ? -vitesseMax : vitesse.x; 
        // vitesse.y = vitesse.y > vitesseMax ? vitesseMax : vitesse.y < -vitesseMax ? -vitesseMax : vitesse.y; 
        // vitesse.z = vitesse.z > vitesseMax ? vitesseMax : vitesse.z < -vitesseMax ? -vitesseMax : vitesse.z; 
        
        go->settranslate(go->getVitesse());
    }

    void applyGravity(GameObject* go ,float deltaTime);

    void applyCollision(GameObject* go, std::vector<Node*> & nodelist ,float deltaTime);

    //////FORCE///////
    void applyForce(Scene & s , float deltaTime);

};