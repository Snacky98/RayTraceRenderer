#pragma once
#include "pch.h"

class color : public tuple3d
{
public:
	//constructors
	color() : color(0, 0, 0) {};
	color(float, float, float);
	//~color();

	//getters and setters
	void setRed(float);
	float getRed();
	void setGreen(float);
	float getGreen();
	void setBlue(float);
	float getBlue();
};

