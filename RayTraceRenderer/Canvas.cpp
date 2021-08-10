#include "pch.h"
#include <fstream>

using namespace std;

constexpr int PPMFileColorDepth = 255;
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

bool Canvas::exportAsPPM(string filename) {
	ofstream outFile(filename);

	if (outFile.fail())
		return false;

	outFile << PPMHeader << endl; //write the header
	outFile << getWidth() << " " << getHeight() << endl;
	outFile << PPMFileColorDepth << endl;

	outFile.close();
	return true;
}