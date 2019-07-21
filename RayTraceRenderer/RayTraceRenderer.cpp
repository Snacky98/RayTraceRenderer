// RayTraceRenderer.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <assert.h>

using namespace std;
int main(int argc, char *argv[])
{ 
	if (argc != 1) {
		cout << "RayTraceRenderer [modenum]\n"
			<< "1: test tuples mode\n"
			<< "2: fun cannon";
		exit(0);
	}

	switch (atoi(argv[0]))
	{
	case 0:
		test_tuples();
		break;

	case 1:
		cannon_fun();
		break;

	default:
		cout << "not a valid modenumber";
		break;
	}
}
