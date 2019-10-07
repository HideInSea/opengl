#pragma once
#include "Node.h"
class Camera :
	public Node
{
public:
	Camera();
	Camera(glm::vec3 position, glm::vec3 target);
	~Camera();
 	virtual void render(Node* node);

	void lockAt(glm::vec3 target);

	glm::mat4 view;
	glm::mat4 projection;

	glm::vec3 target;//摄像机的观察点
};

