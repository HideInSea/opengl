
#include "Sprite2D.h"
#include "Render.h"
#include "Cube.h"
#include <glm/gtc/matrix_transform.hpp>

Render::Render()
{
}

Render::~Render()
{
}

void Render::render(Node* node,Camera * camera)
{
	
	//Sprite2D* sprite2d = (Sprite2D*)node;
	Cube* sprite2d = (Cube*)node;
 	Shader * shader=sprite2d->getShader();
	shader->Use();
	glm::mat4 model = sprite2d->getWorldMatrix();
	glm::mat4 tranform = camera->projection * camera->view* model;
	
	shader->SetMatrix4("transform", tranform, GL_FALSE);
	shader->SetMatrix4("model",model, GL_FALSE);
	shader->SetVector3f("objectColor", node->color);
	//shader->SetVector3f("viewPos", camera->position);
	shader->SetFloat("opacity", node->opacity);

	////方向光属性
	//shader->SetVector3f("directLight.ambient", glm::vec3(1.0f));
	//shader->SetVector3f("directLight.diffuse", glm::vec3(1.0f)); // 将光照调暗了一些以搭配场景
	//shader->SetVector3f("directLight.specular", glm::vec3(1.0f));
	//shader->SetVector3f("directLight.direction", glm::vec3(-5.0f, -2.0f, 0.0f));
	////点光属性
	//shader->SetVector3f("pointLight.ambient", glm::vec3(0.0f));
	//shader->SetVector3f("pointLight.diffuse", glm::vec3(0.0f)); // 将光照调暗了一些以搭配场景
	//shader->SetVector3f("pointLight.specular", glm::vec3(0.0f));
	//shader->SetVector3f("pointLight.position", glm::vec3(0.0f, 5.0f, 0.0f));
	//shader->SetFloat("pointLight.constant", 1.0f);
	//shader->SetFloat("pointLight.linear", 0.09f);
	//shader->SetFloat("pointLight.quadratic", 0.032f);
	////聚光属性
	//shader->SetVector3f("spotLight.ambient", glm::vec3(0.0f));
	//shader->SetVector3f("spotLight.diffuse", glm::vec3(0.0f)); // 将光照调暗了一些以搭配场景
	//shader->SetVector3f("spotLight.specular", glm::vec3(0.0f));

	//shader->SetFloat("spotLight.constant", 1.0f);
	//shader->SetFloat("spotLight.linear", 0.09f);
	//shader->SetFloat("spotLight.quadratic", 0.032f);

	//shader->SetVector3f("spotLight.position",camera->position);
	//shader->SetVector3f("spotLight.direction", camera->cameraFront);
	//shader->SetFloat("spotLight.cutOff", glm::cos(glm::radians(12.5f)));
	//shader->SetFloat("spotLight.outerCutOff", glm::cos(glm::radians(16.0f)));

	sprite2d->draw();
}

void Render::renderModel(Model * mode, Camera * camera, Shader * shader)
{
	//Sprite2D* sprite2d = (Sprite2D*)node;
	shader->Use();
	glm::mat4 model = glm::mat4(1.0f);
	model = glm::translate(model, glm::vec3(0.0f, 0.0f, 0.0f)); // translate it down so it's at the center of the scene
	model = glm::scale(model, glm::vec3(1.0f, 1.0f, 1.0f));	// it's a bit too big for our scene, so scale it down
	glm::mat4 tranform = camera->projection * camera->view* model;

	shader->SetMatrix4("transform", tranform, GL_FALSE);
	shader->SetMatrix4("model", model, GL_FALSE);
	mode->Draw(shader);
}

void Render::renderModelWithLight(Model * mode, Camera * camera, Shader * shader)
{
	//Sprite2D* sprite2d = (Sprite2D*)node;
	shader->Use();
	glm::mat4 model = glm::mat4(1.0f);
	model = glm::translate(model, glm::vec3(0.0f, 0.0f, 0.0f)); // translate it down so it's at the center of the scene
	model = glm::scale(model, glm::vec3(1.0f, 1.0f, 1.0f));	// it's a bit too big for our scene, so scale it down
	glm::mat4 tranform = camera->projection * camera->view* model;

	shader->SetMatrix4("transform", tranform, GL_FALSE);
	//shader->SetMatrix4("model", model, GL_FALSE);
	//设置方向光
	////方向光属性
	shader->SetVector3f("light.ambient", glm::vec3(0.3f));
	shader->SetVector3f("light.diffuse", glm::vec3(0.6f)); // 将光照调暗了一些以搭配场景
	shader->SetVector3f("light.specular", glm::vec3(1.0f));
	shader->SetVector3f("light.direction", glm::vec3(-5.0f, -2.0f, 0.0f));


	shader->SetVector3f("viewPos", camera->position);

	mode->Draw(shader);
}


