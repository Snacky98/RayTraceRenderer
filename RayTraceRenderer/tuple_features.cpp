#include "pch.h"

Tuple3d point(float x, float y, float z) {
	return Tuple3d(x, y, z, 1.0);
}

Tuple3d vector(float x, float y, float z) {
	return Tuple3d(x, y, z, 0.0);
}