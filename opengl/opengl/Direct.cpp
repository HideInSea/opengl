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
	Loader::LoadTexture("../texture/container2_specular.png", GL_TRUE, "container2_specular");
	Loader::LoadTexture("../texture/container2_diffuse.png", GL_TRUE, "container2_diffuse");

	Loader::LoadShader("../shaders/texture2d.vs", "../shaders/texture2d.fs", nullptr, "spriteShader");
	Loader::LoadShader("../shaders/directionLight.vs", "../shaders/directionLight.fs", nullptr, "directionLight");
	Loader::LoadShader("../shaders/pointLight.vs", "../shaders/pointLight.fs", nullptr, "pointLight");
	Loader::LoadShader("../shaders/spotLight.vs", "../shaders/spotLight.fs", nullptr, "spotLight");
	Loader::LoadShader("../shaders/lightPos.vs", "../shaders/lightPos.fs", nullptr, "lightPosShader");
	//this->camera=new OrthographicCamera(0, SCREEN_WIDTH,0,SCREEN_HEIGHT,0.1f,100.0f);
	//this->camera->setPosition(glm::vec3(0,0,10.0f));
	//this->camera->lockAt(glm::vec3(0,0,0));
	this->camera=new PerspectiveCamera(45.0f,(float)SCREEN_WIDTH/(float)SCREEN_HEIGHT,0.1f,100.0f);
	this->camera->setPosition(glm::vec3(0,5.0f,10.0f));
	this->camera->lockAt(glm::vec3(0,0,0));
	this->render = new Render();
	this->shader=Loader::GetShader("spriteShader");

	//this->bg= new Sprite2D(SCREEN_WIDTH, SCREEN_HEIGHT, Loader::GetTexture("block_solid"), Loader::GetShader("spriteShader"));
	//////this->sprite = new Sprite2D(SCREEN_WIDTH, SCREEN_HEIGHT, Loader::GetTexture("background"), Loader::GetShader("spriteShader"));
	//this->bg->anchorX = 0;
	//this->bg->anchorY = 0;

	this->cube = new Cube(1.0f,1.0f,1.0f, Loader::GetTexture("container2_diffuse"), Loader::GetTexture("container2_specular"), Loader::GetShader("spotLight"));



	this->light = new Cube(0.5f,0.5f,0.5f, Loader::GetTexture("block_solid"), Loader::GetTexture("block_solid"), Loader::GetShader("lightPosShader"));
	this->light->setPosition(glm::vec3(5.0f,2.0f,0.0f));

	this->ground = new Cube(10.0f,0.2f,10.0f, Loader::GetTexture("block"), Loader::GetTexture("block"), Loader::GetShader("spotLight"));
	this->ground->setPosition(glm::vec3(0.0f,-0.6f,0.0f));
}

void Direct::mainLoop(float dt)
{
	this->render->render(this->ground, this->camera);

	this->render->render(this->cube, this->camera);

	this->render->render(this->light, camera);
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

