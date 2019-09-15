#pragma once
#include "pch.h"

using namespace std;
class tuple3d
{
protected:
	//fields
	float x, y, z; //variables for the vector's x, y, z components
	float w;		//1.0 when this tuple is a point, 0.0 when this tuple is a vector

public:
	//constructors
	tuple3d() : tuple3d(0, 0, 0, 0) {};
	tuple3d(float,float,float,float);
	~tuple3d ();

	//methods
	string tostring();
	bool operator==(const tuple3d&);
	bool operator!=(const tuple3d&);
	tuple3d operator+(const tuple3d&);
	tuple3d operator-(const tuple3d&);
	tuple3d operator-();
	tuple3d operator*(float);
	//tuple3d operator*(const tuple3d&);
	tuple3d operator/(float);

	float magnitude(); //finds the magnitude of this tuple
	tuple3d normalize(); //returns the normalized version of this tuple
	float dot(const tuple3d&); //returns the dot product between this and the other tuple
	tuple3d cross(const tuple3d&); // returns a tuple of the cross product of this tuple and the other

	//getters for the various fields
	float getX();
	float getY();
	float getZ();

};

