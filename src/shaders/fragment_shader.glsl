#version 330 core

uniform vec3 mesh_color;
uniform sampler2D tex;
in vec2 tex_coord;

// Ouput data
out vec4 o_color;



void main(){
    vec4 color_tex = texture(tex, tex_coord);
    
    o_color = vec4(mesh_color.x * color_tex.x , mesh_color.y * color_tex.y ,mesh_color.z * color_tex.z ,1.0) ;
}
