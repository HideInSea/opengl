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

// ��������Ϸ�ĵ�ǰ״̬
enum GameState {
	GAME_ACTIVE,
	GAME_MENU,
	GAME_WIN
};

typedef std::tuple<GLboolean, Direction, glm::vec2> Collision;


class Game
{
public:
	// ��Ϸ״̬
	GameState  State;
	GLboolean  Keys[1024];
	GLuint     Width, Height;
	// ���캯��/��������
	Game(GLuint width, GLuint height);
	~Game();
	// ��ʼ����Ϸ״̬���������е���ɫ��/����/�ؿ���
	void Init();
	// ��Ϸѭ��
	void ProcessInput(GLfloat dt);
	void Update(GLfloat dt);
	void Render();

	//��Χ�����Χ�е���ײ���
	bool checkCollsions(glm::vec4 boxOne, glm::vec4 boxTwo);
	//��Χ����԰����ײ���
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

