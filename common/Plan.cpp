#include "Plan.hpp"

Plan::Plan(glm::vec3 p , int hauteur , int  largeur) : GameObject(p) , h(hauteur) , l(largeur)
{
        float x , y , z;
        float pas  = 1. / std::min(l , h);
        
        for (int i = 0 ; i < h ; i++){
            for (int j = 0 ; j < l ; j++){
                x = (i + pos[0]) / (float)l - 0.5f ;
                y  = pos[0];
                z = (j + pos[2]) / (float)h - 0.5f;
                position.push_back(glm::vec3(x,y,z));
                tex_coords.push_back(glm::vec2(pas * i , pas * j));
            }
        }              
        
        for (int i = 1; i < h - 1; i++ ){
            for (int j = 1 ; j < l - 1; j++ ){
                indices.push_back(i*l+j);
                indices.push_back(i*l+(j+1));
                indices.push_back((i+1)*l+j);
                
                indices.push_back(i*l+(j+1));
                indices.push_back((i+1)*l+(j+1));
                indices.push_back((i+1)*l+j);
            }       
        }
        
        
}

void Plan::ResoPlus()
{
    h < 500? h++ : h;
    l < 500? l++ : l;
    *this = Plan(pos , h , l);
    this->initobject();      
}

void Plan::ResoMoins()
{
    h > 3? h-- : h;
    l > 3? l-- : l;
    *this = Plan(pos , h , l);
    this->initobject();  
}


void Plan::settexture( const std::string & path , GLuint textureIndex, const std::string & name_in_shader) 
{
renderer.stocktexture(path, textureIndex, name_in_shader); 
}
void Plan::initobject() 
{
renderer.programID = LoadShaders( "../src/shaders/vertex_hm.glsl" , "../src/shaders/frag_hm.glsl");
renderer.genbuffer(position , tex_coords , indices);
}
void Plan::drawobject() 
{
glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
glUniformMatrix4fv(glGetUniformLocation(renderer.programID,"modelmat"), 1 , GL_FALSE, &(this->getmodelmat())[0][0]);
renderer.draw(); 
}

void Plan::deleteobject() 
{
renderer.deletebuffers(); 
delete this;
}
void Plan::loadtextures() 
{
glUseProgram(renderer.programID);
glUniform3fv(glGetUniformLocation(renderer.programID,"mesh_color"), 1 , &(this->getcolor())[0]);
renderer.loadtextures(); 
}




