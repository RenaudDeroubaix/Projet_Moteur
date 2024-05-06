#include "Plan.hpp"

Plan::Plan(glm::vec3 p , int hauteur , int  largeur) : GameObject(p) , h(hauteur) , l(largeur)
{
        float scale_plan = 1.0;
        float x , y , z;
        pas_h  = 1. / (float)h;
        pas_l  = 1. / (float)l;
        float min = std::max(l , h); 
        
        for (int i = 0; i < h ; i++) {
            for (int j = 0; j < l; j++) {
                // Calcul de la position relative
                x = (i - (float)(h - 1) * 0.5f ) * scale_plan + pos[0];
                y = pos[1];
                z = (j - (float)(l - 1) * 0.5f ) * scale_plan + pos[2];
                
                position.push_back(glm::vec3(x, y, z));
                normals.push_back(glm::vec3(0.f, 1.f , 0.f));
                
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
    float max_pas = std::max( pas_h , pas_l);
    for (int i = 0; i < h ; i++) {
        for (int j = 0; j < l; j++) {
            tex_coords.push_back(glm::vec2(i * pas_h * scale_tex  , j * pas_h * scale_tex ));
            
        }
    }
    
    renderer.stocktexture(path, textureIndex, name_in_shader); 

}
void Plan::initobject() 
{
renderer.genbuffer(position , normals , tex_coords  ,indices);
//renderer.programID = LoadShaders( "../src/shaders/vertex_hm.glsl" , "../src/shaders/frag_hm.glsl");
//renderer.genbuffer(position , tex_coords , indices);
}
void Plan::drawobject() 
{
glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
glUniform3fv(glGetUniformLocation(renderer.programID,"mesh_color"), 1 , &(this->getcolor())[0]);
glUniform1f(glGetUniformLocation(renderer.programID,"shininess"), (this->getshininess()));
glUniformMatrix4fv(glGetUniformLocation(renderer.programID,"modelmat"), 1 , GL_FALSE, &(this->getmodelmat())[0][0]);
renderer.loadtextures(); 
renderer.draw(); 
}

void Plan::deleteobject() 
{
renderer.deletebuffers(); 
delete this;
}



