#pragma once
#include "Camera.h"
#include "Shader.h"
class Camera2D :
	public Camera
{
public:
	Camera2D();
	Camera2D(glm::vec3 position,glm::vec3 target,float width,float height);
	~Camera2D();

	void render(Node* node);
	void setSpriteShader(Shader spriteShader) { this->spriteShader = spriteShader; };
	glm::mat4 projection;

	float cameraWidth;
	float cameraHeight;
	Shader  spriteShader;
};

