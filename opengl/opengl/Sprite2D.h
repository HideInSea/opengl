#pragma once
#include "Shader.h"
#include "Texture2D.h"
#include"Node2D.h"

class Sprite2D:
	public Node2D
{
public:
	Sprite2D(float width, float height,Texture2D * texture,Shader * spriteShader);
	void draw();
	void init(float width,float height);
	void setShader(Shader *shader);
	Shader* getShader() { return this->shader; };
	
	
private:
	Shader*  shader;
	Texture2D*  diffuseMap;			//Âş·´ÉäÌùÍ¼
	
	GLuint VAO;
};

