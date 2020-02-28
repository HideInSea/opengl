#include "PerspectiveCamera.h"
#include <glm\gtc\matrix_transform.hpp>

PerspectiveCamera::PerspectiveCamera(float fv, float wh, float near, float far) {
	this->fov = fv;
	this->wh = wh;
	this->far = far;
	this->near = near;
	this->projection= glm::perspective(glm::radians(fv), wh,near,far);
}

void PerspectiveCamera::scroll_callback(GLFWwindow* window, double xoffset, double yoffset)
{
	if (fov >= 1.0f && fov <= 45.0f)
		fov -= yoffset;
	if (fov <= 1.0f)
		fov = 1.0f;
	if (fov >= 45.0f)
		fov = 45.0f;
	this->projection = glm::perspective(glm::radians(fov), wh, near, far);
}
