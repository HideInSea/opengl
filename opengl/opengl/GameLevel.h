#pragma once
#include <vector>
#include "BreakOut.h"
#include "Camera2D.h"
class GameLevel
{
public:
	std::vector<BreakOut> Bricks;
	std::vector<std::vector<int>> data;
	void reset();
	void load(const char* file, float width, float height);
	void draw(Camera2D * camera);
	void init(std::vector<std::vector<int>> tileData,float width,float height);
	bool isCompleted();
	float width;
	float height;
};

