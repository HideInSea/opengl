#include "Cube.h"
#include <glm\gtc\matrix_transform.hpp>

Cube::Cube(float x, float y, float z, Texture2D* texture, Shader* shader)
{
	this->texture = texture;
	this->shader = shader;
	this->init(x, y, z);
}

void Cube::draw()
{
	glActiveTexture(GL_TEXTURE0);
	this->texture->Bind();
	glBindVertexArray(this->VAO);
	//glDrawElements(GL_TRIANGLES, 36, GL_UNSIGNED_INT, 0);
	glDrawArrays(GL_TRIANGLES, 0, 36);
	glBindVertexArray(0);
}

void Cube::init(float x, float y, float z)
{
	this->length = x;
	this->width = z;
	this->height = y;
	float halfL = x * 0.5;
	float halfZ = z * 0.5;
	float halfY = y * 0.5;

	float vertices[] = {
	-halfL, -halfY, -halfZ,  0.0f, 0.0f,		//
	 halfL, -halfY, -halfZ,  1.0f, 0.0f,
	 halfL,  halfY, -halfZ,  1.0f, 1.0f,
	 halfL,  halfY, -halfZ,  1.0f, 1.0f,
	-halfL,  halfY, -halfZ,  0.0f, 1.0f,
	-halfL, -halfY, -halfZ,  0.0f, 0.0f,

	-halfL, -halfY,  halfZ,  0.0f, 0.0f,
	 halfL, -halfY,  halfZ,  1.0f, 0.0f,
	 halfL,  halfY,  halfZ,  1.0f, 1.0f,
	 halfL,  halfY,  halfZ,  1.0f, 1.0f,
	-halfL,  halfY,  halfZ,  0.0f, 1.0f,
	-halfL, -halfY,  halfZ,  0.0f, 0.0f,

	-halfL,  halfY,  halfZ,  1.0f, 0.0f,
	-halfL,  halfY, -halfZ,  1.0f, 1.0f,
	-halfL, -halfY, -halfZ,  0.0f, 1.0f,
	-halfL, -halfY, -halfZ,  0.0f, 1.0f,
	-halfL, -halfY,  halfZ,  0.0f, 0.0f,
	-halfL,  halfY,  halfZ,  1.0f, 0.0f,

	 halfL,  halfY,  halfZ,  1.0f, 0.0f,
	 halfL,  halfY, -halfZ,  1.0f, 1.0f,
	 halfL, -halfY, -halfZ,  0.0f, 1.0f,
	 halfL, -halfY, -halfZ,  0.0f, 1.0f,
	 halfL, -halfY,  halfZ,  0.0f, 0.0f,
	 halfL,  halfY,  halfZ,  1.0f, 0.0f,

	-halfL, -halfY, -halfZ,  0.0f, 1.0f,
	 halfL, -halfY, -halfZ,  1.0f, 1.0f,
	 halfL, -halfY,  halfZ,  1.0f, 0.0f,
	 halfL, -halfY,  halfZ,  1.0f, 0.0f,
	-halfL, -halfY,  halfZ,  0.0f, 0.0f,
	-halfL, -halfY, -halfZ,  0.0f, 1.0f,

	-halfL,  halfY, -halfZ,  0.0f, 1.0f,
	 halfL,  halfY, -halfZ,  1.0f, 1.0f,
	 halfL,  halfY,  halfZ,  1.0f, 0.0f,
	 halfL,  halfY,  halfZ,  1.0f, 0.0f,
	-halfL,  halfY,  halfZ,  0.0f, 0.0f,
	-halfL,  halfY, -halfZ,  0.0f, 1.0f
	};

	GLuint VBO;
	glGenVertexArrays(1, &this->VAO);
	glGenBuffers(1, &VBO);

	glBindVertexArray(this->VAO);

	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);


	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)0);

	glEnableVertexAttribArray(1);
	glVertexAttribPointer(1, 2, GL_FLOAT, false, 5 * sizeof(float), (void*)(3 * sizeof(float)));

	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glBindVertexArray(0);

}

void Cube::updateModelMatrix()
{
	glm::mat4 model(1.0f);
	model = glm::translate(model,this->position);
	model = glm::rotate(model, glm::radians(this->angleX), glm::vec3(1.0f, 0,0));
	model = glm::rotate(model, glm::radians(this->angleY), glm::vec3(0, 1.0f,0));
	model = glm::rotate(model, glm::radians(this->angleZ), glm::vec3(0, 0,1.0f));
	model = glm::scale(model, glm::vec3(this->scaleX, this->scaleY, this->scaleZ));
	this->model = model;
}

void Cube::setShader(Shader* shader)
{
	this->shader = shader;
}
