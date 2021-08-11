#include "pch.h"

Color::Color(double red, double green, double blue) {
	this->x = red;
	this->y = green;
	this->z = blue;
	this->w = 0;
}

void Color::setRed(double val) {
	this->x = val;
}

double Color::getRed() {
	return this->x;
}

void Color::setGreen(double val) {
	this->y = val;
}

double Color::getGreen() {
	return this->y;
}

void Color::setBlue(double val) {
	this->z = val;
}

double Color::getBlue() {
	return this->z;
}