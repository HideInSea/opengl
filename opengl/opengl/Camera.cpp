#include "Camera.h"
#include <glm/gtc/matrix_transform.hpp>

Camera::Camera() {
	this->target = glm::vec3(0.0f, 0.0f, 0.0f);
}

Camera::Camera(glm::vec3 position, glm::vec3 target) :Node(position) {
	this->target = target;
}

Camera::~Camera()
{
}

void Camera::render(Node* node)
{

}

void Camera::lockAt(glm::vec3 target)
{
	this->view = glm::lookAt(this->position, this->target, glm::vec3(0.0f, 1.0f, 0.0f));
}
