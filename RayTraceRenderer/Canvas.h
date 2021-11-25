#pragma once
#include "pch.h"

namespace Renderer {
	class Canvas {
	protected:
		int _height;
		int _width;
		Color *_canv;

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
}

