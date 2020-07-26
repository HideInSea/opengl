#version 450 core

out vec4 FragColor;

in vec2 TexCoord;
in vec3 Normal;
in vec3 fragPos;


uniform vec3 viewPos;


struct Material {
    sampler2D texture_diffuse1;
    sampler2D texture_specular1;
    float shininess;
}; 

uniform Material material;


struct Light {
    vec3 direction;

    vec3 ambient;
    vec3 diffuse;
    vec3 specular;
};

uniform Light light;

void main()
{
	//环境光
    vec3 ambient = vec3(texture(material.texture_diffuse1, TexCoord)) * light.ambient;

	//漫反射
	vec3 norm = normalize(Normal);
	vec3 lightDir = normalize(-light.direction);
	float diff = max(dot(norm, lightDir), 0.0);
	vec3 diffuse = vec3(texture(material.texture_diffuse1, TexCoord))*diff* light.diffuse;

	//镜面光
	vec3 viewDir = normalize(viewPos - fragPos);
	vec3 reflectDir = reflect(-lightDir, norm);
	float spec = pow(max(dot(viewDir, reflectDir), 0.0),32.0f);
	vec3 specular = vec3(texture(material.texture_specular1, TexCoord)) * spec * light.specular;

	vec3 resultColor=(ambient+diffuse+specular);
    FragColor = vec4(resultColor,1.0f);
}