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
		Canvas(int w, int h);
		~Canvas();

		int getHeight();
		int getWidth();
		void writePixel(int x, int y, Color newCol);
		Color getPixel(int x, int y);
		int getPixelCount();

		int PPMValue(double);
		string getPPMString();

	private:
		int numDigits(int number);
	};
}

