#pragma once
#include "Node3D.h"
#include <GLFW\glfw3.h>

class Camera :
	public Node3D
{
public:
	Camera();
	~Camera();
	void processInput(GLFWwindow* window);
	void lockAt(glm::vec3 target);
	void mouse_callback(GLFWwindow* window, double xpos, double ypos);
    virtual void scroll_callback(GLFWwindow* window, double xoffset, double yoffset);
	void mouse_button_callback(GLFWwindow* window, int button, int action, int mods);
	void updateView();
	glm::mat4 view;
	glm::mat4 projection;

	glm::vec3 target;//������Ĺ۲��
	glm::vec3 cameraUp;
	glm::vec3 cameraDir;
	glm::vec3 cameraFront;

	bool firstMouse;
	double lastX;
	double lastY;
	float pitch;
	float yaw;
	float fov;
	bool isPressed;
};

