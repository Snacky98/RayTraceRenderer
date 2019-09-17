#pragma once
#include "pch.h"

class Canvas
{
protected:
	Color *canvas;
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
};

