#version 450 core

out vec4 FragColor;

in vec2 TexCoord;
in vec3 Normal;
in vec3 fragPos;

uniform vec3 objectColor;

uniform vec3 viewPos;
uniform float opacity;

struct Material {
    sampler2D diffuse;
    sampler2D specular;
    float shininess;
}; 

uniform Material material;


struct Light {
    vec3 position;

    vec3 ambient;
    vec3 diffuse;
    vec3 specular;

	float constant;
    float linear;
    float quadratic;
};

uniform Light light;

void main()
{

	float distance    = length(light.position - fragPos);
	float attenuation = 1.0 / (light.constant + light.linear * distance + 
					light.quadratic * (distance * distance));

	//环境光
    vec3 ambient = vec3(texture(material.diffuse, TexCoord)) * light.ambient;

	//漫反射
	vec3 norm = normalize(Normal);
	vec3 lightDir = normalize(light.position-fragPos);
	float diff = max(dot(norm, lightDir), 0.0);
	vec3 diffuse = vec3(texture(material.diffuse, TexCoord))*diff* light.diffuse;


	//镜面光
	vec3 viewDir = normalize(viewPos - fragPos);
	vec3 reflectDir = reflect(-lightDir, norm);
	float spec = pow(max(dot(viewDir, reflectDir), 0.0), material.shininess);
	vec3 specular = vec3(texture(material.specular, TexCoord)) * spec * light.specular;

	ambient*=attenuation;
	diffuse*=attenuation;
	specular*=attenuation;

	vec3 resultColor=(ambient+diffuse+specular);
    FragColor = vec4(resultColor,opacity);
}