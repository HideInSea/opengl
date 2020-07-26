#include "Node.h"
#include"glm\gtc\matrix_transform.hpp"
Node::Node()
{
	x = y = z = 0;
	scaleX = scaleY = scaleZ = 1;
	angleX = angleY = angleZ = 0;
	position = glm::vec3(0);
	angle = glm::vec3(0);
	scale = glm::vec3(1);
	localMatrix = glm::mat4(1);
	worldMatrix = glm::mat4(1);
}


Node::~Node()
{

}

void Node::updateLocalMatrix()
{

}

void Node::updateWorldMatrix()
{
	glm::mat4 origin = glm::mat4(1);
	origin = glm::translate(origin, this->position);
	origin = glm::rotate(origin, this->angleX, glm::vec3(1, 0, 0));
	origin = glm::rotate(origin, this->angleY, glm::vec3(0, 1, 0));
	origin = glm::rotate(origin, this->angleZ, glm::vec3(0, 0, 1));
	origin = glm::scale(origin, this->scale);
	this->worldMatrix = origin;
}

void Node::draw()
{
	
}

void Node::update(float dt)
{

}

glm::mat4 Node::getLocalMatrix()
{
	this->updateLocalMatrix();
	return this->localMatrix;
}

glm::mat4 Node::getWorldMatrix()
{
	this->updateWorldMatrix();
	return this->worldMatrix;
}

