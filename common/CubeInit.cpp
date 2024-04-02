#include "CubeInit.hpp"




void CubeInit::settexture( const std::string & path , GLuint textureIndex, const std::string & name_in_shader) 
{
renderer.stocktexture(path, textureIndex, name_in_shader); 
}
void CubeInit::initobject() 
{
renderer.programID = LoadShaders( "../src/shaders/vertex_shader.glsl" , "../src/shaders/fragment_shader.glsl");
renderer.genbuffer(position , tex_coords , indices);
}
void CubeInit::drawobject() 
{
glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
glUniformMatrix4fv(glGetUniformLocation(renderer.programID,"modelmat"), 1 , GL_FALSE, &(this->getmodelmat())[0][0]);
renderer.draw(); 
}

void CubeInit::deleteobject() 
{
renderer.deletebuffers(); 
delete this;
}

void CubeInit::loadtextures() 
{
glUseProgram(renderer.programID);
glUniform3fv(glGetUniformLocation(renderer.programID,"mesh_color"), 1 , &(this->getcolor())[0]);
renderer.loadtextures(); 
}