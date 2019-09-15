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

void color::setGreen(float val) {
	this->y = val;
}

float color::getGreen() {
	return this->y;
}

void color::setBlue(float val) {
	this->z = val;
}

float color::getBlue() {
	return this->z;
}