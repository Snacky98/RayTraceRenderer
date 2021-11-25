#include "pch.h"
#include <cmath>

using namespace std;
namespace Renderer {
	//public methods

	Tuple3d::Tuple3d(double x, double y, double z, double w) :
		_x(x),
		_y(y),
		_z(z),
		_w(w) {}

	Tuple3d::~Tuple3d() {}

	string Tuple3d::tostring() {
		string rep = "[" + to_string(_x) + "," + to_string(_y) + ","
			+ to_string(_z) + "," + to_string(_w) + "]";
		return rep;
	}

	bool Tuple3d::operator==(const Tuple3d& other) {
		return (_x - other._x <= EPSILON) && (_y - other._y <= EPSILON) && (_z - other._z <= EPSILON) && (_w - other._w <= EPSILON);
	}

	bool Tuple3d::operator!=(const Tuple3d& other) {
		return !((_x - other._x <= EPSILON) && (_y - other._y <= EPSILON) && (_z - other._z <= EPSILON) && (_w - other._w <= EPSILON));
	}

	Tuple3d Tuple3d::operator+(const Tuple3d& other) {
		return Tuple3d(_x + other._x, _y + other._y, _z + other._z, _w + other._w);
	}

	Tuple3d Tuple3d::operator-(const Tuple3d& other) {
		return Tuple3d(_x - other._x, _y - other._y, _z - other._z, _w - other._w);
	}

	Tuple3d Tuple3d::operator-() {
		return Tuple3d(-_x, -_y, -_z, _w);
	}

	Tuple3d Tuple3d::operator*(double scalar) {
		return Tuple3d(_x * scalar, _y * scalar, _z * scalar, _w * scalar);
	}

	//called a Schur product. returns a new tuple with all the terms straight multiplied together
	Tuple3d Tuple3d::operator*(const Tuple3d& other) {
		return Tuple3d(_x * other._x, _y * other._y, _z * other._z, _w * other._w);
	}

	Tuple3d Tuple3d::operator/(double scalar) {
		return Tuple3d(_x / scalar, _y / scalar, _z / scalar, _w / scalar);
	}

	double Tuple3d::magnitude() {
		double radicand = pow(_x, 2) + pow(_y, 2) + pow(_z, 2) + pow(_w, 2);
		return sqrt(radicand);
	}

	Tuple3d Tuple3d::normalize() {
		double mag = magnitude();
		return Tuple3d(_x / mag, _y / mag, _z / mag, _w / mag);
	}

	double Tuple3d::dot(const Tuple3d& other) {
		return (_x * other._x) + (_y * other._y) + (_z * other._z) + (_w * other._w);
	}

	Tuple3d Tuple3d::cross(const Tuple3d& other) {
		return Tuple3d(_y * other._z - _z * other._y,
			_z * other._x - _x * other._z,
			_x * other._y - _y * other._x, 0.0);
	}

	/* getters for the various fields */

	double Tuple3d::getX() {
		return _x;
	}

	double Tuple3d::getY() {
		return _y;
	}

	double Tuple3d::getZ() {
		return _z;
	}

	double Tuple3d::getW() {
		return _w;
	}

	Tuple3d Tuple3d::point(double x, double y, double z) {
		return Tuple3d(x, y, z, 1.0);
	}

	Tuple3d Tuple3d::vector(double x, double y, double z) {
		return Tuple3d(x, y, z, 0.0);
	}
}