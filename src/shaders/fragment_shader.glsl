#version 330 core

uniform vec3 light_color;
uniform vec3 mesh_color;
uniform sampler2D tex;

uniform float shininess;
uniform vec3 pos_camera;

in vec2 tex_coord;
in vec4 light_dir_worldspace;
in vec4 light_pos_worldspace;
in vec4 normal_surface;
in vec4 position_worldspace;
// Ouput data
out vec4 o_color;

void main(){
    float specular=0.0;
    float diffuse=0.0;
    float ambiante =0.1;

    vec3 L = normalize((light_pos_worldspace.xyz - position_worldspace.xyz )); //OK
    diffuse = max(dot(normal_surface.xyz, L), 0.0); //

    vec3 R = reflect(-L , normal_surface.xyz); 
    vec3 vue =  normalize(- position_worldspace.xyz );
    float specAngle = max(dot(R, vue), 0.0);
    specular = pow(specAngle, shininess);

    vec4 color_tex = texture(tex, tex_coord); 
    
    vec3 color = vec3(ambiante) + vec3(diffuse) + vec3(specular) ;

    o_color = vec4(color  , 1.f);
}

