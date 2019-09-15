#include "pch.h"

Color::Color(float red, float green, float blue) {
	this->x = red;
	this->y = green;
	this->z = blue;
	this->w = 0;
}

void Color::setRed(float val) {
	this->x = val;
}

float Color::getRed() {
	return this->x;
}

void Color::setGreen(float val) {
	this->y = val;
}

float Color::getGreen() {
	return this->y;
}

void Color::setBlue(float val) {
	this->z = val;
}

float Color::getBlue() {
	return this->z;
}