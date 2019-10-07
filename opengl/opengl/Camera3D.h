#pragma once
#include "Camera.h"
#include "Shader.h"

class Camera3D :
	public Camera
{
public:
	void render(Node * node);

	Camera3D(glm::vec3 position,glm::vec3 target,float radian,float whRate);
	
	float whRate;
	float radian;
	Shader shader;
	glm::vec3 lightColor;
	glm::vec3 lightPos;

};

