#include "BreakOut.h"

BreakOut::BreakOut(float width, float height, Texture2D texture, Shader shader) :
	Sprite2D(width,height,texture,shader)
{
	destroyed = false;
	isSolid = false;
}
