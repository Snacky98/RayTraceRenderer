#pragma once
#include "pch.h"

class Color : public Tuple3d
{
public:
	//constructors
	Color() : Color(0, 0, 0) {};
	Color(double, double, double);
	//~Color();

	//getters and setters
	void setRed(double);
	double getRed();
	void setGreen(double);
	double getGreen();
	void setBlue(double);
	double getBlue();
};

