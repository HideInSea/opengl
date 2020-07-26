#pragma once
#include "Loader.h"
#include "Sprite2D.h"
#include "Render.h"
#include <GLFW\glfw3.h>
#include "Cube.h"
#include"Model.h"
class Direct
{
public:
	Direct();
	~Direct();

	void init();
	
	void mainLoop(float dt);
	void processInput(GLFWwindow * window);
	void mouse_callback(GLFWwindow* window, double xpos, double ypos);
	void scroll_callback(GLFWwindow* window, double xoffset, double yoffset);
	void mouse_button_callback(GLFWwindow* window, int button, int action, int mods);
	Loader* loader;
	Camera* camera;
	Render* render;
	Cube* light;

	Sprite2D* bg;
	Sprite2D* bgTwo;
	Cube* cube;
	Cube* twoCube;

	Cube* ground;

	GLuint VAO;
	Shader* shader;
	Model * model;
};

