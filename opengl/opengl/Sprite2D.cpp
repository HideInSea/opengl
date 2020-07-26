#include "Sprite2D.h"
#include "ResourceManager.h"
#include <glm/gtc/matrix_transform.hpp>

Sprite2D::Sprite2D(float width, float height, Texture2D* texture2D, Shader* spriteShader):diffuseMap(texture2D),shader(spriteShader)
{
	this->init(width, height);
}

void Sprite2D::draw()
{
	glActiveTexture(GL_TEXTURE0);
	this->diffuseMap->Bind();
	glBindVertexArray(this->VAO);
	glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
	glBindVertexArray(0);
}

void Sprite2D::init(float width,float height)
{
	this->width = width;
	this->height = height;
	//float vertices[] = {
	//	//     ---- 位置 ----         - 纹理坐标 -
	//		 0.5f,  0.5f, 0.0f,      1.0f, 1.0f,   // 右上
	//		 0.5f, -0.5f, 0.0f,      1.0f, 0.0f,   // 右下
	//		-0.5f, -0.5f, 0.0f,      0.0f, 0.0f,   // 左下
	//		-0.5f,  0.5f, 0.0f,      0.0f, 1.0f    // 左上
	//};

	float vertices[] = {
		//     ---- 位置 ----           - 纹理坐标 -
			width,height, 0.0f,     1.0f, 1.0f,   // 右上
			width, 0.0f, 0.0f,     1.0f, 0.0f,   // 右下
			0.0f, 0.0f, 0.0f,   	0.0f, 0.0f,   // 左下
			0.0f,height, 0.0f,      0.0f, 1.0f    // 左上
	};


	unsigned int indices[] = { // 注意索引从0开始! 
	3, 1, 0, // 第一个三角形
	3, 2, 1  // 第二个三角形
	};

	GLuint VBO,EBO;
	glGenVertexArrays(1, &this->VAO);
	glGenBuffers(1, &VBO);
	glGenBuffers(1, &EBO);

	glBindVertexArray(this->VAO);

	glBindBuffer(GL_ARRAY_BUFFER,VBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

	
	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0,3,GL_FLOAT,GL_FALSE,5*sizeof(float),(void*)0);

	glEnableVertexAttribArray(1);
	glVertexAttribPointer(1,2,GL_FLOAT,false,5*sizeof(float),(void*)(3*sizeof(float)));

	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glBindVertexArray(0);
 
}

void Sprite2D::setShader(Shader *shader)
{
	this->shader = shader;
}

