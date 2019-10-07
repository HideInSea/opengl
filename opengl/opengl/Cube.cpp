#include "Cube.h"

Cube::Cube(glm::vec3 position, glm::vec3 size, Shader shader, Texture2D texture) :
	Node(position)
{
	this->size = size;
	this->shader = shader;
	this->texture = texture;
	init();
}

void Cube::draw()
{
	glActiveTexture(GL_TEXTURE0);
	this->texture.Bind();
	glBindVertexArray(this->VAO);
	glDrawArrays(GL_TRIANGLES, 0, 36);
	glBindVertexArray(0);
}

void Cube::init()
{
	float halfX = size.x * 0.5;
	float halfY = size.y * 0.5;
	float halfZ = size.z * 0.5;
	float vertices[] = {
		//     ---- 位置 ----    - 纹理坐标 -	--法向量--
		-halfX, -halfY, -halfZ,  0.0f, 0.0f,0.0f, 0.0f, -1.0f,
		 halfX, -halfY, -halfZ,  1.0f, 0.0f,0.0f, 0.0f, -1.0f,
		 halfX,  halfY, -halfZ,  1.0f, 1.0f,0.0f, 0.0f, -1.0f,
		 halfX,  halfY, -halfZ,  1.0f, 1.0f,0.0f, 0.0f, -1.0f,
		-halfX,  halfY, -halfZ,  0.0f, 1.0f,0.0f, 0.0f, -1.0f,
		-halfX, -halfY, -halfZ,  0.0f, 0.0f,0.0f, 0.0f, -1.0f,

		-halfX, -halfY,  halfZ,  0.0f, 0.0f,0.0f, 0.0f, 1.0f,
		 halfX, -halfY,  halfZ,  1.0f, 0.0f,0.0f, 0.0f, 1.0f,
		 halfX,  halfY,  halfZ,  1.0f, 1.0f,0.0f, 0.0f, 1.0f,
		 halfX,  halfY,  halfZ,  1.0f, 1.0f,0.0f, 0.0f, 1.0f,
		-halfX,  halfY,  halfZ,  0.0f, 1.0f,0.0f, 0.0f, 1.0f,
		-halfX, -halfY,  halfZ,  0.0f, 0.0f,0.0f, 0.0f, 1.0f,

		-halfX,  halfY,  halfZ,  1.0f, 0.0f,-1.0f, 0.0f, 0.0f,
		-halfX,  halfY, -halfZ,  1.0f, 1.0f,-1.0f, 0.0f, 0.0f,
		-halfX, -halfY, -halfZ,  0.0f, 1.0f,-1.0f, 0.0f, 0.0f,
		-halfX, -halfY, -halfZ,  0.0f, 1.0f,-1.0f, 0.0f, 0.0f,
		-halfX, -halfY,  halfZ,  0.0f, 0.0f,-1.0f, 0.0f, 0.0f,
		-halfX,  halfY,  halfZ,  1.0f, 0.0f,-1.0f, 0.0f, 0.0f,

		 halfX,  halfY,  halfZ,  1.0f, 0.0f,1.0f, 0.0f, 0.0f,
		 halfX,  halfY, -halfZ,  1.0f, 1.0f,1.0f, 0.0f, 0.0f,
		 halfX, -halfY, -halfZ,  0.0f, 1.0f,1.0f, 0.0f, 0.0f,
		 halfX, -halfY, -halfZ,  0.0f, 1.0f,1.0f, 0.0f, 0.0f,
		 halfX, -halfY,  halfZ,  0.0f, 0.0f,1.0f, 0.0f, 0.0f,
		 halfX,  halfY,  halfZ,  1.0f, 0.0f,1.0f, 0.0f, 0.0f,

		-halfX, -halfY, -halfZ,  0.0f, 1.0f,0.0f, -1.0f, 0.0f,
		 halfX, -halfY, -halfZ,  1.0f, 1.0f,0.0f, -1.0f, 0.0f,
		 halfX, -halfY,  halfZ,  1.0f, 0.0f,0.0f, -1.0f, 0.0f,
		 halfX, -halfY,  halfZ,  1.0f, 0.0f,0.0f, -1.0f, 0.0f,
		-halfX, -halfY,  halfZ,  0.0f, 0.0f,0.0f, -1.0f, 0.0f,
		-halfX, -halfY, -halfZ,  0.0f, 1.0f,0.0f, -1.0f, 0.0f,

		-halfX,  halfY, -halfZ,  0.0f, 1.0f,0.0f, 1.0f, 0.0f,
		 halfX,  halfY, -halfZ,  1.0f, 1.0f,0.0f, 1.0f, 0.0f,
		 halfX,  halfY,  halfZ,  1.0f, 0.0f,0.0f, 1.0f, 0.0f,
		-halfX,  halfY, -halfZ,  0.0f, 1.0f,0.0f, 1.0f, 0.0f,
		 halfX,  halfY,  halfZ,  1.0f, 0.0f,0.0f, 1.0f, 0.0f,
		-halfX,  halfY,  halfZ,  0.0f, 0.0f,0.0f, 1.0f, 0.0f,

	};


	GLuint VBO;
	glGenVertexArrays(1, &this->VAO);
	glGenBuffers(1, &VBO);

	glBindVertexArray(this->VAO);

	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);


	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)0);

	glEnableVertexAttribArray(1);
	glVertexAttribPointer(1, 2, GL_FLOAT, false, 8 * sizeof(float), (void*)(3 * sizeof(float)));

	glEnableVertexAttribArray(2);
	glVertexAttribPointer(2, 3, GL_FLOAT, false, 8 * sizeof(float), (void*)(5 * sizeof(float)));

	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glBindVertexArray(0);
}
