#include "GameLevel.h"
#include <fstream>
#include <sstream>
#include "ResourceManager.h"
extern const GLuint SCREEN_WIDTH;
extern const GLuint SCREEN_HEIGHT;

void GameLevel::reset()
{
	this->Bricks.clear();
	this->init(this->data,this->width,this->height);
}

void GameLevel::load(const char* file, float width, float height)
{
	this->width = width;
	this->height = height;
	// 清空过期数据
	this->Bricks.clear();
	// 从文件中加载
	int tileCode;
	GameLevel level;
	std::string line;
	std::ifstream fstream(file);
	std::vector<std::vector<int>> tileData;
	if (fstream)
	{
		while (std::getline(fstream, line)) // 读取关卡文件的每一行
		{
			std::istringstream sstream(line);
			std::vector<int> row;
			while (sstream >> tileCode) // 读取被空格分隔的每个数字
				row.push_back(tileCode);
			tileData.push_back(row);
		}
		if (tileData.size() > 0)
			this->data = tileData;
			this->init(tileData, width, height);
	}
}

void GameLevel::draw(Camera2D* camera)
{
	for (auto i : Bricks) {
		if (!i.destroyed) {
			camera->render(&i);
		}
	}
}

void GameLevel::init(std::vector<std::vector<int>> tileData, float levelWidth, float levelHeight)
{
	// Calculate dimensions
	int height = tileData.size();
	int width = tileData[0].size(); // Note we can index vector at [0] since this function is only called if height > 0
	float breakWidth = levelWidth / width, breakHeight = levelHeight / height;
	// Initialize level tiles based on tileData		
	for (int y = 0; y < height; ++y)
	{
		for (int x = 0; x < width; ++x)
		{
			// Check block type from level data (2D level array)
			if (tileData[y][x] == 1) // Solid
			{
				glm::vec2 pos(breakWidth * x,SCREEN_HEIGHT-breakHeight * y-breakHeight);
				BreakOut breakOut(breakWidth, breakHeight, ResourceManager::GetTexture("block_solid"), ResourceManager::GetShader("spriteShader"));
				breakOut.isSolid = true;
				breakOut.setPosition(glm::vec3(pos, 0.0f));
				breakOut.anchorX = 0;
				breakOut.anchorY = 0;
				this->Bricks.push_back(breakOut);
			}
			else if (tileData[y][x] > 1)	// Non-solid; now determine its color based on level data
			{
				glm::vec3 color = glm::vec3(1.0f); // original: white
				if (tileData[y][x] == 2)
					color = glm::vec3(0.2f, 0.6f, 1.0f);
				else if (tileData[y][x] == 3)
					color = glm::vec3(0.0f, 0.7f, 0.0f);
				else if (tileData[y][x] == 4)
					color = glm::vec3(0.8f, 0.8f, 0.4f);
				else if (tileData[y][x] == 5)
					color = glm::vec3(1.0f, 0.5f, 0.0f);

				glm::vec2 pos(breakWidth * x, SCREEN_HEIGHT - breakHeight * y - breakHeight);
				BreakOut breakOut(breakWidth, breakHeight, ResourceManager::GetTexture("block"), ResourceManager::GetShader("spriteShader"));
				breakOut.isSolid = false;
				breakOut.setPosition(glm::vec3(pos, 0.0f));
				breakOut.setColor(color);
				breakOut.anchorX = 0;
				breakOut.anchorY = 0;
				this->Bricks.push_back(breakOut);
			}
		}
	}
}

bool GameLevel::isCompleted()
{
	return false;
}
