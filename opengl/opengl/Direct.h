#pragma once
#include "Loader.h"
#include "Sprite2D.h"
#include "Render.h"
#include <GLFW\glfw3.h>
#include "Cube.h"

class Direct
{
public:
	Direct();
	~Direct();

	void init();
	
	void mainLoop(float dt);
	void processInput(GLFWwindow * window);
	
	Loader* loader;
	Camera* camera;
	Render* render;

	Sprite2D* bg;
	Cube* cube;
	GLuint VAO;
	Shader* shader;
};

