#version 330 core


uniform sampler2D grass_tex;
uniform sampler2D rock_tex;
uniform sampler2D snow_tex;


in vec2 tex_coord;

in float o_height;
// Ouput data
out vec4 color;



void main(){
        
        float grassThreshold = 0.2;
        float rockThreshold = 0.35;

        // smooth transition
        float grassFactor = smoothstep(grassThreshold, grassThreshold + 0.1, o_height);
        float rockFactor = smoothstep(rockThreshold, rockThreshold + 0.1, o_height);

        // mix texture
        vec4 grassColor = texture(grass_tex, tex_coord) * (1.0 - rockFactor) * (1.0 - grassFactor);
        vec4 rockColor = texture(rock_tex, tex_coord) * (1.0 - rockFactor) * grassFactor;
        vec4 snowColor = texture(snow_tex, tex_coord) * rockFactor;

        // Combine the colors
        color = grassColor + rockColor + snowColor;
        
        
       /*mix(grass , rock , height);*/

}
