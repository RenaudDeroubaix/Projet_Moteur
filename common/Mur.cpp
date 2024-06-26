#include "Mur.hpp"

Mur::Mur(glm::vec3 p , int hauteur , int  largeur ) : GameObject(p) , h(hauteur) , l(largeur)
{
    float epaisseur = 0.1;
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
                normals.push_back(glm::vec3(0.f, -1.f ,0.f));
                
            }
        }  
         for (int i = 0; i < h ; i++) {
            for (int j = 0; j < l; j++) {
                // Calcul de la position relative
                x = (i - (float)(h - 1) * 0.5f ) * scale_plan + pos[0];
                y = pos[1];
                z = (j - (float)(l - 1) * 0.5f ) * scale_plan + pos[2];
                
                position.push_back(glm::vec3(x, y+epaisseur, z));
                normals.push_back(glm::vec3(0.f, 1.f ,0.f));
                
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

                indices.push_back(i*l+j + position.size()/2);
                indices.push_back((i+1)*l+j+ position.size()/2);
                indices.push_back(i*l+(j+1)+ position.size()/2);

                indices.push_back((i+1)*l+j+ position.size()/2);
                indices.push_back((i+1)*l+(j+1)+ position.size()/2);
                indices.push_back(i*l+(j+1)+ position.size()/2); 
            }       
        }
        
        
    
}

void Mur::ResoPlus()
{
    h < 500? h++ : h;
    l < 500? l++ : l;
    *this = Mur(pos , h , l);
    this->initobject();      
}

void Mur::ResoMoins()
{
    h > 3? h-- : h;
    l > 3? l-- : l;
    *this = Mur(pos , h , l);
    this->initobject();  
}


void Mur::settexture( const std::string & path , GLuint textureIndex, const std::string & name_in_shader) 
{
renderer.stocktexture(path, textureIndex, name_in_shader); 
}
void Mur::initobject() 
{
    
renderer.genbuffer(position , normals , tex_coords  ,indices);
//renderer.programID = LoadShaders( "../src/shaders/vertex_hm.glsl" , "../src/shaders/frag_hm.glsl");
//renderer.genbuffer(position , tex_coords , indices);
}
void Mur::drawobject() 
{
glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
glUniform1f(glGetUniformLocation(renderer.programID,"shininess"), (this->getshininess()));
glUniform3fv(glGetUniformLocation(renderer.programID,"mesh_color"), 1 , &(this->getcolor())[0]);
glUniformMatrix4fv(glGetUniformLocation(renderer.programID,"modelmat"), 1 , GL_FALSE, &(this->getmodelmat())[0][0]);
renderer.loadtextures(); 
renderer.draw(); 
}

void Mur::deleteobject() 
{
renderer.deletebuffers(); 
delete this;
}





