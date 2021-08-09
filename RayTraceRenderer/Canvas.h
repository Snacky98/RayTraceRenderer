#pragma once
#include "pch.h"

const string PPMHeader = "P3";

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

	bool exportAsPPM(string);
};

