// Raytracer.cpp : アプリケーションのエントリ ポイントを定義します。
//

#include "stdafx.h"
#include <iostream>
#include "vector.h"
#include "color.h"


int main()
{
	const int nx = 200;
	const int ny = 100;
	std::cout << "P3\n" << nx << " " << ny << "\n255\n";
	const vec3 lower_left_corner(-2.0, -1.0, -1.0);
	const vec3 horizontal(4.0, 0.0, 0.0);
	const vec3 vertical(0.0, 2.0, 0.0);
	const vec3 origin(0.0, 0.0, 0.0);
	for (int j = ny - 1; j >= 0; j--)
	{
		for (int i = 0; i < nx; i++)
		{
			const float u = float(i) / float(nx);
			const float v = float(j) / float(ny);
			const ray r(origin, lower_left_corner + u * horizontal +
			      v * vertical);
			vec3 col = color(r);
			const int ir = int(255.99 * col[0]);
			const int ig = int(255.99 * col[1]);
			const int ib = int(255.99 * col[2]);
			std::cout << ir << " " << ig << " " << ib << "\n";
		}
	}
}
