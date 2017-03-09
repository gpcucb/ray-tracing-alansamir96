#include "vector.h"



vector::vector()
{
	x = 0;
	y = 0;
	z = 0;
}

vector::vector(float x1, float y1, float z1)
{
	this->x = x1;
	this->y = y1;
	this->z = z1;
}


vector::~vector()
{
}

void vector::show()
{
	cout << "(" << x << "," << y << "," << z << ")" << " ";
}



vector vector::suma(vector vec)
{
	vector vecres;
	float x1, y1, z1;
	vecres.x = this->x + vec.x;
	vecres.y = this->y + vec.y;
	vecres.z = this->z + vec.z;
	return vecres;
}

vector vector::resta(vector vec)
{
	vector vecres;
	float x1, y1, z1;
	vecres.x = this->x - vec.x;
	vecres.y = this->y - vec.y;
	vecres.z = this->z - vec.z;
	return vecres;
}

float vector::modulo()
{
	float xa, ya, za, res;
	xa = this->x*x;
	ya = this->y*y;
	za = this->z*z;
	res = sqrt(xa + ya + za);
	return res;
}

vector vector::producto_vectorial(vector ve)
{
	float xa, ya, za;
	vector vecres;
	vecres.x = (this->y * ve.z) - (ve.y * this->z);
	vecres.y = (this->x * ve.z) - (ve.x * this->z);
	vecres.z = (this->x * ve.y) - (ve.x * this->y);
	return vecres;
}

float vector::producto_escalar(vector ve)
{

}