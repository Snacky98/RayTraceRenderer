#include "pch.h"

namespace Renderer {
	using namespace std;

	constexpr int PPMFileColorDepth = 255;
	constexpr int LINE_LEN = 70;
	const string PPMHeader = "P3";


	Canvas::Canvas(int w, int h) :
		_width(w),
		_height(h),
		_canv(new Color[w*h]) {}

	Canvas::~Canvas() {
		delete[] _canv;
	}

	int Canvas::getHeight() {
		return _height;
	}

	int Canvas::getWidth() {
		return _width;
	}

	Color Canvas::getPixel(int x, int y) {
		return _canv[(_width * y) + x];
	}

	void Canvas::writePixel(int x, int y, Color newPix) {
		if ((x >= _width || x  < 0) || (y >= _height || y < 0))
			return; //bounds check

		_canv[(_width * y) + x] = newPix;
	}

	int Canvas::getPixelCount() {
		return _width * _height;
	}

	int Canvas::PPMValue(double value) {
		double calcVal = value;
		if (calcVal > 1.0) {
			calcVal = 1.0;
		} else if (calcVal < 0.0) {
			return 0;
		}

		return static_cast<int>(round(PPMFileColorDepth * calcVal));
	}

	string Canvas::getPPMString() {
		string outputString;
		outputString = outputString + PPMHeader + "\n"; //write the header
		outputString = outputString + to_string(getWidth()) + " " + to_string(getHeight()) + "\n";
		outputString = outputString + to_string(PPMFileColorDepth) + "\n";

		int lineLen = 0;
		int digits;
		int colCtr = 0;
		for (int i = 0; i < getPixelCount(); i++) {
			Color currCol = _canv[i];

			int red = PPMValue(currCol.getRed());
			digits = numDigits(red) + 1; //+1 for the trailing space
			if (lineLen + digits > LINE_LEN) {
				lineLen = 0;
				outputString = outputString + "\n";
			}
			outputString = outputString + to_string(red) + " ";
			lineLen += digits;

			int green = PPMValue(currCol.getGreen());
			digits = numDigits(green) + 1; //+1 for the trailing space
			if (lineLen + digits > LINE_LEN) {
				lineLen = 0;
				outputString = outputString + "\n";
			}
			outputString = outputString + to_string(green) + " ";
			lineLen += digits;

			int blue = PPMValue(currCol.getBlue());
			digits = numDigits(blue) + 1; //+1 for the trailing space
			if (lineLen + digits > LINE_LEN) {
				lineLen = 0;
				outputString = outputString + "\n";
			}
			outputString = outputString + to_string(blue) + " ";
			lineLen += digits;

			// once the row has been outputted, newline
			if (++colCtr == getWidth()) {
				outputString = outputString + "\n";
				lineLen = 0;
				colCtr = 0;
			}
		}
		return outputString;
	}

	/* Private functions */

	int Canvas::numDigits(int num) {
		if (num == 0)
			return 1;

		int count = 0;
		while (num != 0) {
			num /= 10;
			count++;
		}
		return count;
	}
}