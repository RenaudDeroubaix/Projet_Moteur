#pragma once
#include "common/utils.hpp"
#include "common/shader.hpp"
#include "common/GameObject.hpp"

/*Include AssImp
#include <assimp/Importer.hpp>      // C++ importer interface
#include <assimp/scene.h>           // Output data structure
#include <assimp/postprocess.h> */ 


class Mesh : public GameObject{
private:
    
    glm::vec3 pos;
    glm::mat4 modelmat = glm::mat4(1.f);
    
public:
    bool loadOFF(const std::string & filename);
    void computeNormals();
    void computeVerticesNormals(std::vector<glm::vec3>& triangle_normals);
    std::vector<glm::vec3> computeTrianglesNormals();
    Mesh(const std::string & filename):GameObject()
    {
        loadOFF(filename);
    } 
    ~Mesh(){}
    
    //bool loadAssImp(const char * path);
    
    
    void initobject() override;
    void drawobject() override;
    void deleteobject() override;
    void settexture(const std::string & path , GLuint textureIndex, const std::string & name_in_shader) override;
                  
};
