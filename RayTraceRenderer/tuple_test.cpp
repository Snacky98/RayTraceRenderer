#include "pch.h"
#include <iostream>
#include <assert.h>


namespace Renderer {
	namespace Test {
		using namespace std;
		void test_tuples() {
			error_ctr = 0;

			cout << "Starting tests to assure vectors and points allocate correctly" << endl;
			Tuple3d pon0 = Tuple3d::point(4, -4, 3);
			Tuple3d vec0 = Tuple3d::vector(4, -4, 3);

			assert(pon0.getW() - 1.0 < EPSILON);
			assert(vec0.getW() - 0.0 < EPSILON);
			assert(pon0 == pon0);
			assert(!(pon0 == vec0));

			tuple_operations();

			if (error_ctr < 1) {
				cout << "\ntests passed successfully\n";
			} else {
				cout << "\nthere were " + to_string(error_ctr) + " errors among the tests";
			}
		}

		void tuple_operations() {
			cout << "\nStarting tests to show tuple operations work \n";
			//create our Tuple3D objects we will test on
			Tuple3d pon = Tuple3d::point(3, -2, 5);
			Tuple3d vec = Tuple3d::vector(-2, 3, 1);
			Tuple3d pon1 = Tuple3d::point(3, 2, 1);
			Tuple3d pon2 = Tuple3d::point(5, 6, 7);
			Tuple3d vec1 = Tuple3d::vector(1, 2, 3);
			Tuple3d vec2 = Tuple3d::vector(4, 0, 0);
			Tuple3d vec3 = Tuple3d::vector(1, 2, 3);
			Tuple3d vec4 = Tuple3d::vector(1, 2, 3);
			Tuple3d vec5 = Tuple3d::vector(2, 3, 4);

			if (pon != pon) report_failure("tuples not equal when they should be");
			if (pon == vec) report_failure("tuples equal when they should not be");
			if (pon + vec != Tuple3d::point(1, 1, 6)) report_failure("tuple addition did not work correctly");
			if (pon1 - pon2 != Tuple3d::vector(-2, -4, -6)) report_failure("tuple subtraction did not work correctly");
			if (-pon != Tuple3d::point(-3, 2, -5)) report_failure("tuple negate did not work");
			if (vec * 2.0 != Tuple3d::vector(-4, 6, 2)) report_failure("multiplication by a scalar did not work");
			if (vec / 2.0 != Tuple3d::vector(-1, 1.5, .5)) report_failure("division by a scalar did not work");
			if (vec1.magnitude() - sqrt(14) > EPSILON) report_failure("magnitude not calculated correctly");
			if (vec2.normalize() != Tuple3d::vector(1, 0, 0)) report_failure("normalization doesn't work");
			if (vec3.normalize() != Tuple3d::vector(0.26726, 0.53452, 0.80178)) report_failure("normalization has a bug");
			if (vec4.dot(vec5) != 20) report_failure("dot product broke");
			if (vec4.cross(vec5) != Tuple3d::vector(-1, 2, -1)) report_failure("cross product broke");

			//some color tests
			Color c1a(0.9, 0.6, 0.75);
			Color c1b(0.9, 0.6, 0.75);
			Color c2(0.7, 0.1, 0.25);
			Color multColor1(1.0, 0.2, 0.04);
			Color multColor2(0.9, 1.0, 0.1);

			if (c1a != c1b) report_failure("Colors cannot be found equal");
			if (c1a + c2 != Color(1.6, 0.7, 1.0)) report_failure("Color addition is off");
			if (multColor1 * multColor2 != Color(0.9, 0.6, 0.04)) report_failure("Color multiplication doesn't work");
		}
	} //namespace Test
} //namespace Renderer