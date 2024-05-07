#version 330 core

// Input vertex data, different for all executions of this shader.
layout(location = 0) in vec3 vertices_position_modelspace;
layout(location = 1) in vec3 normals;
layout(location = 2) in vec2 uv_coords;


//layout(location = 4) in vec3 light_dir;

uniform mat4 modelmat;
uniform mat4 viewmat;
uniform mat4 projmat;

out vec4 o_position_worldspace;
out vec4 o_position_screenspace;
out vec4 o_normal_worldspace;
out vec2 o_tex_coord;

//TODO create uniform transformations matrices Model View Projection
// Values that stay constant for the whole mesh.

void main(){

    mat4 MVP = projmat * viewmat * modelmat ;
    gl_Position = MVP * vec4(vertices_position_modelspace , 1.f);
    o_position_screenspace = MVP * vec4(vertices_position_modelspace , 1.f);
    o_position_worldspace  =  modelmat * vec4(vertices_position_modelspace , 1.f);
    //o_light_color = light_color;
    o_normal_worldspace =  normalize( modelmat *vec4(normals, 0.f));
    o_tex_coord = uv_coords;
    
    // TODO : Output position of the vertex, in clip space : MVP * position
    
    

}

