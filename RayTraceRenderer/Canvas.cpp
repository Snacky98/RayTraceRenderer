#include "pch.h"
#include <fstream>

using namespace std;

constexpr int PPMFileColorDepth = 255;
constexpr int LINE_LEN = 70;
const string PPMHeader = "P3";


Canvas::Canvas(int w, int h) {
	this->width = w;
	this->height = h;
	this->canv = new Color[w*h];
}

Canvas::~Canvas() {
	delete canv;
}

int Canvas::getHeight() {
	return this->height;
}

int Canvas::getWidth() {
	return this->width;
}

Color Canvas::getPixel(int row, int col) {
	return canv[width * row + col];
}

void Canvas::writePixel(int row, int col, Color newPix) {
	canv[width * row + col] = newPix;
}

int Canvas::getPixelCount() {
	return this->width * this->height;
}

int Canvas::PPMValue(double value) {
	double calcVal = value;
	if (calcVal > 1.0) {
		calcVal = 1.0;
	} else if (calcVal < 0.0) {
		return 0;
	}

	return static_cast<int>(PPMFileColorDepth * value);
}

bool Canvas::exportAsPPM(string filename) {
	ofstream outFile(filename);

	if (outFile.fail())
		return false;

	outFile << PPMHeader << endl; //write the header
	outFile << getWidth() << " " << getHeight() << endl;
	outFile << PPMFileColorDepth << endl;

	int lineLen = 0;
	int digits;
	for (int i = 0; i < getPixelCount(); i++) {
		Color currCol = canv[i];

		digits = static_cast<int>(floor(log10(currCol.getRed()) + 1) + 1);
		if (lineLen + digits > LINE_LEN) {
			lineLen = 0;
			outFile << endl;
		} else {
			outFile << PPMValue(currCol.getRed()) << " ";
			lineLen += digits;
		}

		digits = static_cast<int>(floor(log10(currCol.getGreen()) + 1));
		if (lineLen + digits > LINE_LEN) {
			lineLen = 0;
			outFile << endl;
		} else {
			outFile << PPMValue(currCol.getGreen()) << " ";
			lineLen += digits;
		}

		digits = static_cast<int>(floor(log10(currCol.getBlue()) + 1));
		if (lineLen + digits > LINE_LEN) {
			lineLen = 0;
			outFile << endl;
		} else {
			outFile << PPMValue(currCol.getBlue()) << " ";
			lineLen += digits;
		}
	}

	outFile.close();
	return true;
}