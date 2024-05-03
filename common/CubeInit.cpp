#include "CubeInit.hpp"




void CubeInit::settexture( const std::string & path , GLuint textureIndex, const std::string & name_in_shader) 
{
renderer.stocktexture(path, textureIndex, name_in_shader); 
}
void CubeInit::initobject() 
{
renderer.genbuffer(position , tex_coords , indices);
}
void CubeInit::drawobject() 
{
glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
glUniform1f(glGetUniformLocation(renderer.programID,"shininess"), (this->getshininess()));
glUniform3fv(glGetUniformLocation(renderer.programID,"mesh_color"), 1 , &(this->getcolor())[0]);
glUniformMatrix4fv(glGetUniformLocation(renderer.programID,"modelmat"), 1 , GL_FALSE, &(this->getmodelmat())[0][0]);
renderer.loadtextures(); 

renderer.draw(); 
}

void CubeInit::deleteobject() 
{
renderer.deletebuffers(); 
delete this;
}

