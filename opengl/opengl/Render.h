#pragma once
#include "Node.h"
#include "Camera.h"
#include "Model.h"

class Render
{
public:
	Render();
	~Render();

	void render(Node * node,Camera * camera);
	void renderModel(Model * mode, Camera * camera,Shader * shader);
	void renderModelWithLight(Model * model, Camera * camera, Shader * shader);
};

