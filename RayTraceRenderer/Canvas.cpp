#include "pch.h"

Canvas::Canvas(int w, int h) {
	this->width = w;
	this->height = h;
	this->canvas = new Color[w*h];
}

Canvas::~Canvas() {
	delete canvas;
}

int Canvas::getHeight() {
	return this->height;
}

int Canvas::getWidth() {
	return this->width;
}

Color Canvas::getPixel(int row, int col) {
	return canvas[width * row + col];
}

void Canvas::writePixel(int row, int col, Color newPix) {
	canvas[width * row + col] = newPix;
}