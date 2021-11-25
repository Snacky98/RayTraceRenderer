#pragma once
#include "pch.h"

namespace Renderer {
	class Color : public Tuple3d {
	public:
		//constructors
		Color() : Color(0, 0, 0) {};
		Color(double, double, double);
		~Color();

		//getters
		double getRed();
		double getGreen();
		double getBlue();
	};
}

