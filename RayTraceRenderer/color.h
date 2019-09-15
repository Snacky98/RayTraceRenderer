#pragma once
#include "pch.h"

class Color : public Tuple3d
{
public:
	//constructors
	Color() : Color(0, 0, 0) {};
	Color(float, float, float);
	//~Color();

	//getters and setters
	void setRed(float);
	float getRed();
	void setGreen(float);
	float getGreen();
	void setBlue(float);
	float getBlue();
};

