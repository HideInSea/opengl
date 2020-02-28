#include "Direct.h"
#include"OrthographicCamera.h"
#include"PerspectiveCamera.h"

extern const GLuint SCREEN_WIDTH;
extern const GLuint SCREEN_HEIGHT;
Direct::Direct()
{
	
}

Direct::~Direct()
{
}

void Direct::init()
{
	Loader::LoadTexture("../texture/block.png", GL_TRUE, "block");
	Loader::LoadTexture("../texture/block_solid.png", GL_TRUE, "block_solid");

	Loader::LoadTexture("../texture/face.png", GL_TRUE, "face");
	Loader::LoadTexture("../texture/background.jpg", GL_TRUE, "background");
	Loader::LoadTexture("../texture/paddle.png", GL_TRUE, "paddle");

	Loader::LoadShader("../shaders/texture2d.vs", "../shaders/texture2d.fs", nullptr, "spriteShader");
	Loader::LoadShader("../shaders/light.vs", "../shaders/light.fs", nullptr, "lightShader");
	//this->camera=new OrthographicCamera(0, SCREEN_WIDTH,0,SCREEN_HEIGHT,0.1f,100.0f);
	//this->camera->setPosition(glm::vec3(0,0,10.0f));
	//this->camera->lockAt(glm::vec3(0,0,0));
	this->camera=new PerspectiveCamera(45.0f,(float)SCREEN_WIDTH/(float)SCREEN_HEIGHT,0.1f,100.0f);
	this->camera->setPosition(glm::vec3(0,0,5.0f));
	this->camera->lockAt(glm::vec3(0,0,0));
	this->render = new Render();
	this->shader=Loader::GetShader("spriteShader");

	//this->bg= new Sprite2D(SCREEN_WIDTH, SCREEN_HEIGHT, Loader::GetTexture("block_solid"), Loader::GetShader("spriteShader"));
	//////this->sprite = new Sprite2D(SCREEN_WIDTH, SCREEN_HEIGHT, Loader::GetTexture("background"), Loader::GetShader("spriteShader"));
	//this->bg->anchorX = 0;
	//this->bg->anchorY = 0;

	this->cube = new Cube(1.0f,1.0f,1.0f, Loader::GetTexture("block_solid"), Loader::GetShader("spriteShader"));

}

void Direct::mainLoop(float dt)
{

	this->render->render(this->cube, this->camera);
	//this->shader->Use();
	//this->shader->SetVector3f("color",glm::vec3(1.0f));
	//this->shader->SetFloat("opacity",1.0f);
	//glBindVertexArray(this->VAO);
	//glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
	//glBindVertexArray(0);
}

void Direct::processInput(GLFWwindow* window)
{
	this->camera->processInput(window);
}

void Direct::mouse_callback(GLFWwindow* window, double xpos, double ypos)
{
	this->camera->mouse_callback(window, xpos, ypos);
}

void Direct::scroll_callback(GLFWwindow* window, double xoffset, double yoffset)
{
	this->camera->scroll_callback(window,xoffset,yoffset);
}

void Direct::mouse_button_callback(GLFWwindow* window, int button, int action, int mods)
{
	this->camera->mouse_button_callback(window, button, action, mods);
}

