#pragma once
#include "pch.h"

using namespace std;
class Tuple3d
{
protected:
	//fields
	double x, y, z; //variables for the vector's x, y, z components
	double w;		//1.0 when this tuple is a point, 0.0 when this tuple is a vector

public:
	//constructors
	Tuple3d() : Tuple3d(0.0, 0.0, 0.0, 0.0) {};
	Tuple3d(double, double, double, double);
	~Tuple3d ();

	//methods
	string tostring();
	bool operator==(const Tuple3d&);
	bool operator!=(const Tuple3d&);
	Tuple3d operator+(const Tuple3d&);
	Tuple3d operator-(const Tuple3d&);
	Tuple3d operator-();
	Tuple3d operator*(double);
	Tuple3d operator*(const Tuple3d&);
	Tuple3d operator/(double);

	double magnitude(); //finds the magnitude of this tuple
	Tuple3d normalize(); //returns the normalized version of this tuple
	double dot(const Tuple3d&); //returns the dot product between this and the other tuple
	Tuple3d cross(const Tuple3d&); // returns a tuple of the cross product of this tuple and the other

	//getters for the various fields
	double getX();
	double getY();
	double getZ();
	double getW();
};
