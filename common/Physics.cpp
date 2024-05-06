#include "Physics.hpp"

void Physics::applyGravity(GameObject* go ,float deltaTime){
    float F = getForceDeGravite(go->getMasse());
    float gravite = -(F / go->getMasse()) * deltaTime * 0.1f  ;
    //std::cout<< gravite << std::endl;
    go->addVitesse(glm::vec3(0.f, gravite , 0.f));    
    //std::cout<< "fin boucle gravity" <<std::endl;
    
}
/*
void Physics::applyCollision(GameObject* go, std::vector<Node> & nodelist ,float deltaTime){
    bool collision=false;
    GameObject* collisionGO;
    int i=0;
    for (Node & n : nodelist){
        GameObject* otherGO = n.getData();
        if (otherGO!=go && go->checkCollision(*otherGO)){
            collision=true;
            collisionGO=otherGO;
            std::cout<<"collision avec : "<< i <<std::endl;
            break; // Sortir de la boucle dès qu'une collision est détectée
        }
        i++;
    }
    if (collision){
        glm::vec3 v = go->getVitesse();
        v[1] = 0.0;
        float distanceToCollision = collisionGO->getpos().y - go->getpos().y + (go->getMaxBB().y-go->getMinBB().y)/2; //distance au plan + moitier de la taille de la bb
        go->settranslate(glm::vec3(0.0,distanceToCollision,0.0));
        go->setVitesse(v); 
    }
}*/

void Physics::applyCollision(GameObject* go, std::vector<Node*>& nodelist, float deltaTime) {
    //int i=0;
    for (Node* n : nodelist) {
        GameObject* otherGO = n->getData();
        
            
        if (otherGO != go &&  go->checkCollision(*otherGO) && !otherGO->getgameObjectInfo().getIsEvent()) {
            // Collision détectée
           // std::cout<< "colision detecter "<< i <<std::endl;
           
            glm::vec3 collisionAxe;
            glm::vec3 goMax = go->getMaxBB() ;
            glm::vec3 otherGoMax = otherGO->getMaxBB();
            glm::vec3 goMin = go->getMinBB() ;
            glm::vec3 otherGoMin = otherGO->getMinBB();

            collisionAxe.x = goMax.x >= otherGoMin.x &&  goMin.x <= otherGoMax.x;
            collisionAxe.y = goMax.y >= otherGoMin.y &&  goMin.y <= otherGoMax.y;
            collisionAxe.z = goMax.z >= otherGoMin.z &&  goMin.z <= otherGoMax.z;
            
        /*    std::cout<<collisionAxe.x<<std::endl;
            std::cout<<collisionAxe.y<<std::endl;
            std::cout<<collisionAxe.z<<std::endl;*/
        
            glm::vec3 v = go->getVitesse();
            float sens=1.0;
            float distanceToCollisionx = fabs(otherGO->getpos().x - go->getpos().x) - (go->getMaxBB().x - go->getMinBB().x + otherGO->getMaxBB().x - otherGO->getMinBB().x) / 2;
            float distanceToCollisiony = fabs(otherGO->getpos().y - go->getpos().y) - (go->getMaxBB().y - go->getMinBB().y + otherGO->getMaxBB().y - otherGO->getMinBB().y) / 2;
            float distanceToCollisionz = fabs(otherGO->getpos().z - go->getpos().z) - (go->getMaxBB().z - go->getMinBB().z + otherGO->getMaxBB().z - otherGO->getMinBB().z) / 2;

            // Prendre la valeur absolue pour s'assurer que la distance est toujours positive
            distanceToCollisionx = fabs(distanceToCollisionx);
            distanceToCollisiony = fabs(distanceToCollisiony);
            distanceToCollisionz = fabs(distanceToCollisionz);

            if(v.x !=0 && collisionAxe.x && distanceToCollisionx < distanceToCollisiony && distanceToCollisionx < distanceToCollisionz){
                sens = go->getpos().x < otherGO->getpos().x ? -1.0 : 1.0;
                go->settranslate(glm::vec3(distanceToCollisionx * sens,0.0,0.0));
                if (go->getgameObjectInfo().getIsFalling() ){v.x=-v.x;} else v.x=0.0;
                //std::cout<<sens<<std::endl;
                //std::cout<<go->getpos().x<<std::endl;
                //std::cout<<otherGO->getpos().x<<std::endl;
            }
            else if(v.y != 0 && collisionAxe.y && distanceToCollisiony < distanceToCollisionx && distanceToCollisiony < distanceToCollisionz){
                sens = go->getpos().y < otherGO->getpos().y ? -1.0 : 1.0;
                go->settranslate(glm::vec3(0.0,distanceToCollisiony * sens,0.0));
                v.y=0.0;
                go->getgameObjectInfo().setIsFalling(false);
                //std::cout<<sens<<std::endl;
            } 
            else if(v.z != 0 &&collisionAxe.z && distanceToCollisionz < distanceToCollisiony && distanceToCollisionz < distanceToCollisionx){
                sens = go->getpos().z < otherGO->getpos().z ? -1.0 : 1.0;
                go->settranslate(glm::vec3(0.0,0.0,distanceToCollisionz * sens));
                if (go->getgameObjectInfo().getIsFalling() ){v.z=-v.z;} else v.z=0.0;
                //std::cout<<sens<<std::endl;
                //std::cout<<go->getpos().z<<std::endl;
                //std::cout<<otherGO->getpos().z<<std::endl;
                
            }
            go->setVitesse(v);
        }
        
         //i++;
    }
}


//////FORCE///////
void Physics::applyForce(Scene & s , float deltaTime){
    std::vector<Node* > nodelist =  s.get_node_list();
    for (Node * n : nodelist){
        GameObject* go=s.get_data(n);
        GOInfo goi=go->getgameObjectInfo();
        if(go->getVitesse() == glm::vec3(0.f) && !goi.getIsFalling()){goi.setMovedRecently(false);}
        if(goi.getHasPhysics() && goi.getMovedRecently() ){
            applyVitesse(go);
            applyGravity(go ,deltaTime);
            go->calculateBoundingBox();
            applyCollision(go, nodelist ,deltaTime);
  
        }
        
    }    
}
