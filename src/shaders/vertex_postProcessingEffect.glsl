#version 330 core

layout(location = 0) in vec2 vertexPosition;

out vec2 TexCoords;

void main() {
    gl_Position = vec4(vertexPosition, 0.0, 1.0);
    TexCoords = vertexPosition * 0.5 + 0.5;
}
