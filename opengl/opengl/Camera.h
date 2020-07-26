#pragma once
#include "Node.h"
#include <GLFW\glfw3.h>

class Camera :
	public Node
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

	glm::vec3 target;//摄像机的观察点
	glm::vec3 cameraUp;
	glm::vec3 cameraDir;
	glm::vec3 cameraFront;
	glm::vec3 cameraRight;
	glm::vec3 up;
	glm::vec3 right;

	
	bool firstMouse;
	double lastX;
	double lastY;
	float pitch;
	float yaw;
	float fov;
	bool isPressed;
};

