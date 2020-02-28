#include "Node.h"
#include"glm\gtc\matrix_transform.hpp"
Node::Node()
{
	init(glm::vec3(0.0f, 0.0f, 0.0f));
}


Node::~Node()
{

}

void Node::updateModelMatrix()
{
}

void Node::init(glm::vec3 position)
{
	x = position.x;
	y = position.y;
	z = position.z;
	this->position = position;

	opacity = 1.0f;
	color = glm::vec3(1.0f, 1.0f, 1.0f);
	
	scaleX = scaleY = scaleZ = 1.0f;
	
	angleX = angleY = angleZ = 0.0f;

	model = glm::mat4(1.0f);
}

void Node::draw()
{

}

void Node::update(float dt)
{
}

glm::mat4 Node::getModelMatrix()
{
	this->updateModelMatrix();
	return this->model;
}

