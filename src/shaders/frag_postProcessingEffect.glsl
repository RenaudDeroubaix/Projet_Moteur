#version 330 core

in vec2 TexCoords;
out vec4 FragColor;

uniform sampler2D screenTexture;
uniform vec3 haloColor;

void main() {
    vec2 texelSize = 1.0 / textureSize(screenTexture, 0);
    vec3 color = texture(screenTexture, TexCoords).rgb;

    // Détection des bords en comparant les couleurs des pixels adjacents
    vec3 leftColor = texture(screenTexture, TexCoords - vec2(texelSize.x, 0)).rgb;
    vec3 rightColor = texture(screenTexture, TexCoords + vec2(texelSize.x, 0)).rgb;
    vec3 topColor = texture(screenTexture, TexCoords - vec2(0, texelSize.y)).rgb;
    vec3 bottomColor = texture(screenTexture, TexCoords + vec2(0, texelSize.y)).rgb;

    bool isEdge = (color != leftColor) || (color != rightColor) || (color != topColor) || (color != bottomColor);

    // Appliquer l'effet de halo uniquement aux pixels qui sont des bords
    vec3 finalColor = isEdge ? (color + haloColor) : color;

    FragColor = vec4(finalColor, 1.0);
    
}
