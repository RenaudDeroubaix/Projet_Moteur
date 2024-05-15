#pragma once
#include "common/utils.hpp"
#include "common/shader.hpp"
#include "common/GameObject.hpp"

class Light : public GameObject{
private: 
    float radius = 20.f;
public:
    Light() : GameObject() {}    
    void set_radius(float f){radius = f;}
    float get_radius(){return radius;}
    void initobject() override;
    void drawobject() override;
    void deleteobject() override;
    void settexture(const std::string & path , GLuint textureIndex, const std::string & name_in_shader) override;

   
    
};
