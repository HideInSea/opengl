#pragma once
#include"Shader.h"
#include<vector>
#include<string>
#include"Mesh.h"
#include <assimp/Importer.hpp>
#include <assimp/scene.h>
#include <assimp/postprocess.h>
#include<iostream>
using namespace std;

class Model
{
public:
	Model();
	~Model();
	/*  函数   */
	Model(const char *path)
	{
		loadModel(path);
	}
	void Draw(Shader *shader);
private:
	/*  模型数据  */
	vector<Mesh> meshes;
	string directory;
	/*  函数   */
	void loadModel(string path);
	void processNode(aiNode *node, const aiScene *scene);
	Mesh processMesh(aiMesh *mesh, const aiScene *scene);
	vector<Texture> loadMaterialTextures(aiMaterial *mat, aiTextureType type,
		string typeName);
};

