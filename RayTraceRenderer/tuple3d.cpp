#include "pch.h"
#include <cmath>

using namespace std;

//public methods

tuple3d::tuple3d(float x, float y, float z, float w) {
	this->x = x;
	this->y = y;
	this->z = z;
	this->w = w;
}

tuple3d::~tuple3d()
{
}

string tuple3d::tostring() {
	string rep = "[" + to_string(x) + "," + to_string(y) + ","
		+ to_string(z) + "," + to_string(w) + "]";
	return rep;
}

bool tuple3d::operator==(const tuple3d &other) {
	return (this->x - other.x <= epsilon) && (this->y - other.y <= epsilon) && (this->z - other.z <= epsilon) && (this->w - other.w <= epsilon);
}

bool tuple3d::operator!=(const tuple3d &other) {
	return !((this->x - other.x <= epsilon) && (this->y - other.y <= epsilon) && (this->z - other.z <= epsilon) && (this->w - other.w <= epsilon));
}

// adds the tuple other to this tuple and returns the result as a new tuple
tuple3d tuple3d::operator+(const tuple3d &other) {
	return tuple3d(this->x + other.x, this->y + other.y, this->z + other.z, this->w + other.w);
}

// subtracts this tuple from the other tuple and returns a new tuple as the result
tuple3d tuple3d::operator-(const tuple3d &other) {
	return tuple3d(this->x - other.x, this->y - other.y, this->z - other.z, this->w - other.w);
}

tuple3d tuple3d::operator-() {
	return tuple3d(-this->x, -this->y, -this->z, this->w);
}

tuple3d tuple3d::operator*(float scalar) {
	return tuple3d(this->x * scalar, this->y * scalar, this->z * scalar , this->w * scalar);
}

tuple3d tuple3d::operator/(float scalar) {
	return tuple3d(this->x / scalar, this->y / scalar, this->z / scalar, this->w / scalar);
}

float tuple3d::magnitude() {
	float radicand = pow(this->x, 2) + pow(this->y, 2) + pow(this->z, 2) + pow(this->w, 2);
	return sqrt(radicand);
}

tuple3d tuple3d::normalize() {
	float mag = magnitude();
	return tuple3d(this->x / mag, this->y / mag, this->z / mag, this->w / mag);
}

float tuple3d::dot(const tuple3d &other) {
	return (this->x * other.x) + (this->y * other.y) + (this->z * other.z) + (this->w * other.w);
}

tuple3d tuple3d::cross(const tuple3d &other) {
	return tuple3d(this->y * other.z - this->z * other.y,
		this->z * other.x - this->x * other.z,
		this->x * other.y - this->y * other.x, 0.0);
}

// getters for the various fields
float tuple3d::getX() {
	return this->x;
}

float tuple3d::getY() {
	return this->y;
}

float tuple3d::getZ() {
	return this->z;
}