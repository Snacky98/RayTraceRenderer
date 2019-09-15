#include "pch.h"

color::color(float red, float green, float blue) {
	this->x = red;
	this->y = green;
	this->z = blue;
	this->w = 0;
}

void color::setRed(float val) {
	this->x = val;
}

float color::getRed() {
	return this->x;
}