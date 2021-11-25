#include "pch.h"
#include <fstream>

namespace Renderer {
	namespace Test {

		Tuple3d* tick(Tuple3d[], Tuple3d[]);

		void cannon_fun() {
			int iter = 0;
			Canvas outCanvas(20, 8);
			Color markColor(1, 0, 0);

			Tuple3d projectile[] = { Tuple3d::point(0,1,0), Tuple3d::vector(1,1,0) };
			Tuple3d environment[] = { Tuple3d::vector(0, -0.1, 0), Tuple3d::vector(-0.01, 0, 0) };

			int x = int(round(projectile[0].getX()));
			int y = outCanvas.getHeight() - int(round(projectile[0].getY()));
			outCanvas.writePixel(x, y, markColor);
			while (projectile[0].getY() > 0) {
				std::cout << "position: " << projectile[0].tostring() << "\nvelocity: " << projectile[1].tostring() << "\n\n";
				Tuple3d* newproj = tick(projectile, environment);
				projectile[0] = newproj[0];
				projectile[1] = newproj[1];
				delete[] newproj;
				x = int(round(projectile[0].getX()));
				y = outCanvas.getHeight() - int(round(projectile[0].getY()));
				outCanvas.writePixel(x, y, markColor);
				iter++;
			}

			std::cout << "Final position: " << projectile[0].tostring() << "\nFinal velocity: " << projectile[1].tostring() << " after " << iter << " iterations\n\n";

			string ppmString = outCanvas.getPPMString();
			std::cout << ppmString;
			ofstream outFile;
			outFile.open("D:/DevBox/Renderer Outputs/outfile.ppm"); //TODO: naughty absolute file path
			outFile << ppmString;
			outFile.close();
		}

		Tuple3d* tick(Tuple3d proj[], Tuple3d env[]) {
			Tuple3d pos = proj[0] + proj[1];
			Tuple3d vel = proj[1] + env[0] + env[1];

			Tuple3d* newproj = new Tuple3d[2]{ pos, vel };
			return newproj;
		}
	}
}