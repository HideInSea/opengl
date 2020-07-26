#include "Loader.h"
#include <iostream>
#include <sstream>
#include <fstream>

#include "stb_image.h"
using namespace std;
std::map<std::string, Texture2D*>    Loader::Textures;
std::map<std::string, Shader*>       Loader::Shaders;

Shader* Loader::LoadShader(const GLchar* vShaderFile, const GLchar* fShaderFile, const GLchar* gShaderFile, std::string name)
{
	Shaders[name] = loadShaderFromFile(vShaderFile, fShaderFile, gShaderFile);
	return Shaders[name];
}

Shader*  Loader::GetShader(std::string name)
{
	return Shaders[name];
}

Texture2D* Loader::LoadTexture(const GLchar* file, GLboolean alpha, std::string name)
{
	cout << "Load texture " << file << endl;
	Textures[name] = loadTextureFromFile(file, alpha);
	return Textures[name];
}

Texture2D*  Loader::GetTexture(std::string name)
{
	Texture2D* texture = Textures[name];
	return texture;
}

void Loader::Clear()
{
	// (Properly) delete all shaders	
	for (auto iter : Shaders)
		glDeleteProgram(iter.second->ID);
	// (Properly) delete all textures
	for (auto iter : Textures)
		glDeleteTextures(1, &iter.second->ID);
}

Shader* Loader::loadShaderFromFile(const GLchar* vShaderFile, const GLchar* fShaderFile, const GLchar* gShaderFile)
{
	// 1. Retrieve the vertex/fragment source code from filePath
	std::string vertexCode;
	std::string fragmentCode;
	std::string geometryCode;
	try
	{
		// Open files
		std::ifstream vertexShaderFile(vShaderFile);
		std::ifstream fragmentShaderFile(fShaderFile);
		std::stringstream vShaderStream, fShaderStream;
		// Read file's buffer contents into streams
		vShaderStream << vertexShaderFile.rdbuf();
		fShaderStream << fragmentShaderFile.rdbuf();
		// close file handlers
		vertexShaderFile.close();
		fragmentShaderFile.close();
		// Convert stream into string
		vertexCode = vShaderStream.str();
		fragmentCode = fShaderStream.str();
		// If geometry shader path is present, also load a geometry shader
		if (gShaderFile != nullptr)
		{
			std::ifstream geometryShaderFile(gShaderFile);
			std::stringstream gShaderStream;
			gShaderStream << geometryShaderFile.rdbuf();
			geometryShaderFile.close();
			geometryCode = gShaderStream.str();
		}
	}
	catch (std::exception e)
	{
		std::cout << "ERROR::SHADER: Failed to read shader files" << std::endl;
	}
	const GLchar* vShaderCode = vertexCode.c_str();
	const GLchar* fShaderCode = fragmentCode.c_str();
	const GLchar* gShaderCode = geometryCode.c_str();
	// 2. Now create shader object from source code
	Shader* shader=new Shader();
	shader->Compile(vShaderCode, fShaderCode, gShaderFile != nullptr ? gShaderCode : nullptr);
	return shader;
}

Texture2D* Loader::loadTextureFromFile(const GLchar* file, GLboolean alpha)
{
	// Create Texture object
	Texture2D* texture=new Texture2D();
	if (alpha)
	{
		texture->Internal_Format = GL_RGBA;
		texture->Image_Format = GL_RGBA;
	}
	// Load image
	int width, height,nrChannels;
	stbi_set_flip_vertically_on_load(true);
	//stbi_load("container.jpg", &width, &height, &nrChannels, 0);
	unsigned char* image = stbi_load(file, &width, &height, &nrChannels, texture->Image_Format== GL_RGBA?STBI_rgb_alpha:STBI_rgb);
	// Now generate texture
	texture->Generate(width, height, image);
	// And finally free image data
	stbi_image_free(image);
	return texture;
}
