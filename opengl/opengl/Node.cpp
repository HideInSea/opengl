#include "Node.h"
#include"glm\gtc\matrix_transform.hpp"
Node::Node()
{
	init(glm::vec3(0.0f, 0.0f, 0.0f));
}

Node::Node(glm::vec3 position)
{
	init(position);
}

Node::~Node()
{

}

void Node::init(glm::vec3 position)
{
	width = height = 100.0f;
	x = position.x;
	y = position.y;
	z = position.z;
	opacity = 1.0f;
	color = glm::vec3(1.0f, 1.0f, 1.0f);
	anchorX = 0.5f;
	anchorY = 0.5f;
	this->position = glm::vec3(x, y, z);
	angle = 0;
	scaleX = scaleY = scaleZ = 1.0f;
	model = getModelMatrix();
}

void Node::draw()
{

}

void Node::update(float dt)
{
}

glm::mat4 Node::getModelMatrix()
{
	glm::mat4 model = glm::mat4(1.0f);
	//glm::vec3 v3 = -glm::vec3(this->anchorX * width, this->anchorY * height, 0.0f) + this->position;
	glm::vec3 v3 = this->position;
	model = glm::translate(model, v3);
	model = glm::rotate(model, glm::radians(this->angle), glm::vec3(0.0f, 0.0f, 1.0f));
	model = glm::scale(model, glm::vec3(this->scaleX, this->scaleY, this->scaleZ));
	return model;
}
