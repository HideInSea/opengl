
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include<iostream>
#include<fstream>
#include<sstream>
#include "Game.h"
#include "ResourceManager.h"
using namespace std;
//
//#define BUFFER_OFFSET(offset) ((void * )(offset))
//
//const int SCR_H = 800;
//const int SCR_W = 800;
//const int NumVertices = 6;
//const GLsizei NumVAOs=2, NumBuffers=2;
//
//GLuint VAOs[NumVAOs],Buffers[NumBuffers];
//GLint ArrayBuffer=0, Triangles=0;





//GLuint vPosition=0;
//
//struct ShaderInfo {
//	string vertexShader;
//	string fragmentShader;
//};
//
//void framebuffer_size_callback(GLFWwindow* window, int width, int height);
//
//GLuint LoadShaders(ShaderInfo shaderInfo);
//void init();
//void display();
//
// GLFW function declerations
void key_callback(GLFWwindow* window, int key, int scancode, int action, int mode);

// The Width of the screen
extern const GLuint SCREEN_WIDTH = 800;
// The height of the screen
extern const GLuint SCREEN_HEIGHT = 600;

Game Breakout(SCREEN_WIDTH, SCREEN_HEIGHT);



int main() {
	//初始化
	glfwInit();
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 5);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);
	//创建窗口
	GLFWwindow* window = glfwCreateWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "firstGame", NULL, NULL);
	if (window == NULL)
	{
		std::cout << "Failed to create GLFW window" << std::endl;
		glfwTerminate();
		return -1;
	}


	glfwMakeContextCurrent(window);
	glfwSetKeyCallback(window, key_callback);

	//获取 opengl 接口地址
