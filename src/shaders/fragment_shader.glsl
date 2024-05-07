#version 330 core

uniform vec3 mesh_color;
uniform sampler2D tex;
uniform vec3 pos_camera_worldspace;

uniform float shininess;

in vec4 o_light_pos;
in vec3 o_light_color;
in vec4 o_position_screenspace;

in vec4 o_position_worldspace;
in vec4 o_normal_worldspace;
in vec2 o_tex_coord;
// Ouput data
out vec4 o_color;

void main(){
    float specular=0.0;
    float diffuse=0.0;
    float ambiante =0.3;

    vec3 L = normalize(( o_light_pos.xyz -  o_position_worldspace.xyz )); //OK
    diffuse = max(dot(o_normal_worldspace.xyz, - L) , 0.f); //
    if (diffuse > 0){
        vec3 R = normalize(reflect(-L , o_normal_worldspace.xyz)); 
        vec3 vue =  normalize((/*pos_camera_worldspace */ -  o_position_screenspace.xyz));
        float specAngle = max(dot(R, vue), 0.0);
        specular = pow(specAngle, shininess);
    }

    vec4 color_tex = texture(tex, o_tex_coord); 
    
    vec3 colordiffuse = vec3(diffuse) * 0.5/* * (o_light_color)*/;
    vec3 colorspecular = vec3(specular) * 0.5/* * (o_light_color)*/;
   // + specular)  /*+ vec3(ambiante) +*//* + vec3(diffuse) + vec3(specular)*/ ;

    o_color =vec4(mesh_color * color_tex.xyz *( colordiffuse + colorspecular/* + ambiante*/)  , 1.f);
}

