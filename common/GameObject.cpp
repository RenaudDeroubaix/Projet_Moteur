#include "GameObject.hpp"

glm::vec3 GameObject::getpos() { return glm::vec3(modelmat[3][0] ,modelmat[3][1], modelmat[3][2]);}
void GameObject::setpos(glm::vec3 p) {  modelmat[3][0]=p.x ,modelmat[3][1]=p.y, modelmat[3][2]=p.z;}
glm::mat4 GameObject::getmodelmat() { return modelmat;}

void GameObject::setscale(glm::vec3 s)
{
    modelmat = glm::scale(glm::mat4(1.f) , s) * modelmat;

}
void GameObject::settranslate(glm::vec3 t)
{
    modelmat = glm::translate(glm::mat4(1.f) , t) * modelmat;

}
void GameObject::setrotate(float angle ,glm::vec3 axe)
{
    modelmat =  glm::rotate( glm::mat4(1.f) ,glm::radians(angle) , axe) * modelmat;
   
}

void GameObject::calculateBoundingBox() {
        glm::vec3 minPos = glm::vec3(std::numeric_limits<float>::max());
        glm::vec3 maxPos = glm::vec3(std::numeric_limits<float>::lowest());

        // Calcul des positions extrêmes
        for (glm::vec3 localPos : position) {
            glm::vec4 worldPos = modelmat * glm::vec4(localPos, 1.0f);
            minPos = glm::min(minPos, glm::vec3(worldPos));
            maxPos = glm::max(maxPos, glm::vec3(worldPos));
        }

        minBoundingBox = minPos;
        maxBoundingBox = maxPos;
}

bool GameObject::checkCollision(const GameObject& other) {
        // Vérifier la collision entre les boîtes englobantes
        return (maxBoundingBox[0] >= other.minBoundingBox[0] && minBoundingBox[0] <= other.maxBoundingBox[0]) &&
               (maxBoundingBox[1] >= other.minBoundingBox[1] && minBoundingBox[1] <= other.maxBoundingBox[1]) &&
               (maxBoundingBox[2] >= other.minBoundingBox[2] && minBoundingBox[2] <= other.maxBoundingBox[2]);
    }