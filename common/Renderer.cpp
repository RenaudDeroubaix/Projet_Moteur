#include "Renderer.hpp"

void Renderer::genbuffer(std::vector<glm::vec3> & position , std::vector<glm::vec2> & tex_coords , std::vector<unsigned short> & indices)  
{
    indicesize = indices.size();
    
    glGenVertexArrays(1, &VertexArrayID);
    glBindVertexArray(VertexArrayID);
    
    glGenBuffers(1, &vertexbuffer);
    glBindBuffer(GL_ARRAY_BUFFER, vertexbuffer);
    glBufferData(GL_ARRAY_BUFFER, position.size() * sizeof(glm::vec3), &(position)[0], GL_STATIC_DRAW);
    
    glGenBuffers(1, &heightbuffer);
    glBindBuffer(GL_ARRAY_BUFFER, heightbuffer);
    glBufferData(GL_ARRAY_BUFFER, tex_coords.size() * sizeof(glm::vec2), &(tex_coords)[0], GL_STATIC_DRAW);
    // Generate a buffer for the indices as well
    glGenBuffers(1, &elementbuffer);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, elementbuffer);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, indices.size() * sizeof(unsigned short), &(indices)[0] , GL_STATIC_DRAW);
}
void Renderer::draw() 
{
    // 1rst attribute buffer : vertices
    //glUseProgram(programID);
    glEnableVertexAttribArray(0);
    glBindBuffer(GL_ARRAY_BUFFER, vertexbuffer);
    glVertexAttribPointer(
        0,                  // attribute
        3,                  // size
        GL_FLOAT,           // type
        GL_FALSE,           // normalized?
        0,// stride
        (void*)0            // array buffer offset
    );
    
    glEnableVertexAttribArray(1);
    glBindBuffer(GL_ARRAY_BUFFER, heightbuffer);
    glVertexAttribPointer(
        1,                  // attribute
        2,                  // size
        GL_FLOAT,           // type
        GL_FALSE,           // normalized?
        0,                     // stride
        (void*)0            // array buffer offset
    );
    // Index buffer
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, elementbuffer);
    // Draw the triangles !
    glDrawElements(
        GL_TRIANGLES,      // mode
        indicesize,    // count
        GL_UNSIGNED_SHORT, // type
        (void*)0           // element array buffer offset
    );
    
    glDisableVertexAttribArray(0);
    glDisableVertexAttribArray(1);
    
    
}

void Renderer::deletebuffers() 
{
    glDeleteBuffers(1, &vertexbuffer);
    glDeleteBuffers(1, &heightbuffer);
    glDeleteBuffers(1, &elementbuffer);
    glDeleteVertexArrays(1, &VertexArrayID);
}

void Renderer::stocktexture(const std::string & path , GLuint textureIndex ,  const std::string & name_in_shader) 
{
    tex_id_list.push_back(loadTexture2DFromFilePath(path));
    names_in_shader.push_back(name_in_shader);
}
void Renderer::loadtextures() 
{
    
    for (int i = 0 ; i<tex_id_list.size() ; i++ ){
        glActiveTexture(GL_TEXTURE0 + tex_id_list[i]);
        glBindTexture(GL_TEXTURE_2D, tex_id_list[i]);
        glUniform1i(glGetUniformLocation(programID, names_in_shader[i].c_str()),tex_id_list[i]);
    }
    
}


