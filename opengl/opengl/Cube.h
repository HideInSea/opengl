#pragma once
#include "Node.h"
#include "Shader.h"
#include "Texture2D.h"
class Cube :
	public Node
{
public:
	Cube(glm::vec3 position,glm::vec3 size,Shader shader,Texture2D texture);
	void draw();
	void init();
	glm::vec3 size;
	Shader shader;
	Texture2D texture;
	GLuint VAO;
};

