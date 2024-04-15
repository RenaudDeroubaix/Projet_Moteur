#include "GameObject.hpp"

glm::vec3 GameObject::getpos() { return glm::vec3(modelmat[0][3] ,modelmat[1][3], modelmat[2][3]);}
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
