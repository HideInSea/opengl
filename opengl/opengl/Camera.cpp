#include "Camera.h"
#include <glm/gtc/matrix_transform.hpp>



Camera::Camera(){
	this->up = glm::vec3(0);
	this->right = glm::vec3(0);
	this->cameraUp = glm::vec3(0.0f, 1.0f, 0.0f);
	this->cameraDir = glm::vec3(0);
	this->cameraFront = glm::vec3(0);
	this->lastX = 400;
	this->lastY = 300;
	this->firstMouse = true;
	this->yaw = -90.0f;
	this->pitch = 0;
	this->fov = 45.0f;
	this->isPressed = false;
}

Camera::~Camera()
{
}

void Camera::processInput(GLFWwindow* window)
{
	float cameraSpeed = 0.3f; // adjust accordingly
	if (glfwGetKey(window, GLFW_KEY_Q) == GLFW_PRESS)
		this->position -= cameraSpeed * glm::normalize(cameraDir),this->updateView();
	if (glfwGetKey(window, GLFW_KEY_E) == GLFW_PRESS)
		this->position += cameraSpeed * glm::normalize(cameraDir), this->updateView();
	if (glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS)
		this->position -= this->cameraRight * cameraSpeed, this->updateView();
	if (glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS)
		this->position += this->cameraRight * cameraSpeed, this->updateView();
	if (glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS)
		this->position += this->cameraUp * cameraSpeed, this->updateView();
	if (glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS)
		this->position -= this->cameraUp * cameraSpeed, this->updateView();
	


	//if (glfwGetKey(window, GLFW_KEY_UP) == GLFW_PRESS)
	//	this->position += cameraSpeed * this->up, this->lockAt(target);
	//if (glfwGetKey(window, GLFW_KEY_DOWN) == GLFW_PRESS)
	//	this->position -= cameraSpeed * this->up, this->lockAt(target);
	//if (glfwGetKey(window, GLFW_KEY_LEFT) == GLFW_PRESS)
	//	this->position += glm::normalize(glm::cross(cameraFront, cameraUp)) * cameraSpeed, this->lockAt(target);
	//if (glfwGetKey(window, GLFW_KEY_RIGHT) == GLFW_PRESS)
	//	this->position -= glm::normalize(glm::cross(cameraFront, cameraUp)) * cameraSpeed, this->lockAt(target);
}


void Camera::lockAt(glm::vec3 target)
{
	this->target = target;
	this->cameraDir = this->position - this->target;
	this->cameraRight = glm::normalize(glm::cross(glm::vec3(0,1.0f,0),this->cameraDir));
	this->cameraUp = glm::normalize(glm::cross(this->cameraDir,this->cameraRight));
	this->view = glm::lookAt(this->position,this->target,glm::vec3(0,1.0f,0));
}

void Camera::mouse_callback(GLFWwindow* window, double xpos, double ypos)
{
	if (!isPressed)return;
	if (firstMouse)
	{
		lastX = xpos;
		lastY = ypos;
		firstMouse = false;
	}

	float xoffset = xpos - lastX;
	float yoffset = lastY - ypos;
	lastX = xpos;
	lastY = ypos;

	float sensitivity = 0.05;
	xoffset *= sensitivity;
	yoffset *= sensitivity;

	yaw += xoffset;
	pitch += yoffset;

	if (pitch > 89.0f)
		pitch = 89.0f;
	if (pitch < -89.0f)
		pitch = -89.0f;

	glm::vec3 front;
	front.x = cos(glm::radians(yaw)) * cos(glm::radians(pitch));
	front.y = sin(glm::radians(pitch));
	front.z = sin(glm::radians(yaw)) * cos(glm::radians(pitch));
	this->cameraDir = -glm::normalize(front);
	this->updateView();
}

void Camera::scroll_callback(GLFWwindow* window, double xoffset, double yoffset)
{
}

void Camera::mouse_button_callback(GLFWwindow* window, int button, int action, int mods)
{
	if (action == GLFW_PRESS)isPressed = true,firstMouse=true;
	else if (action == GLFW_RELEASE)isPressed = false;

}

void Camera::updateView()
{
	this->target = this->position - this->cameraDir;
	this->view = glm::lookAt(this->position,this->target, glm::vec3(0,1.0f,0));
}
