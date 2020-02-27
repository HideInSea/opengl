#include "Game.h"
#include "ResourceManager.h"
#include <GLFW\glfw3.h>
extern const GLuint SCREEN_WIDTH;
extern const GLuint SCREEN_HEIGHT;
Game::Game(GLuint width, GLuint height)
{
}

Game::~Game()
{
}

void Game::Init()
{
	
	
	ResourceManager::LoadTexture("../texture/block.png", GL_TRUE, "block");
	ResourceManager::LoadTexture("../texture/block_solid.png", GL_TRUE, "block_solid");
	
	ResourceManager::LoadTexture("../texture/face.png", GL_TRUE, "face");
	ResourceManager::LoadTexture("../texture/background.jpg", GL_TRUE, "background");
	ResourceManager::LoadTexture("../texture/paddle.png", GL_TRUE, "paddle");

	ResourceManager::LoadShader("../shaders/texture2d.vs", "../shaders/texture2d.fs", nullptr, "spriteShader");
	ResourceManager::LoadShader("../shaders/light.vs", "../shaders/light.fs", nullptr, "lightShader");

	//���عؿ�
	//this->gameLevel = new GameLevel();
	//this->gameLevel->load("../levels/one.level", SCREEN_WIDTH, SCREEN_HEIGHT*0.5f);


	//this->render = new Camera2D();
	this->render = new Camera3D(glm::vec3(3.0f,3.0f,5.0f),glm::vec3(0),45.0f,(float)SCREEN_WIDTH/(float)SCREEN_HEIGHT);
	this->render->shader = ResourceManager::GetShader("lightShader");
	this->render->lightColor = glm::vec3(1.0f);//���
	this->render->lightPos = glm::vec3(5.0f,3.0f,-6.0f);//���

	//����ͼƬ
	//this->sprite = new Sprite2D(SCREEN_WIDTH, SCREEN_HEIGHT, ResourceManager::GetTexture("background"), ResourceManager::GetShader("spriteShader"));
	//this->sprite->anchorX = 0;

	//this->sprite->anchorY = 0;
	 

	////���
	//this->player = new Player(120, 30, ResourceManager::GetTexture("paddle"), ResourceManager::GetShader("spriteShader"));
	//this->player->anchorY = 0;
	//this->player->setPosition(glm::vec3(SCREEN_WIDTH*0.5f,0,0));

	////��
	//this->ball = new Ball(30.0f,30.0f, ResourceManager::GetTexture("face"), ResourceManager::GetShader("spriteShader"));
	//this->ball->setPosition(glm::vec3(SCREEN_WIDTH*0.5f,45.0f,0));
	this->cube = new Cube(glm::vec3(0),glm::vec3(2.0f),  ResourceManager::GetShader("lightShader"), ResourceManager::GetTexture("block"));
	//this->two = new Cube(glm::vec3(1.0f,1.0f,0), glm::vec3(1.0f), ResourceManager::GetShader("spriteShader"), ResourceManager::GetTexture("block"));
}

void Game::ProcessInput(GLfloat dt)
{

}

void Game::Update(GLfloat dt)
{
	return;

	if (Keys[GLFW_KEY_LEFT]) {
		player->setPosition(glm::vec3(player->x - dt * player->speedX, player->y, player->z));
	}

	if (Keys[GLFW_KEY_RIGHT]) {
		player->setPosition(glm::vec3(player->x + dt * player->speedX, player->y, player->z));
	}

	//�߽���
	if (player->width * 0.5f + player->x > SCREEN_WIDTH) {
		player->setPosition(glm::vec3(SCREEN_WIDTH - player->width * 0.5f, player->y, player->z));
	}

	if (player->x - player->width * 0.5f < 0) {
		player->setPosition(glm::vec3(player->width * 0.5f, player->y, player->z));
	}

	if (Keys[GLFW_KEY_SPACE]) {
		ball->isStuck = false;
	}

	if (ball->isStuck) {
		ball->setPosition(glm::vec3(player->x,ball->y,ball->z));
	}
	else {
		ball->setPosition(ball->position+glm::vec3(ball->velocity*dt,0));

		doCollsions();

		if (ball->x + ball->radius > SCREEN_WIDTH) {
			ball->velocity.x *= -1;
			ball->setPosition(glm::vec3(SCREEN_WIDTH-ball->radius,ball->y,ball->z));
		}
		else if (ball->x - ball->radius < 0) {
			ball->velocity.x *= -1;
			ball->setPosition(glm::vec3(ball->radius, ball->y, ball->z));
		}
		else if (ball->y+ball->radius>SCREEN_HEIGHT) {
			ball->velocity.y *= -1;
			ball->setPosition(glm::vec3(ball->x, SCREEN_HEIGHT-ball->radius, ball->z));
		}
		else if (ball->y - ball->radius < 0) {
			reset();
		}
	}

	
}

void Game::Render()
{
	this->render->render(this->cube);
	//this->render->render(this->two);
	
	//this->gameLevel->draw(this->render);



	//this->render->render(this->player);

	//this->render->render(this->ball);
}

