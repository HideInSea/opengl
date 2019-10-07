#pragma once

#include <glad\glad.h>
#include "Sprite2D.h"
#include "Camera2D.h"
#include "GameLevel.h"
#include "Player.h"
#include "Ball.h"
#include "Camera3D.h"
#include "Cube.h"

enum Direction {
	UP,
	RIGHT,
	DOWN,
	LEFT
};

// 代表了游戏的当前状态
enum GameState {
	GAME_ACTIVE,
	GAME_MENU,
	GAME_WIN
};

typedef std::tuple<GLboolean, Direction, glm::vec2> Collision;


class Game
{
public:
	// 游戏状态
	GameState  State;
	GLboolean  Keys[1024];
	GLuint     Width, Height;
	// 构造函数/析构函数
	Game(GLuint width, GLuint height);
	~Game();
	// 初始化游戏状态（加载所有的着色器/纹理/关卡）
	void Init();
	// 游戏循环
	void ProcessInput(GLfloat dt);
	void Update(GLfloat dt);
	void Render();

	//包围盒与包围盒的碰撞检测
	bool checkCollsions(glm::vec4 boxOne, glm::vec4 boxTwo);
	//包围盒与园的碰撞检测
	Collision  checkCollsions(glm::vec4 boxOne, glm::vec3 circleTwo);

	Direction VectorDirection(glm::vec2 target);

	void doCollsions();

	void reset();

	Sprite2D* sprite;

	Texture2D texture;
	Shader shader;

	GLuint VAO;

	Camera3D* render;

	GameLevel* gameLevel;

	Player* player;

	Ball* ball;

	Cube* cube;
	Cube* two;
};

