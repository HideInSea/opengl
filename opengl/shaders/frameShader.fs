#version 450 core

out vec4 FragColor;

in vec2 TexCoord;
in vec3 Normal;
in vec3 fragPos;

uniform vec3 objectColor;
uniform float opacity;

uniform vec3 viewPos;

//材质
struct Material {
    sampler2D diffuse;
    sampler2D specular;
    float shininess;
}; 

uniform Material material;

//方向光
struct DirectLight {
    vec3 direction;

    vec3 ambient;
    vec3 diffuse;
    vec3 specular;
};

uniform DirectLight directLight;

//点光源
struct PointLight {
    vec3 position;

    float constant;
    float linear;
    float quadratic;

    vec3 ambient;
    vec3 diffuse;
    vec3 specular;
};  
#define NR_POINT_LIGHTS 4
uniform PointLight pointLight;

//聚光
struct SpotLight {
    vec3  position;
    vec3  direction;
    float cutOff;
	float outerCutOff;

    vec3 ambient;
    vec3 diffuse;
    vec3 specular;

	float constant;
    float linear;
    float quadratic;
};

uniform SpotLight spotLight;

vec3 CalcDirLight(DirectLight light, vec3 normal, vec3 viewDir);
vec3 CalcPointLight(PointLight light, vec3 normal, vec3 fragPos, vec3 viewDir);
vec3 CalcSpotLight(SpotLight light, vec3 normal, vec3 fragPos, vec3 viewDir);

void main()
{
    FragColor = vec4(0.0f,0.0f,1.0f,1.0f);
}

//计算方向光
vec3 CalcDirLight(DirectLight light, vec3 normal, vec3 viewDir){
	vec3 diffColor=vec3(texture(material.diffuse, TexCoord));
	vec3 lightDir = normalize(-light.direction);
	//环境光
    vec3 ambient =  diffColor* light.ambient;
	//漫反射
	float diff = max(dot(normal, lightDir), 0.0);
	vec3 diffuse = diffColor*diff* light.diffuse;

	//镜面光
	vec3 reflectDir = reflect(-lightDir, normal);
	float spec = pow(max(dot(viewDir, reflectDir), 0.0), material.shininess);
	vec3 specular = vec3(texture(material.specular, TexCoord)) * spec * light.specular;

	return (ambient+diffuse+specular);
}

//计算点光源
vec3 CalcPointLight(PointLight light, vec3 normal, vec3 fragPos, vec3 viewDir){
	vec3 lightDir = normalize(light.position - fragPos);
    // 漫反射着色
    float diff = max(dot(normal, lightDir), 0.0);
    // 镜面光着色
    vec3 reflectDir = reflect(-lightDir, normal);
    float spec = pow(max(dot(viewDir, reflectDir), 0.0), material.shininess);
    // 衰减
    float distance    = length(light.position - fragPos);
    float attenuation = 1.0 / (light.constant + light.linear * distance + 
                 light.quadratic * (distance * distance));    
    // 合并结果
    vec3 ambient  = light.ambient  * vec3(texture(material.diffuse, TexCoord));
    vec3 diffuse  = light.diffuse  * diff * vec3(texture(material.diffuse, TexCoord));
    vec3 specular = light.specular * spec * vec3(texture(material.specular, TexCoord));
    ambient  *= attenuation;
    diffuse  *= attenuation;
    specular *= attenuation;
    return (ambient + diffuse + specular);
}

//计算聚光
vec3 CalcSpotLight(SpotLight light, vec3 normal, vec3 fragPos, vec3 viewDir){
	vec3 lightDir = normalize(light.position-fragPos);

	//环境光
    vec3 ambient = vec3(texture(material.diffuse, TexCoord)) * light.ambient;

     
		// 执行光照计算
		float distance    = length(light.position - fragPos);
		float attenuation = 1.0 / (light.constant + light.linear * distance + 
						light.quadratic * (distance * distance));

		//漫反射

		float diff = max(dot(normal, lightDir), 0.0);
		vec3 diffuse = vec3(texture(material.diffuse, TexCoord))*diff* light.diffuse;

		//镜面光
		vec3 reflectDir = reflect(-lightDir, normal);
		float spec = pow(max(dot(viewDir, reflectDir), 0.0), material.shininess);
		vec3 specular = vec3(texture(material.specular, TexCoord)) * spec * light.specular;

		float theta = dot(lightDir, normalize(-light.direction));
		float epsilon   = light.cutOff - light.outerCutOff;
		float intensity = clamp((theta - light.outerCutOff) / epsilon, 0.0, 1.0);
		// 将不对环境光做出影响，让它总是能有一点光
		diffuse  *= intensity;
		specular *= intensity;

		diffuse*=attenuation;
		specular*=attenuation;
		
		return (ambient+diffuse+specular);
}