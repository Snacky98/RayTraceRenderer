#pragma once
#include "pch.h"

using namespace std;
class Tuple3d
{
protected:
	//fields
	float x, y, z; //variables for the vector's x, y, z components
	float w;		//1.0 when this tuple is a point, 0.0 when this tuple is a vector

public:
	//constructors
	Tuple3d() : Tuple3d(0.0, 0.0, 0.0, 0.0) {};
	Tuple3d(float, float, float, float);
	~Tuple3d ();

	//methods
	string tostring();
	bool operator==(const Tuple3d&);
	bool operator!=(const Tuple3d&);
	Tuple3d operator+(const Tuple3d&);
	Tuple3d operator-(const Tuple3d&);
	Tuple3d operator-();
	Tuple3d operator*(float);
	Tuple3d operator*(const Tuple3d&);
	Tuple3d operator/(float);

	float magnitude(); //finds the magnitude of this tuple
	Tuple3d normalize(); //returns the normalized version of this tuple
	float dot(const Tuple3d&); //returns the dot product between this and the other tuple
	Tuple3d cross(const Tuple3d&); // returns a tuple of the cross product of this tuple and the other

	//getters for the various fields
	float getX();
	float getY();
	float getZ();
	float getW();
};
