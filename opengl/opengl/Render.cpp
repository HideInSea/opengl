
#include "Sprite2D.h"
#include "Render.h"
#include "Cube.h"

Render::Render()
{
}

Render::~Render()
{
}

void Render::render(Node* node,Camera * camera)
{
	
	Cube* sprite2d = (Cube*)node;
 	Shader * shader=sprite2d->getShader();
	shader->Use();
	glm::mat4 model = sprite2d->getModelMatrix();
	glm::mat4 tranform = camera->projection * camera->view* model;
	
	shader->SetMatrix4("transform", tranform, GL_FALSE);
	shader->SetMatrix4("model",model, GL_FALSE);
	shader->SetVector3f("objectColor", node->color);
	shader->SetVector3f("viewPos", camera->position);
	shader->SetFloat("opacity", node->opacity);

	//光属性
	shader->SetVector3f("light.ambient", glm::vec3(0.2f));
	shader->SetVector3f("light.diffuse", glm::vec3(0.5f)); // 将光照调暗了一些以搭配场景
	shader->SetVector3f("light.specular", glm::vec3(1.0f));
	shader->SetVector3f("light.position", glm::vec3(5.0f, 2.0f, 0.0f));
	//材质属性
	shader->SetVector3f("material.specular", glm::vec3(0.5f, 0.5f, 0.5f));
	shader->SetFloat("material.shininess", 64.0f);
	sprite2d->draw();
}
