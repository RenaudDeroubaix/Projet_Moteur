#version 330 core

// Input vertex data, different for all executions of this shader.
layout(location = 0) in vec3 vertices_position_modelspace;
layout(location = 1) in vec3 normals;
layout(location = 2) in vec2 uv_coords;
layout(location = 3) in vec3 light_pos;
layout(location = 4) in vec3 light_dir;


uniform mat4 modelmat;
uniform mat4 viewmat;
uniform mat4 projmat;

out vec4 light_dir_worldspace;
out vec4 light_pos_worldspace;
out vec4 position_worldspace;
out vec4 normal_surface;
out vec2 tex_coord;

//TODO create uniform transformations matrices Model View Projection
// Values that stay constant for the whole mesh.

void main(){
    
   
    mat4 MVP = projmat * viewmat * modelmat;
    light_pos_worldspace =  MVP * vec4(light_pos,1.f);
    light_dir_worldspace = MVP * vec4(light_dir,0.f);
    normal_surface =  MVP * vec4(normals , 0.f);
    tex_coord = uv_coords;
    
        // TODO : Output position of the vertex, in clip space : MVP * position
    position_worldspace = MVP * vec4(vertices_position_modelspace , 1.f);
    gl_Position = position_worldspace;

}

