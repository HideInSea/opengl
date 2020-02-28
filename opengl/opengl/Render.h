#pragma once
#include "Node.h"
#include "Camera.h"

class Render
{
public:
	Render();
	~Render();

	void render(Node * node,Camera * camera);
};

