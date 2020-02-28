#version 450 core

out vec4 FragColor;

in vec2 TexCoord;
uniform sampler2D ourTexture;
uniform vec3 color;

uniform float opacity;

void main()
{
    FragColor = vec4(color,opacity)*texture(ourTexture, TexCoord);
}