#pragma once
#include "Camera.h"
class PerspectiveCamera :
	public Camera
{
public:
	PerspectiveCamera(float fv,float wh,float near,float far);
	~PerspectiveCamera() {};
	float near;
	float far;
	float fov;
	float wh;
	virtual void scroll_callback(GLFWwindow* window, double xoffset, double yoffset);
};

