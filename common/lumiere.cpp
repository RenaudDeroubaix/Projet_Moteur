#include "lumiere.hpp"

void Light::settexture( const std::string & path , GLuint textureIndex, const std::string & name_in_shader) 
{}
void Light::initobject() 
{}
void Light::drawobject() 

{
    glUniformMatrix3fv(glGetUniformLocation(renderer.programID,"light_pos"), 1 , GL_FALSE, &(this->getpos())[0]);
    glUniformMatrix3fv(glGetUniformLocation(renderer.programID,"light_color"), 1 , GL_FALSE, &(this->getcolor())[0]);
    
}

void Light::deleteobject() 
{delete this;}

