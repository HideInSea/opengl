#include "Ball.h"

Ball::Ball(float width, float height, Texture2D texture, Shader shader) :
	Sprite2D(width,height,texture,shader)
{
	isStuck = true;
	velocity = glm::vec2(200.0f,200.0f);
	radius = 15.0f;
}
