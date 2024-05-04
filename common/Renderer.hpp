#pragma once
#include "common/utils.hpp"
#include "common/texture.hpp"
class Renderer{
public:
    GLuint VertexArrayID;
    GLuint vertexbuffer;
    GLuint texbuffer;
    GLuint elementbuffer;
    GLuint programID;
    std::vector<GLuint> tex_id_list;
    std::vector<std::string> names_in_shader;
    
    
    size_t indicesize;
    
    Renderer(){}
    ~Renderer(){}
    
    void genbuffer(std::vector<glm::vec3> & position , std::vector<glm::vec2> & tex_coords , std::vector<unsigned short> & indices) ;
    void genbufferDynamic(std::vector<glm::vec3> & position , std::vector<glm::vec2> & tex_coords , std::vector<unsigned short> & indices) ;
    void draw() ;
    void deletebuffers() ;
    void stocktexture(const std::string & path , GLuint textureIndex, const std::string & name_in_shader) ;
    void loadtextures();
    
};
