#pragma once
#include "Camera.h"
class PerspectiveCamera :
	public Camera
{
public:
	PerspectiveCamera(float fv,float wh,float near,float far);
	~PerspectiveCamera() {};
};

