
#include "rgb.h"
#include "camara.h"

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
			camara.DireccionRayo(i, j, nx, ny).show();
		}
	}

	return 0;
}