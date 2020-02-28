#pragma once
#include "Node.h"
class Node2D :
	public Node
{
public:
	Node2D();
	~Node2D();

	virtual void updateModelMatrix();

	float anchorX;
	float anchorY;

	float width;
	float height;

	float angle;

};

