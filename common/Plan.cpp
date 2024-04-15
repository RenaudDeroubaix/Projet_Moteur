#include "Plan.hpp"

Plan::Plan(glm::vec3 p , int hauteur , int  largeur) : GameObject(p) , h(hauteur) , l(largeur)
{
        float scale_plan =0.1;
        float x , y , z;
        float pas_h  = 1. /  (float)h;
        float pas_l  = 1. /  (float)l;
        // Calcul des bornes pour le centrage
        float half_width = (float)(largeur) * pas_l * 0.5f;
        float half_height = (float)(hauteur) * pas_h * 0.5f;
        
        for (int i = 0; i < h; i++) {
            for (int j = 0; j < l; j++) {
                // Calcul de la position relative
                x = (i - (float)(h - 1) * 0.5f ) * scale_plan + pos[0];
                y = pos[1];
                z = (j - (float)(l - 1) * 0.5f ) * scale_plan + pos[2];
                position.push_back(glm::vec3(x, y, z));
                tex_coords.push_back(glm::vec2(pas_l * i , pas_h * j));
            }
        }              
        
        for (int i = 0; i < h - 1; i++ ){
            for (int j = 0 ; j < l - 1; j++ ){
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
renderer.programID = LoadShaders( "../src/shaders/vertex_shader.glsl" , "../src/shaders/fragment_shader.glsl");
renderer.genbuffer(position , tex_coords , indices);
//renderer.programID = LoadShaders( "../src/shaders/vertex_hm.glsl" , "../src/shaders/frag_hm.glsl");
//renderer.genbuffer(position , tex_coords , indices);
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



