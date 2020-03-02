#version 450 core

out vec4 FragColor;

in vec2 TexCoord;
uniform sampler2D ourTexture;
uniform vec3 objectColor;

uniform float opacity;

void main()
{
    FragColor = vec4(objectColor,opacity)*texture(ourTexture, TexCoord);
}