// glad: load all OpenGL function pointers
// ---------------------------------------
	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
	{
		std::cout << "Failed to initialize GLAD" << std::endl;
		return -1;
	}

	//glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);
		// OpenGL configuration
	glViewport(0, 0, SCREEN_WIDTH, SCREEN_HEIGHT);
	//glEnable(GL_CULL_FACE);
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_STENCIL_TEST);
	// Initialize game
	Breakout.Init();

	// DeltaTime variables
	GLfloat deltaTime = 0.0f;
	GLfloat lastFrame = 0.0f;

	// Start Game within Menu State
	Breakout.State = GAME_ACTIVE;


	//init();


	while (!glfwWindowShouldClose(window))
	{
		// Calculate delta time
		GLfloat currentFrame = glfwGetTime();
		deltaTime = currentFrame - lastFrame;
		lastFrame = currentFrame;
		glfwPollEvents();
		//update
				//deltaTime = 0.001f;
		// Manage user input
		Breakout.ProcessInput(deltaTime);

		// Update Game state
		Breakout.Update(deltaTime);


		// render
				// Render
		glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT|GL_STENCIL_BUFFER_BIT);
		Breakout.Render();
		//display();

		// glfw: swap buffers and poll IO events (keys pressed/released, mouse moved etc.)
		// -------------------------------------------------------------------------------
		glfwSwapBuffers(window);
	}
	ResourceManager::Clear();
	// glfw: terminate, clearing all previously allocated GLFW resources.
	// ------------------------------------------------------------------
	glfwTerminate();
	return 0;
}
//
//
//void init() {
//	static const GLfloat vertices[NumVertices][2] = {
//		{-0.90,-0.90},//triangle1
//		{0.85,-0.90},
//		{-0.90,0.85},
//		{0.90,-0.85},//triangle2
//		{0.90,0.90},
//		{-0.85,0.90}
//	};
//
//	glCreateVertexArrays(NumVAOs,VAOs);
//	glCreateBuffers(NumBuffers, Buffers);
//	glNamedBufferStorage(Buffers[ArrayBuffer], sizeof(vertices), vertices, 0);
//	
//
//	ShaderInfo shaders = {
//		"../shaders/triangles.vs",
//		"../shaders/triangles.fs",
//	};
//
//	GLuint program = LoadShaders(shaders);
//	glUseProgram(program);
//
//	glBindVertexArray(VAOs[Triangles]);
//	glBindBuffer(GL_ARRAY_BUFFER, Buffers[ArrayBuffer]);
//	glVertexAttribPointer(vPosition, 2, GL_FLOAT, GL_FALSE, 0, BUFFER_OFFSET(0));
//	glEnableVertexAttribArray(vPosition);
//}
//
//void display() {
//	glClearColor(0.5f, 0.5f, 0.5f, 1.0f);
//	glClear(GL_COLOR_BUFFER_BIT);
//
//	glBindVertexArray(VAOs[Triangles]);
//	glDrawArrays(GL_TRIANGLES,0,NumVertices);
//}
//
//GLuint LoadShaders(ShaderInfo shaderInfo) {
//	std::string vertexCode;
//	std::string fragmentCode;
//	//std::string geometryCode;
//	std::ifstream vertexShaderFile;
//	std::ifstream fragmentShaderFile;
//
//	vertexShaderFile.exceptions(std::ifstream::failbit | std::ifstream::badbit);
//	fragmentShaderFile.exceptions(std::ifstream::failbit | std::ifstream::badbit);
//	try
//	{
//		// Open files
//		vertexShaderFile.open(shaderInfo.vertexShader);
//		fragmentShaderFile.open(shaderInfo.fragmentShader);
//
//		std::stringstream vShaderStream, fShaderStream;
//		// Read file's buffer contents into streams
//		vShaderStream << vertexShaderFile.rdbuf();
//		fShaderStream << fragmentShaderFile.rdbuf();
//		// close file handlers
//		vertexShaderFile.close();
//		fragmentShaderFile.close();
//		// Convert stream into string
//		vertexCode = vShaderStream.str();
//		fragmentCode = fShaderStream.str();
//		// If geometry shader path is present, also load a geometry shader
//		//if (gShaderFile != nullptr)
//		//{
//		//	std::ifstream geometryShaderFile(gShaderFile);
//		//	std::stringstream gShaderStream;
//		//	gShaderStream << geometryShaderFile.rdbuf();
//		//	geometryShaderFile.close();
//		//	geometryCode = gShaderStream.str();
//		//}
//	}
//	catch (std::exception e)
//	{
//		std::cout << "ERROR::SHADER: Failed to read shader files" << std::endl;
//	}
//	const GLchar* vShaderCode = vertexCode.c_str();
//	const GLchar* fShaderCode = fragmentCode.c_str();
//
//
//
//	//编译顶点着色器
//	GLuint vShader;
//	GLint success;
//	GLchar infoLog[512];
//	vShader = glCreateShader(GL_VERTEX_SHADER);
//	glShaderSource(vShader, 1, &vShaderCode, NULL);
//	glCompileShader(vShader);
//
//	glGetShaderiv(vShader, GL_COMPILE_STATUS, &success);
//
//	if (!success) {
//		glGetShaderInfoLog(vShader, 512, NULL, infoLog);
//		std::cout << "ERROR::SHADER::VERTEX::COMPILATION_FAILED\n" << infoLog << std::endl;
//	}
//	
//	//编译片段着色器
//	GLuint fShader;
//	fShader = glCreateShader(GL_FRAGMENT_SHADER);
//	glShaderSource(fShader, 1, &fShaderCode, NULL);
//	glCompileShader(fShader);
//
//	glGetShaderiv(fShader, GL_COMPILE_STATUS, &success);
//
//	if (!success) {
//		glGetShaderInfoLog(fShader, 512, NULL, infoLog);
//		std::cout << "ERROR::SHADER::VERTEX::COMPILATION_FAILED\n" << infoLog << std::endl;
//	}
//
//	//连接着色器程序
//	GLuint program;
//	program = glCreateProgram();
//	glAttachShader(program, vShader);
//	glAttachShader(program, fShader);
//	glLinkProgram(program);
//	// 打印连接错误（如果有的话）
//	glGetProgramiv(program, GL_LINK_STATUS, &success);
//	if (!success)
//	{
//		glGetProgramInfoLog(program, 512, NULL, infoLog);
//		std::cout << "ERROR::SHADER::PROGRAM::LINKING_FAILED\n" << infoLog << std::endl;
//	}
//
//	// 删除着色器，它们已经链接到我们的程序中了，已经不再需要了
//	glDeleteShader(vShader);
//	glDeleteShader(fShader);
//
//	return program;
//}
//
////窗口变化是跟新视口大小
//void framebuffer_size_callback(GLFWwindow* window, int width, int height)
//{
//	// make sure the viewport matches the new window dimensions; note that width and 
//	// height will be significantly larger than specified on retina displays.
//	glviewport(0, 0, width, height);
//}

void key_callback(GLFWwindow* window, int key, int scancode, int action, int mode)
{
	// When a user presses the escape key, we set the WindowShouldClose property to true, closing the application
	if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
		glfwSetWindowShouldClose(window, GL_TRUE);
	if (key >= 0 && key < 1024)
	{
		if (action == GLFW_PRESS)
			Breakout.Keys[key] = GL_TRUE;
		else if (action == GLFW_RELEASE)
			Breakout.Keys[key] = GL_FALSE;
	}
}