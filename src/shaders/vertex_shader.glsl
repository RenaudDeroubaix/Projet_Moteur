#version 330 core

// Input vertex data, different for all executions of this shader.
layout(location = 0) in vec3 vertices_position_modelspace;
layout(location = 1) in vec2 uv_coords;


uniform mat4 modelmat;
uniform mat4 viewmat;
uniform mat4 projmat;

out vec2 tex_coord;

//TODO create uniform transformations matrices Model View Projection
// Values that stay constant for the whole mesh.

void main(){
    
    
    mat4 MVP = projmat * viewmat * modelmat;
    tex_coord = uv_coords;
    
        // TODO : Output position of the vertex, in clip space : MVP * position
    gl_Position = MVP * vec4(vertices_position_modelspace , 1 );

}

