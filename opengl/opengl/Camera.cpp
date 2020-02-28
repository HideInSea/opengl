#include "Camera.h"
#include <glm/gtc/matrix_transform.hpp>



Camera::Camera(){
	this->cameraUp = glm::vec3(0.0f, 1.0f, 0.0f);
	this->cameraDir = glm::vec3(0);
}

Camera::~Camera()
{
}

void Camera::processInput(GLFWwindow* window)
{
	float cameraSpeed = 0.05f; // adjust accordingly
	if (glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS)
		this->position += cameraSpeed * cameraDir,this->lockAt(this->target);
	if (glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS)
		this->position -= cameraSpeed * cameraDir, this->lockAt(this->target);
	if (glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS)
		this->position += glm::normalize(glm::cross(cameraDir, cameraUp)) * cameraSpeed, this->lockAt(this->target);
	if (glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS)
		this->position -= glm::normalize(glm::cross(cameraDir, cameraUp)) * cameraSpeed, this->lockAt(this->target);
}


void Camera::lockAt(glm::vec3 target)
{
	this->cameraDir = glm::normalize(this->position - this->target);
	this->view = glm::lookAt(this->position, this->target,this->cameraUp);
}
