#include "Player.h"
extern const GLuint SCREEN_WIDTH;
extern const GLuint SCREEN_HEIGHT;
Player::Player(float width, float height, Texture2D texture, Shader shader):
	Sprite2D(width, height, texture, shader)
{
	speedX = 400;
}

void Player::update(float dt)
{

}
