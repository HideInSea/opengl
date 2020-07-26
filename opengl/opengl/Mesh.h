#pragma once
#include<glm/glm.hpp>
#include<string>
#include<vector>
#include"Shader.h"

#include"Texture2D.h"
using namespace std;


struct Vertex {
	glm::vec3 Position;
	glm::vec3 Normal;
	glm::vec2 TexCoords;
};

struct Texture {
	Texture2D * texture;
	string type;
};

class Mesh
{
public:
	Mesh();
	~Mesh();

	/*  ��������  */
	vector<Vertex> vertices;
	vector<unsigned int> indices;
	vector<Texture> textures;
	/*  ����  */
	Mesh(vector<Vertex> vertices, vector<unsigned int> indices, vector<Texture> textures);
	void Draw(Shader* shader);
private:
	/*  ��Ⱦ����  */
	unsigned int VAO, VBO, EBO;
	/*  ����  */
	void setupMesh();

};

