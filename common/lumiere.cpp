void Plan::settexture( const std::string & path , GLuint textureIndex, const std::string & name_in_shader) 
{}
void Plan::initobject() 
{}
void Plan::drawobject() 

{
    glUniformMatrix3fv(glGetUniformLocation(renderer.programID,"light_pos"), 1 , GL_FALSE, &(this->getpos())[0]);
    glUniformMatrix3fv(glGetUniformLocation(renderer.programID,"light_color"), 1 , GL_FALSE, &(this->getpos())[0]);
    
}

void Plan::deleteobject() 
{delete this;}

