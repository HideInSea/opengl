#pragma once
#include "Node3D.h"
#include "Shader.h"
#include "Texture2D.h"
class Cube :
	public Node3D
{
public:
	Cube(float x,float y,float z,Texture2D * diffuseMap,Texture2D * specularMap,Shader * shader);
	~Cube() {};
	void draw();
	void init(float x, float y,float z);
	virtual void updateModelMatrix();
	void setShader(Shader* shader);
	Shader* getShader() { return this->shader; };
	
	void setSpecularMap(Texture2D* texture) { this->specularMap = texture; };

	float length;
	float width;
	float height;

private:
	Shader* shader;
	Texture2D* diffuseMap;				//Âş·´ÉäÌùÍ¼
	Texture2D* specularMap;				//¾µÃæ¹âÌùÍ¼

	GLuint VAO;
};

