#pragma once
#include"glm\glm.hpp"
class Node
{
public:
	Node();
	Node(glm::vec3 position);

	~Node();
	void setPosition(glm::vec3 position) { this->position = position; x = position.x; y = position.y; z = position.z; };
	void setColor(glm::vec3 color) { this->color = color; }
	void init(glm::vec3 position);
	virtual void draw();
	virtual void update(float dt);

	glm::mat4 getModelMatrix();

	glm::vec3 position;

	float x;
	float y;
	float z;

	glm::vec3 color;

	float opacity;

	float width;
	float height;

	float anchorX;
	float anchorY;

	float angle;

	float scaleX;
	float scaleY;
	float scaleZ;

protected:
	glm::mat4 model;
};

