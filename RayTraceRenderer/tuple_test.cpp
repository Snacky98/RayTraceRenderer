#include "pch.h"
#include <iostream>
#include <assert.h>

int error_ctr;



using namespace std;
void test_tuples() {
	error_ctr = 0;

	cout << "Starting tests to assure vectors and points allocate correctly\n";
	tuple3d pon0 = point(4, -4, 3);
	tuple3d vec0 = vector(4, -4, 3);

	assert(pon0.w - 1.0 < epsilon);
	assert(vec0.w - 0.0 < epsilon);
	assert(pon0 == pon0);
	assert(!(pon0 == vec0));

	tuple_operations();

	if (error_ctr < 1) {
		cout << "\ntests passed successfully\n";
	}
	else {
		cout << "\nthere were " + to_string(error_ctr) + " errors among the tests";
	}
}

void tuple_operations() {
	cout << "\nStarting tests to show tuple operations work \n";
	tuple3d pon = point(3, -2, 5);
	tuple3d vec = vector(-2, 3, 1);
	tuple3d pon1 = point(3, 2, 1);
	tuple3d pon2 = point(5, 6, 7);
	tuple3d vec1 = vector(1, 2, 3);
	tuple3d vec2 = vector(4, 0, 0);
	tuple3d vec3 = vector(1, 2, 3);
	tuple3d vec4 = vector(1, 2, 3);
	tuple3d vec5 = vector(2, 3, 4);

	if (pon != pon) report_failure("tuples not equal when they should be");
	if (pon == vec) report_failure("tuples equal when they should not be");
	if (pon + vec != point(1, 1, 6)) report_failure("tuple addition did not work correctly");
	if (pon1 - pon2 != vector(-2, -4, -6)) report_failure("tuple subtraction did not work correctly");
	if (-pon != point(-3, 2, -5)) report_failure("tuple negate did not work");
	if (vec * 2.0 != vector(-4, 6, 2)) report_failure("multiplication by a scalar did not work");
	if (vec / 2.0 != vector(-1, 1.5, .5)) report_failure("division by a scalar did not work");
	if (vec1.magnitude() - sqrt(14) > epsilon) report_failure("magnitude not calculated correctly");
	if (vec2.normalize() != vector(1, 0, 0)) report_failure("normalization doesn't work");
	if (vec3.normalize() != vector(0.26726, 0.53452, 0.80178)) report_failure("normalization has a bug");
	if (vec4.dot(vec5) != 20) report_failure("dot product broke");
	if (vec4.cross(vec5) != vector(-1, 2, -1)) report_failure("cross product broke");
}

// this very specific and ugly function is to help report and count errors during tests
void report_failure(string errmsg) {
	cerr << errmsg + "\n";
	error_ctr++;
}