#include "Camera3D.h"
#include <glm\gtc\matrix_transform.hpp>

void Camera3D::render(Node* node)
{
	this->shader.Use();
	glm::mat4 tranform = this->projection * this->view * node->getModelMatrix();
	this->shader.SetMatrix4("transform", tranform, GL_FALSE);
	this->shader.SetVector3f("objectColor", node->color);
	this->shader.SetVector3f("lightColor", this->lightColor);
	this->shader.SetVector3f("lightPos",this->lightPos);
	this->shader.SetVector3f("viewPos",this->position);

	this->shader.SetFloat("opacity", node->opacity);
	node->draw();
}

Camera3D::Camera3D(glm::vec3 position, glm::vec3 target, float radian, float whRate):
	Camera(position,target)
{
	this->lockAt(this->target);
	this->projection = glm::perspective(glm::radians(45.0f), whRate, 0.1f, 100.0f);
	this->lightColor = glm::vec3(1.0f);
}
