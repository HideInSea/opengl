#include "OrthographicCamera.h"
#include <glm\gtc\matrix_transform.hpp>

OrthographicCamera::OrthographicCamera(float left, float right, float bottom, float top, float near, float far)
{
	this->projection = glm::ortho(left,right,bottom,top, near,far);
}

OrthographicCamera::~OrthographicCamera()
{
}
