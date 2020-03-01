#version 450 core

out vec4 FragColor;

in vec2 TexCoord;
in vec3 Normal;
in vec3 fragPos;

uniform sampler2D ourTexture;
uniform vec3 color;

uniform vec3 lightColor;
uniform vec3 aLightPos;

uniform float opacity;

void main()
{
	float ambientStrength = 0.1;
    vec3 ambient = ambientStrength * lightColor;

	vec3 norm = normalize(Normal);
	vec3 lightDir = normalize(aLightPos - fragPos);
	float diff = max(dot(norm, lightDir), 0.0);
	vec3 diffuse = diff * lightColor;

	vec3 resultColor=(ambient+diffuse)*color;
    FragColor = vec4(1.0f);
}