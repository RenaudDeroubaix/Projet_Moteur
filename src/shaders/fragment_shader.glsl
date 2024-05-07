#version 330 core

uniform vec3 mesh_color;
uniform sampler2D tex;
uniform vec3 pos_camera_worldspace;

uniform int numberOfLight;
uniform vec3 light_pos[20];
uniform vec3 light_col[20];

uniform float shininess;

in vec4 o_position_screenspace;
in vec4 o_position_worldspace;
in vec4 o_normal_worldspace;
in vec2 o_tex_coord;
// Ouput data
out vec4 o_color;

void main(){
    float specular=0.0;
    float diffuse=0.0;
    float ambiante =0.1;
    vec3 radiance = vec3(0.0);
    vec4 color_tex = texture(tex, o_tex_coord); 
    
    for (int i = 0 ; i < numberOfLight; i++){
    
        vec3 L = normalize(( light_pos[i].xyz -  o_position_worldspace.xyz )); //OK
        diffuse = max(dot(o_normal_worldspace.xyz, L) , 0.f); //
    
        if (diffuse > 0){
            vec3 R = normalize(reflect( -L , o_normal_worldspace.xyz)); 
            vec3 vue =  normalize((-  o_normal_worldspace.xyz));
            float specAngle = max(dot(R, vue), 0.0);
            specular = pow(specAngle, shininess);
        }   
        radiance += light_col[i] *  (diffuse  + specular + ambiante);
    }
    o_color =vec4(mesh_color * color_tex.xyz * radiance  , 1.f);
}

