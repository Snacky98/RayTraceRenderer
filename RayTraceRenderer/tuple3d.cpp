#include "pch.h"
#include <cmath>

using namespace std;

//public methods

Tuple3d::Tuple3d(double x, double y, double z, double w) {
	this->x = x;
	this->y = y;
	this->z = z;
	this->w = w;
}

Tuple3d::~Tuple3d()
{
}

string Tuple3d::tostring() {
	string rep = "[" + to_string(x) + "," + to_string(y) + ","
		+ to_string(z) + "," + to_string(w) + "]";
	return rep;
}

bool Tuple3d::operator==(const Tuple3d &other) {
	return (this->x - other.x <= EPSILON) && (this->y - other.y <= EPSILON) && (this->z - other.z <= EPSILON) && (this->w - other.w <= EPSILON);
}

bool Tuple3d::operator!=(const Tuple3d &other) {
	return !((this->x - other.x <= EPSILON) && (this->y - other.y <= EPSILON) && (this->z - other.z <= EPSILON) && (this->w - other.w <= EPSILON));
}

// adds the tuple other to this tuple and returns the result as a new tuple
Tuple3d Tuple3d::operator+(const Tuple3d &other) {
	return Tuple3d(this->x + other.x, this->y + other.y, this->z + other.z, this->w + other.w);
}

// subtracts this tuple from the other tuple and returns a new tuple as the result
Tuple3d Tuple3d::operator-(const Tuple3d &other) {
	return Tuple3d(this->x - other.x, this->y - other.y, this->z - other.z, this->w - other.w);
}

Tuple3d Tuple3d::operator-() {
	return Tuple3d(-this->x, -this->y, -this->z, this->w);
}

Tuple3d Tuple3d::operator*(double scalar) {
	return Tuple3d(this->x * scalar, this->y * scalar, this->z * scalar , this->w * scalar);
}

//called a Schur product. returns a new tuple with all the terms straight multiplied together
Tuple3d Tuple3d::operator*(const Tuple3d& other) {
	return Tuple3d(this->x * other.x, this->y * other.y, this->z * other.z, this->w * other.w);
}

Tuple3d Tuple3d::operator/(double scalar) {
	return Tuple3d(this->x / scalar, this->y / scalar, this->z / scalar, this->w / scalar);
}

double Tuple3d::magnitude() {
	double radicand = pow(this->x, 2) + pow(this->y, 2) + pow(this->z, 2) + pow(this->w, 2);
	return sqrt(radicand);
}

Tuple3d Tuple3d::normalize() {
	double mag = magnitude();
	return Tuple3d(this->x / mag, this->y / mag, this->z / mag, this->w / mag);
}

double Tuple3d::dot(const Tuple3d &other) {
	return (this->x * other.x) + (this->y * other.y) + (this->z * other.z) + (this->w * other.w);
}

Tuple3d Tuple3d::cross(const Tuple3d &other) {
	return Tuple3d(	this->y * other.z - this->z * other.y,
					this->z * other.x - this->x * other.z,
					this->x * other.y - this->y * other.x, 0.0);
}

// getters for the various fields
double Tuple3d::getX() {
	return this->x;
}

double Tuple3d::getY() {
	return this->y;
}

double Tuple3d::getZ() {
	return this->z;
}

double Tuple3d::getW() {
	return this->w;
}