#pragma once
#include "common/utils.hpp"
#include "common/shader.hpp"
#include "common/GameObject.hpp"

class Mur : public GameObject{
private:

    glm::vec3 pos;
    glm::mat4 modelmat = glm::mat4(1.f);
    int h ; int l;
    
public:
    Mur() : GameObject() {}
    Mur(glm::vec3 p , int hauteur , int  largeur);
    void ResoPlus();
    void ResoMoins();
    
 
    void initobject() override;
    void drawobject() override;
    void deleteobject() override;
    void settexture(const std::string & path , GLuint textureIndex, const std::string & name_in_shader) override;
    void loadtextures() override;

   
    
};




