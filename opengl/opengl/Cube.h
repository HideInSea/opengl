#pragma once
#include "Node3D.h"
#include "Shader.h"
#include "Texture2D.h"
class Cube :
	public Node3D
{
public:
	Cube(float x,float y,float z,Texture2D * texture,Shader * shader);
	~Cube() {};
	void draw();
	void init(float x, float y,float z);
	virtual void updateModelMatrix();
	void setShader(Shader* shader);
	Shader* getShader() { return this->shader; };

	float length;
	float width;
	float height;

private:
	Shader* shader;
	Texture2D* texture;

	GLuint VAO;
};