bool Game::checkCollsions(glm::vec4 boxOne, glm::vec4 boxTwo)
{
	// x�᷽����ײ��
	bool collisionX = boxOne.x + boxOne.z >= boxTwo.x &&
		boxTwo.x + boxTwo.z >= boxOne.x;
	// y�᷽����ײ��
	bool collisionY = boxOne.y + boxOne.w >= boxTwo.y &&
		boxTwo.y + boxTwo.w >= boxOne.y;
	// ֻ��������������ײʱ����ײ
	return collisionX && collisionY;
}

Collision Game::checkCollsions(glm::vec4 boxOne, glm::vec3 circleTwo)
{
	// ��ȡԲ������ 
	glm::vec2 center(circleTwo.x,circleTwo.y);
	// ����AABB����Ϣ�����ġ���߳���
	glm::vec2 aabb_half_extents(boxOne.z / 2, boxOne.w / 2);
	glm::vec2 aabb_center(
		boxOne.x + aabb_half_extents.x,
		boxOne.y + aabb_half_extents.y
	);
	// ��ȡ�������ĵĲ�ʸ��
	glm::vec2 difference = center - aabb_center;
	glm::vec2 clamped = glm::clamp(difference, -aabb_half_extents, aabb_half_extents);
	// AABB_center����clamped�����͵õ�����ײ���Ͼ���Բ����ĵ�closest
	glm::vec2 closest = aabb_center + clamped;
	// ���Բ��center�������closest��ʸ�����ж��Ƿ� length <= radius
	difference = closest - center;
	if (glm::length(difference) <= circleTwo.z)
		return std::make_tuple(GL_TRUE, VectorDirection(difference), difference);
	else
		return std::make_tuple(GL_FALSE, UP, glm::vec2(0, 0));
}

Direction Game::VectorDirection(glm::vec2 target)
{
	glm::vec2 compass[] = {
		glm::vec2(0.0f, 1.0f),  // ��
		glm::vec2(1.0f, 0.0f),  // ��
		glm::vec2(0.0f, -1.0f), // ��
		glm::vec2(-1.0f, 0.0f)  // ��
	};
	GLfloat max = 0.0f;
	GLuint best_match = -1;
	for (GLuint i = 0; i < 4; i++)
	{
		GLfloat dot_product = glm::dot(glm::normalize(target), compass[i]);
		if (dot_product > max)
		{
			max = dot_product;
			best_match = i;
		}
	}
	return (Direction)best_match;
}

void Game::doCollsions()
{
	for (auto& box : this->gameLevel->Bricks)
	{
		if (!box.destroyed)
		{
			Collision collision = checkCollsions(glm::vec4(box.x,box.y,box.width,box.height), glm::vec3(ball->x,ball->y,ball->radius));
			if (std::get<0>(collision)) // ���collision �� true
			{
				// ���ש�鲻��ʵ�ľ�����ש��
				if (!box.isSolid)
					box.destroyed = GL_TRUE;
				// ��ײ����
				Direction dir = std::get<1>(collision);
				glm::vec2 diff_vector = std::get<2>(collision);
				if (dir == LEFT || dir == RIGHT) // ˮƽ������ײ
				{
					ball->velocity.x *= -1; // ��תˮƽ�ٶ�
					// �ض�λ
					GLfloat penetration = ball->radius - std::abs(diff_vector.x);
					if (dir == LEFT)
						ball->setPosition(glm::vec3(ball->x + penetration, ball->y, ball->z)); // ��������
					else
						ball->setPosition(glm::vec3(ball->x-penetration,ball->y,ball->z)); // ��������
				}
				else // ��ֱ������ײ
				{
					ball->velocity.y *= -1;// ��ת��ֱ�ٶ�
					// �ض�λ
					GLfloat penetration = ball->radius - std::abs(diff_vector.y);
					if (dir == UP)
						ball->setPosition(glm::vec3(ball->x,ball->y-penetration,ball->z)); // ��������
					else
						ball->setPosition(glm::vec3(ball->x, ball->y + penetration, ball->z)); // ��������
				}
			}
		}
	}

	//�����ҵ���ײ
	Collision result = checkCollsions(glm::vec4(player->x-player->width*0.5f, player->y, player->width, player->height), glm::vec3(ball->x, ball->y, ball->radius));
	if (!ball->isStuck && std::get<0>(result))
	{
		// ��������˵�����ĸ�λ�ã������������ĸ�λ�����ı��ٶ�
		GLfloat centerBoard = player->x;
		GLfloat distance = ball->x - centerBoard;
		GLfloat percentage = distance /player->width*0.5f;
		// ���ݽ���ƶ�
		GLfloat strength = 2.0f;
		glm::vec2 oldVelocity = ball->velocity;
		ball ->velocity.x = 200 * percentage * strength;
		ball->velocity.y *= -1;
		ball->velocity = glm::normalize(ball->velocity) * glm::length(oldVelocity);
	}
}

void Game::reset()
{
	//���
	this->player->setPosition(glm::vec3(SCREEN_WIDTH * 0.5f, 0, 0));

	//��
	this->ball->setPosition(glm::vec3(SCREEN_WIDTH * 0.5f, 45.0f, 0));
	this->ball->isStuck = true;
	this->ball->velocity = glm::vec2(200.0f,200.0f);

	this->gameLevel->reset();
}
