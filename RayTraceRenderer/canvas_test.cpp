#include "pch.h"

namespace Renderer {
	namespace Test {

		using namespace std;
		void test_canvas() {
			cout << "Running canvas tests" << endl;

			Canvas canv1(5, 3);
			canv1.writePixel(0, 0, Color(1.5, 0, 0));
			canv1.writePixel(2, 1, Color(0, 0.5, 0));
			canv1.writePixel(4, 2, Color(-0.5, 0, 1));
			string canv1PPM = canv1.getPPMString();
			cout << canv1PPM;

			Canvas canv2(10, 2);
			Color initColor(1, 0.8, 0.6);
			for (int x = 0; x < canv2.getWidth(); x++) {
				for (int y = 0; y < canv2.getHeight(); y++) {
					canv2.writePixel(x, y, initColor);
				}
			}
			string canv2PPM = canv2.getPPMString();
			cout << canv2PPM;

			if (error_ctr > 0) {
				cout << "tests finished with " << error_ctr << " errors" << endl;
			} else {
				cout << "tests finished successfully" << endl;
			}
		}
	}
}
