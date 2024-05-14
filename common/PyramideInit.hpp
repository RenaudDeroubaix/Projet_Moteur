#pragma once
#include "common/utils.hpp"
#include "common/shader.hpp"
#include "common/GameObject.hpp"

class PyramideInit : public GameObject {
private:
    glm::vec3 pos;
    glm::mat4 modelmat = glm::mat4(1.f);

public:
    PyramideInit() : GameObject() {

        // Définir les sommets de la pyramide avec le sommet à l'avant
        position.push_back(glm::vec3(0.0f, 1.0f, 0.0f));  // Sommet (0)
        position.push_back(glm::vec3(-0.5f, 0.0f, 0.5f)); // Coin avant gauche (1)
        position.push_back(glm::vec3(0.5f, 0.0f, 0.5f));  // Coin avant droit (2)
        position.push_back(glm::vec3(0.5f, 0.0f, -0.5f)); // Coin arrière droit (3)
        position.push_back(glm::vec3(-0.5f, 0.0f, -0.5f));// Coin arrière gauche (4)

        // Définir les indices pour former les triangles de la pyramide
        indices = {
            0, 1, 2, // Face avant
            0, 2, 3, // Face droite
            0, 3, 4, // Face arrière
            0, 4, 1, // Face gauche
            1, 2, 3, // Base triangle droit
            1, 3, 4  // Base triangle gauche
        };

        normals = {
            glm::normalize(glm::cross(position[1] - position[0], position[2] - position[0])), // Normale face avant
            glm::normalize(glm::cross(position[2] - position[0], position[3] - position[0])), // Normale face droite
            glm::normalize(glm::cross(position[3] - position[0], position[4] - position[0])), // Normale face arrière
            glm::normalize(glm::cross(position[4] - position[0], position[1] - position[0])), // Normale face gauche
            glm::vec3(0.0f, -1.0f, 0.0f), // Normale de la base
            glm::vec3(0.0f, -1.0f, 0.0f)  // Normale de la base
        };
    }

    void initobject() override;
    void drawobject() override;
    void deleteobject() override;
    void settexture(const std::string& path, GLuint textureIndex, const std::string& name_in_shader) override;
};
