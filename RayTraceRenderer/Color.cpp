#include "pch.h"

namespace Renderer {
	Color::Color(double red, double green, double blue) :
		Tuple3d(red, green, blue, 0.0) {}

	Color::~Color() {}

	/* Getters. Essentially renaming the getters in Tuple3d to make them more sensical as colors */

	double Color::getRed() {
		return getX();
	}

	double Color::getGreen() {
		return getY();
	}

	double Color::getBlue() {
		return getZ();
	}
}