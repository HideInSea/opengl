#pragma once
#include "Shader.h"
#include "Texture2D.h"
#include"Node.h"

class Sprite2D:
	public Node
{
public:
	Sprite2D(float width, float height,Texture2D  texture,Shader  spriteShader);
	void draw();
	void init(float width,float height);
	void updateMatrix();
	void setShader(Shader &shader);
	Shader getShader() { return this->shader; };
	
private:
	Shader  shader;
	Texture2D  texture;
	
	GLuint VAO;
};

