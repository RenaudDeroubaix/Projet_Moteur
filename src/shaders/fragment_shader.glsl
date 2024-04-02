#version 330 core

uniform vec3 mesh_color;

//uniform sampler2D tex;
//in vec2 tex_coord;

//in float o_height;
// Ouput data
out vec4 color;



void main(){
    color = vec4(mesh_color, 1.0);/* texture(tex, tex_coord);*/
}
