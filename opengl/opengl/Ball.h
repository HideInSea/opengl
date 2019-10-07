#pragma once
#include "Sprite2D.h"
class Ball :
	public Sprite2D
{
public:
	Ball(float width, float height, Texture2D texture, Shader shader);
	
	float radius;
	bool isStuck;

	glm::vec2 velocity;
};

