
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
	glm::mat4 tranform = camera->projection * camera->view*sprite2d->getModelMatrix();

	shader->SetMatrix4("transform", tranform, GL_FALSE);
	shader->SetVector3f("color", node->color);
	shader->SetFloat("opacity", node->opacity);
	sprite2d->draw();
}
