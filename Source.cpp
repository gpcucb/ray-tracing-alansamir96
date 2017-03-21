
#include "rgb.h"
#include "camara.h"
#include "vector.h"
#include "rayo.h"
#include "esfera.h"

int main()
{
	/*
	vector v1(3, 5, 1), v2(1, 1, 1), v3;
	v1.show();
	v2.show();
	v3 = v1.suma(v2);
	v3.show();
	v3 = v1.resta(v2);
	v3.show();
	*/

	/*
	vector eje(1, 2, -6), center(1, 2, -4), up(0, 1, 0);
	float fov = 39.0;
	float df = 1.0;
	float nx = 640.0;
	float ny = 480.0;
	camara camara(eje, center, up, nx, ny);

	for (int i = 0; i < nx; i++)
	{
		for (int j = 0; j < ny; j++)
		{
		//	camara.DireccionRayo(i, j, nx, ny).show();
		}
	}
	*/


	vector e(278, 273, -800);
	vector center(278, 273, -700);
	vector	up(0, 1, 0);
	vector direc;
	float	fov = 39.31;
	float	df = 0.035;
	float	nx = 640.0;
	float	ny = 480.0;

	vector posicion(370, 120, 370);
	float radio = 120;
	camara camara(e, center, up, fov, df);
	esfera esfera(posicion,radio);

	for (int i = 0; i < nx; i++)
	{
		for (int j = 0; j < ny; j++)
		{
			direc = camara.DireccionRayo(i, j, nx, ny);
			rayo ray(e, direc);
			esfera.interseccion(ray);
		}
	}

	return 0;
}