#pragma once
#include "pch.h"

class Canvas
{
protected:
	Color *canv;
	int height;
	int width;

public:
	Canvas() : Canvas(0, 0) {};
	Canvas(int, int);
	~Canvas();

	int getHeight();
	int getWidth();
	void writePixel(int, int, Color);
	Color getPixel(int, int);
	int getPixelCount();

	int PPMValue(double);
	bool exportAsPPM(string);
};

