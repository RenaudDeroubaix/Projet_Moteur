#version 330 core

// Input vertex data, different for all executions of this shader.
layout(location = 0) in vec3 vertices_position_modelspace;
layout(location = 1) in vec2 uv_coords;

uniform sampler2D height;


uniform mat4 modelmat;
uniform mat4 viewmat;
uniform mat4 projmat;


out vec2 tex_coord;
out float o_height;

//TODO create uniform transformations matrices Model View Projection
// Values that stay constant for the whole mesh.

void main(){
    
    
    mat4 MVP = projmat * viewmat * modelmat;
    tex_coord = uv_coords;
    o_height = texture(height,uv_coords).r * 0.5;
    
        // TODO : Output position of the vertex, in clip space : MVP * position
    gl_Position = MVP * vec4(vec3(vertices_position_modelspace.x , vertices_position_modelspace.y + o_height ,vertices_position_modelspace.z) , 1 );

}

