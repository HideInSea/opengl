#pragma once
#include "Sprite2D.h"
class Player :
	public Sprite2D
{
public:
	Player(float width, float height, Texture2D  texture, Shader  shader);
	void update(float dt);
	bool leftPressed;
	bool rightPressed;
	float speedX;
};

