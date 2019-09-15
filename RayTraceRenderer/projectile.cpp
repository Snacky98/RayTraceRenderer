#include "pch.h"

Tuple3d* tick(Tuple3d[], Tuple3d[]);

void cannon_fun() {
	Tuple3d projectile[] = { point(0,1,0), vector(1,1,0) };
	Tuple3d environment[] = { vector(0, -0.1, 0), vector(-0.01, 0, 0) };

	while (projectile[0].getY() > 0) {
		std::cout << "position: " << projectile[0].tostring() << "\nvelocity: " << projectile[1].tostring() << "\n\n";
		Tuple3d *newproj = tick(projectile, environment);
		projectile[0] = newproj[0];
		projectile[1] = newproj[1];
	}

	std:cout << "Final position: " << projectile[0].tostring() << "\nFinal velocity: " << projectile[1].tostring() << "\n\n";
}

Tuple3d* tick(Tuple3d proj[], Tuple3d env[]) {
	Tuple3d pos = proj[0] + proj[1];
	Tuple3d vel = proj[1] + env[0] + env[1];

	Tuple3d newproj[2] = { pos, vel };
	return newproj;
}