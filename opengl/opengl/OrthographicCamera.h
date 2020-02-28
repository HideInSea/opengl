#pragma once
#include "Camera.h"
class OrthographicCamera :
	public Camera
{
public:
	OrthographicCamera(float left,float right,float top,float bottom,float near,float far);
	~OrthographicCamera();
};

