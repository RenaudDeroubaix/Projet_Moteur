#pragma once
#include "common/utils.hpp"
#include "common/shader.hpp"
#include "common/GameObject.hpp"

class CubeInit : public GameObject{
private:

    glm::vec3 pos;
    glm::mat4 modelmat = glm::mat4(1.f);
    
public:
    CubeInit() : GameObject() 
    {
        is_rendered = true;
        std::vector<std::vector<unsigned short>> triangles; // Liste des triangles
        
        
        // Définir les sommets du cube
        position.push_back(glm::vec3(-0.5f, -0.5f, -0.5f)); // 0
        position.push_back(glm::vec3(0.5f, -0.5f, -0.5f));  // 1
        position.push_back(glm::vec3(0.5f, 0.5f, -0.5f));   // 2
        position.push_back(glm::vec3(-0.5f, 0.5f, -0.5f));  // 3
        position.push_back(glm::vec3(-0.5f, -0.5f, 0.5f));  // 4
        position.push_back(glm::vec3(0.5f, -0.5f, 0.5f));   // 5
        position.push_back(glm::vec3(0.5f, 0.5f, 0.5f));    // 6
        position.push_back(glm::vec3(-0.5f, 0.5f, 0.5f));   // 7
        
        // Définir les indices pour former les triangles du cube
        indices = {
            0, 1, 2, 0, 2, 3,   // Face avant
            1, 5, 6, 1, 6, 2,   // Face droite
            5, 4, 7, 5, 7, 6,   // Face arrière
            4, 0, 3, 4, 3, 7,   // Face gauche
            3, 2, 6, 3, 6, 7,   // Face supérieure
            4, 5, 1, 4, 1, 0    // Face inférieure
        };
        
    }
 
    void initobject() override;
    void drawobject() override;
    void deleteobject() override;
    void settexture(const std::string & path , GLuint textureIndex, const std::string & name_in_shader) override;

   
    
};
