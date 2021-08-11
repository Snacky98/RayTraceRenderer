#include "pch.h"

Tuple3d point(double x, double y, double z) {
	return Tuple3d(x, y, z, 1.0);
}

Tuple3d vector(double x, double y, double z) {
	return Tuple3d(x, y, z, 0.0);
}