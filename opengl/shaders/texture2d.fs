#version 450 core

out vec4 FragColor;

in vec2 TexCoord;

uniform sampler2D ourTexture;
uniform vec3 objectColor;
uniform vec3 lightColor;
uniform float opacity;

void main()
{
	vec3 result=objectColor*lightColor;
    FragColor = vec4(result,opacity)*texture(ourTexture, TexCoord);
}