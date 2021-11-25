// RayTraceRenderer.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <assert.h>


using namespace std;
using namespace Renderer;

void show_usage(string path);
bool contains_arg(string arg, int argc, char *argv[]);

int main(int argc, char *argv[])
{
	bool foundCommand = false;
	if (argc <= 1) {
		show_usage(argv[0]);
		exit(0);
	}

	if (contains_arg("-h", argc, argv) || contains_arg("--help", argc, argv)) {
		show_usage(argv[0]);
		foundCommand = true;
	}
	if (contains_arg("-t", argc, argv) || contains_arg("--tuple", argc, argv)) {
		Test::test_tuples();
		foundCommand = true;
	}
	if (contains_arg("-n", argc, argv) || contains_arg("--cannon", argc, argv)) {
		Test::cannon_fun();
		foundCommand = true;
	}
	if (contains_arg("-c", argc, argv) || contains_arg("--canvas", argc, argv)) {
		Test::test_canvas();
		foundCommand = true;
	}

	if (!foundCommand) {
		cout << "No valid command found" << endl;
		show_usage(argv[0]);
		exit(1);
	}
}

void show_usage(string path) {
	cout << "Usage: " << path << " <option(s)...>" << endl
		<< "Optons:" << endl
		<< "\t-h, --help\t: Show this message." << endl
		<< "\t-t, --tuple\t: Run tuples test." << endl
		<< "\t-n, --cannon\t: Fun cannon." << endl
		<< "\t-c, --canvas\t: Test canvas operations." << endl << endl;
}

bool contains_arg(string arg, int argc, char* argv[]) {
	for (int i = 1; i < argc; i++) {
		if (string(argv[i]) == arg)
			return true;
	}
	return false;
}