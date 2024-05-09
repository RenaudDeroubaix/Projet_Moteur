#version 330 core

uniform vec3 mesh_color;
uniform sampler2D tex;
uniform vec3 pos_camera_worldspace;

uniform int numberOfLight;
uniform vec3 light_pos[20];
uniform vec3 light_col[20];
uniform vec3 light_dir[20];
uniform int is_directional[20];
uniform float radius[20];
uniform int is_on[20];


uniform float shininess;

in vec4 o_position_screenspace;
in vec4 o_position_worldspace;
in vec4 o_normal_worldspace;
in vec2 o_tex_coord;
// Ouput data
out vec4 o_color;

void main(){
    
    float ambiante =0.05;
    vec3 radiance = vec3(0.0);
    vec4 color_tex = texture(tex, o_tex_coord); 
    
    vec3 L;
    for (int i = 0 ; i < numberOfLight; i++){
    if (is_on[i] == 1 ){
        float specular=0.0;
        float diffuse=0.0;
        vec3 hwd , vue ;
        float anglespec;
        if (is_directional[i] == 1)
        {   
            L =   - normalize (light_dir[i]) ;
            diffuse =  max( dot(o_normal_worldspace.xyz, L) , 0.f)  ;
                if ( diffuse > 0){
                    vue = normalize((-o_position_screenspace.xyz));
                    hwd = normalize( L  + vue);
                    anglespec = max(dot( hwd , o_normal_worldspace.xyz), 0);
                    specular =  pow(anglespec, shininess) * 0.5 ;
                }
        } 
        else 
        {
            L = (  light_pos[i].xyz - o_position_worldspace.xyz );
            float distL = smoothstep(0, 1 ,  length(L)/radius[i]);
            L = normalize(L);
            if (distL < 1) 
            {  
                diffuse = smoothstep(distL  , distL+1  , max(dot(o_normal_worldspace.xyz, L), 0.f) )  + smoothstep ( distL  , distL+1 ,  max(dot(o_normal_worldspace.xyz, - normalize (light_dir[i]) ), 0.f) )  ;
                
                if ( diffuse > 0){
                    vue = normalize((-o_position_screenspace.xyz));
                    hwd = normalize( L  + vue);
                    anglespec =  smoothstep(distL + 0.8 , distL+1 , max(dot( hwd , o_normal_worldspace.xyz), 0)) ;
                    specular =  pow(anglespec, shininess) ;
                }
            }
                     
        }
        radiance += light_col[i] *(diffuse + specular + ambiante ); 
        }
    }
    
    o_color =vec4(mesh_color* color_tex.xyz * radiance  , 1.f);
}

