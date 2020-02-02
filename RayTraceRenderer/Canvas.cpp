#include "pch.h"

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