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

	glm::mat4 view;
	glm::mat4 projection;

	glm::vec3 target;//摄像机的观察点
	glm::vec3 cameraUp;
	glm::vec3 cameraDir;
};

