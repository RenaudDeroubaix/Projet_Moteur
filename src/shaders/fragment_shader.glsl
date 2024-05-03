#version 330 core

uniform vec3 light_color;
uniform vec3 mesh_color;
uniform sampler2D tex;

uniform float shininess;
uniform vec3 pos_camera;
in vec2 tex_coord;
in vec4 light_pos_worldspace;
in vec4 normal_surface;
in vec4 position_worldspace;
// Ouput data
out vec4 o_color;

void main(){

    vec3 L = normalize((light_pos_worldspace.xyz - position_worldspace.xyz));
    vec3 vue =  normalize((pos_camera - position_worldspace.xyz));
    vec3 halfwayDir = normalize(L + vue);
    
    vec4 color_tex = texture(tex, tex_coord); 
    
    vec3 diffuse = color_tex.xyz * max(dot(L ,  normal_surface.xyz), 0.0) ;
    vec3 specular =  color_tex.xyz * pow(max(dot(halfwayDir  , vue), 0.0) , shininess) ;
    

    
    
    o_color = vec4(mesh_color.x * color_tex.x , mesh_color.y * color_tex.y ,mesh_color.z * color_tex.z ,1.0) ;
}
