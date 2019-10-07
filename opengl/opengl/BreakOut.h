#pragma once
#include <glm\detail\type_vec.hpp>
#include "Sprite2D.h"
class BreakOut:
    public Sprite2D 
{
public:
	BreakOut(float width,float height,Texture2D  texture,Shader  shader);
	bool isSolid;
	bool destroyed;
};

