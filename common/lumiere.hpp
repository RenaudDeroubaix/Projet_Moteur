#pragma once
#include "common/utils.hpp"
#include "common/shader.hpp"
#include "common/GameObject.hpp"

class Light : public GameObject{
private: 

    
public:
    Light() : GameObject() {}    
 
    void initobject() override;
    void drawobject() override;
    void deleteobject() override;
    void settexture(const std::string & path , GLuint textureIndex, const std::string & name_in_shader) override;

   
    
};
