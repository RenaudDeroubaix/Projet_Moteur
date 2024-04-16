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
        go->settranslate(go->getVitesse());
    }

    void applyGravity(GameObject* go ,float deltaTime);

    void applyCollision(GameObject* go, std::vector<Node> & nodelist ,float deltaTime);

    //////FORCE///////
    void applyForce(Scene & s , float deltaTime);

};