#include "pch.h"

tuple3d* tick(tuple3d[], tuple3d[]);

void cannon_fun() {
	tuple3d projectile[] = { point(0,1,0), vector(1,1,0) };
	tuple3d environment[] = { vector(0, -0.1, 0), vector(-0.01, 0, 0) };

	while (projectile[0].getY() > 0) {
		std::cout << "position: " << projectile[0].tostring() << "\nvelocity: " << projectile[1].tostring() << "\n\n";
		tuple3d *newproj = tick(projectile, environment);
		projectile[0] = newproj[0];
		projectile[1] = newproj[1];
	}

	std:cout << "Final position: " << projectile[0].tostring() << "\nFinal velocity: " << projectile[1].tostring() << "\n\n";
}

tuple3d* tick(tuple3d proj[], tuple3d env[]) {
	tuple3d pos = proj[0] + proj[1];
	tuple3d vel = proj[1] + env[0] + env[1];

	tuple3d newproj[2] = { pos, vel };
	return newproj;
}