#include "Node2D.h"

Node2D::Node2D()
{
	this->anchorX = 0.5f;
	this->anchorY = 0.5f;
	this->angle = 0;
	this->width = 100.0f;
	this->height = 100.0f;
}


Node2D::~Node2D()
{
}

void Node2D::updateModelMatrix()
{
}
