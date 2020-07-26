#version 450 core

out vec4 FragColor;

in vec2 TexCoord;
in vec3 Normal;
in vec3 fragPos;

uniform vec3 objectColor;

uniform vec3 viewPos;
uniform float opacity;

struct Material {
    sampler2D texture_diffuse1;
    sampler2D texture_specular1;
    float shininess;
}; 

uniform Material material;


void main()
{
   FragColor = texture(material.texture_diffuse1, TexCoord);
   //FragColor = vec4(1.0f);
}