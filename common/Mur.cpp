#include "Mur.hpp"

Mur::Mur(glm::vec3 p , int hauteur , int  largeur) : GameObject(p) , h(hauteur) , l(largeur)
{
    is_rendered = true;
    float scale_mur = 1.0f;
    float x, y, z;
    float pas_h = 1.0f / static_cast<float>(h);
    float pas_l = 1.0f / static_cast<float>(l);
    // Calcul des bornes pour le centrage
    float half_width = static_cast<float>(largeur) * pas_l * 0.5f;
    float half_height = static_cast<float>(hauteur) * pas_h * 0.5f;

    for (int i = 0; i < h; i++) {
        for (int j = 0; j < l; j++) {
            // Calcul de la position relative
            x = (i - static_cast<float>(h - 1) * 0.5f) * scale_mur + pos[0];
            y = pos[1];
            z = (j - static_cast<float>(l - 1) * 0.5f) * scale_mur + pos[2];
            position.push_back(glm::vec3(x, y, z));
            tex_coords.push_back(glm::vec2(pas_l * i, pas_h * j));
        }
    }

    // Calcul des indices et des normales pour chaque triangle
    for (int i = 0; i < h - 1; i++) {
        for (int j = 0; j < l - 1; j++) {
            // Indices des sommets formant le premier triangle
            int index1 = i * l + j;
            int index2 = i * l + (j + 1);
            int index3 = (i + 1) * l + j;

            // Calcul des normales pour chaque triangle et ajout aux sommets
            glm::vec3 v1 = position[index2] - position[index1];
            glm::vec3 v2 = position[index3] - position[index1];
            glm::vec3 normal = glm::normalize(glm::cross(v1, v2));
            normals.push_back(normal);
            normals.push_back(normal);
            normals.push_back(normal);

            // Indices des sommets formant le deuxième triangle
            index1 = i * l + (j + 1);
            index2 = (i + 1) * l + (j + 1);
            index3 = (i + 1) * l + j;

            // Calcul des normales pour chaque triangle et ajout aux sommets
            v1 = position[index2] - position[index1];
            v2 = position[index3] - position[index1];
            normal = glm::normalize(glm::cross(v1, v2));
            normals.push_back(normal);
            normals.push_back(normal);
            normals.push_back(normal);

            // Ajout des indices pour chaque triangle
            indices.push_back(index1);
            indices.push_back(index2);
            indices.push_back(index3);

            indices.push_back(index3);
            indices.push_back(index2);
            indices.push_back(index1);
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
renderer.programID = LoadShaders( "../src/shaders/vertex_shader.glsl" , "../src/shaders/fragment_shader.glsl");
renderer.genbuffer(position , tex_coords , indices);
//renderer.programID = LoadShaders( "../src/shaders/vertex_hm.glsl" , "../src/shaders/frag_hm.glsl");
//renderer.genbuffer(position , tex_coords , indices);
}
void Mur::drawobject() 
{
glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
glUniformMatrix4fv(glGetUniformLocation(renderer.programID,"modelmat"), 1 , GL_FALSE, &(this->getmodelmat())[0][0]);
renderer.draw(); 
}

void Mur::deleteobject() 
{
renderer.deletebuffers(); 
delete this;
}
void Mur::loadtextures() 
{
glUseProgram(renderer.programID);
glUniform3fv(glGetUniformLocation(renderer.programID,"mesh_color"), 1 , &(this->getcolor())[0]);
renderer.loadtextures(); 
}




