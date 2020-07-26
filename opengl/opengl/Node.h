#pragma once
#include"glm\glm.hpp"

class Node
{


public:
	glm::vec3 position;
	glm::vec3 color;
	glm::vec3 angle;
	glm::vec3 scale;

	float opacity;

	float angleX;
	float angleY;
	float angleZ;

	float scaleX;
	float scaleY;
	float scaleZ;

	float x;
	float y;
	float z;

public:
	Node();

	~Node();

	virtual void draw();
	virtual void update(float dt);

	void updateLocalMatrix();
	void updateWorldMatrix();

	glm::mat4 getLocalMatrix();
	glm::mat4 getWorldMatrix();

	void setPosition(glm::vec3 position) { this->position = position; x = position.x; y = position.y; z = position.z; };
	void setScale(glm::vec3 scale) { this->scale = scale; scaleX = scale.x; scaleY = scale.y; scaleZ = scale.z; };
	void setAngle(glm::vec3 angle) { this->angle = angle; angleX = angle.x; angleY = angle.y; angleZ = angle.z; };
	void setColor(glm::vec3 color) { this->color = color; };
	void setOpacity(float opacity) { this->opacity = opacity; };
	void setPositionX(float x) { this->x = x; }
	void setPositionY(float y) { this->y = y; }
	void setPositionZ(float z) { this->z = z; }
	void setScaleX(float x) { this->scaleX = x; }
	void setScaleY(float y) { this->scaleY = y; }
	void setScaleZ(float z) { this->scaleZ = z; }
	void setAngleX(float x) { this->angleX = x; }
	void setAngleY(float y) { this->angleY = y; }
	void setAngleZ(float z) { this->angleZ = z; }

protected:

	glm::mat4 localMatrix;
	glm::mat4 worldMatrix;
};

