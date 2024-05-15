#include "GameObject.hpp"

glm::vec3 GameObject::getpos() { return glm::vec3(modelmat[3][0] ,modelmat[3][1], modelmat[3][2]);}
void GameObject::setpos(glm::vec3 p) {  modelmat[3][0]=p.x ,modelmat[3][1]=p.y, modelmat[3][2]=p.z;}
glm::mat4 GameObject::getmodelmat() const { return modelmat;}

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
    modelmat =  glm::rotate(glm::mat4(1.f) ,glm::radians(angle) , axe) * modelmat;
   
}
void GameObject::setrotateeulerYaw(glm::vec3 euler)
{
    //modelmat = glm::rotate(modelmat , glm::radians(euler.x) , glm::vec3(1.f,0.f,0.f));
     glm::mat4 translate =  glm::translate(glm::mat4(1.f) , getpos());
     glm::mat4 scale =  glm::scale(glm::mat4(1.f) ,glm::vec3(getscale()));
     glm::mat4 rotate = glm::rotate(glm::mat4(1.f) , euler.y ,glm::vec3(0.f,1.f,0.f) );

     modelmat = translate * scale * rotate  ;
    // modelmat = glm::rotate(modelmat , euler.y , glm::vec3(0.f,1.f,0.f));

    //modelmat = glm::rotate(modelmat ,glm::radians(euler.z), glm::vec3(0.f,0.f,1.f));
      //modelmat = glm::rotate(modelmat , glm::radians(euler.y) , glm::vec3(0.f,1.f,0.f));
}

void GameObject::calculateBoundingBox() {
        glm::vec3 minPos = glm::vec3(std::numeric_limits<float>::max());
        glm::vec3 maxPos = glm::vec3(std::numeric_limits<float>::lowest());

        // Calcul des positions extrêmes
        for (glm::vec3 localPos : position) {
            //glm::vec4 worldPos = modelmat * glm::vec4(localPos, 1.0f);
            minPos = glm::min(minPos, glm::vec3(localPos));
            maxPos = glm::max(maxPos, glm::vec3(localPos));
        }

        minBoundingBox_Original = minPos;
        maxBoundingBox_Original = maxPos;

        minBoundingBox_Updated = minPos;
        maxBoundingBox_Updated = maxPos;
}
void GameObject::updateBoundingBox() {
        glm::vec3 minPos = glm::vec3( modelmat * glm::vec4(minBoundingBox_Original,1.0) );
        glm::vec3 maxPos = glm::vec3( modelmat * glm::vec4(maxBoundingBox_Original,1.0) );
        glm::vec3 corners[8] = {
            glm::vec3(minPos.x, minPos.y, minPos.z),
            glm::vec3(maxPos.x, minPos.y, minPos.z),
            glm::vec3(minPos.x, maxPos.y, minPos.z),
            glm::vec3(maxPos.x, maxPos.y, minPos.z),
            glm::vec3(minPos.x, minPos.y, maxPos.z),
            glm::vec3(maxPos.x, minPos.y, maxPos.z),
            glm::vec3(minPos.x, maxPos.y, maxPos.z),
            glm::vec3(maxPos.x, maxPos.y, maxPos.z)
        };

        glm::vec3 newMin = corners[0];
        glm::vec3 newMax = corners[0];

        for (int i = 1; i < 8; ++i) {
            newMin = glm::min(newMin, corners[i]);
            newMax = glm::max(newMax, corners[i]);
        }
        minBoundingBox_Updated = newMin;
        maxBoundingBox_Updated = newMax;
}

bool GameObject::checkCollision(const GameObject& other) {
        // Vérifier la collision entre les boîtes englobantes
        /*
        glm::vec4 maxBBworldPos = modelmat * glm::vec4(maxBoundingBox, 1.0f);
        glm::vec4 minBBworldPos = modelmat * glm::vec4(minBoundingBox, 1.0f);
        glm::mat4 modelmatOther= other.getmodelmat();
        glm::vec4 maxBBworldPosOther = modelmatOther * glm::vec4(other.maxBoundingBox, 1.0f);
        glm::vec4 minBBworldPosOther = modelmatOther * glm::vec4(other.minBoundingBox , 1.0f);
        return (maxBBworldPos[0] >= minBBworldPosOther[0] && minBBworldPos[0] <= maxBBworldPosOther[0]) &&
               (maxBBworldPos[1] >= minBBworldPosOther[1] && minBBworldPos[1] <= maxBBworldPosOther[1]) &&
               (maxBBworldPos[2] >= minBBworldPosOther[2] && minBBworldPos[2] <= maxBBworldPosOther[2]);
           */    
               
        return (maxBoundingBox_Updated[0] >= other.minBoundingBox_Updated[0] && minBoundingBox_Updated[0] <= other.maxBoundingBox_Updated[0]) &&
               (maxBoundingBox_Updated[1] >= other.minBoundingBox_Updated[1] && minBoundingBox_Updated[1] <= other.maxBoundingBox_Updated[1]) &&
               (maxBoundingBox_Updated[2] >= other.minBoundingBox_Updated[2] && minBoundingBox_Updated[2] <= other.maxBoundingBox_Updated[2]);
    }
