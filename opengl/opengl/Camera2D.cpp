#include "Camera2D.h"
#include <glad\glad.h>
#include<glm/gtc/matrix_transform.hpp>
#include "ResourceManager.h"
extern const GLuint SCREEN_WIDTH;
extern const GLuint SCREEN_HEIGHT;
Camera2D::Camera2D()
{	
	this->cameraWidth = SCREEN_WIDTH;
	this->cameraHeight = SCREEN_HEIGHT;
	this->position = glm::vec3(0.0f, 0.0f,1.0f);
	this->lockAt(this->target);
	this->projection = glm::ortho(0.0f, this->cameraWidth, 0.0f, this->cameraHeight, -0.1f, 100.0f);
}

Camera2D::Camera2D(glm::vec3 position, glm::vec3 target,float width=0,float height=0):Camera(position,target)
{
	this->cameraWidth = width || SCREEN_WIDTH;
	this->cameraHeight = height || SCREEN_HEIGHT;
	this->projection = glm::ortho(0.0f, this->cameraWidth,0.0f, this->cameraHeight, -0.1f, 100.0f);
}

Camera2D::~Camera2D()
{
}

void Camera2D::render(Node* node)
{
	this->spriteShader.Use();
	glm::mat4 tranform = this->projection  *this->view* node->getModelMatrix();
	this->spriteShader.SetMatrix4("transform",tranform,GL_FALSE);
	this->spriteShader.SetVector3f("color",node->color);
	this->spriteShader.SetFloat("opacity", node->opacity);
	node->draw();
}

