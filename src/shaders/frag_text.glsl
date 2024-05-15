#version 330 core
in vec2 TexCoords;
out vec4 color;
uniform int renderMode; // 0 =texture 1= pas texture
uniform sampler2D text;
uniform vec3 textColor;
void main()
{
    if (renderMode == 0) {
        // Render text
        vec4 sampled = vec4(1.0, 1.0, 1.0, texture(text, TexCoords).r);
        color = vec4(textColor, 1.0) * sampled;
    } else {
        // Render square
        color = vec4(textColor, 1.0);
    }
}