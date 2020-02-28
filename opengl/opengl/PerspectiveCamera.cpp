#include "PerspectiveCamera.h"
#include <glm\gtc\matrix_transform.hpp>

PerspectiveCamera::PerspectiveCamera(float fv, float wh, float near, float far) {
	this->projection= glm::perspective(glm::radians(fv), wh,near,far);
}