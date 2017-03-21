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

void vector::setX(float v)
{
	this->x = v;
}

float vector::getX()
{
	return this->x;
}

void vector::setY(float v)
{
	this->y = v;
}

float vector::getY()
{
	return this->y;
}

void vector::setZ(float v)
{
	this->z = v;
}

float vector::getZ()
{
	return this->z;
}

void vector::show()
{
	cout << "(" << x << "," << y << "," << z << ")" << " ";
}



vector vector::suma(vector vec)
{
	vector vecres;
	vecres.x = this->x + vec.x;
	vecres.y = this->y + vec.y;
	vecres.z = this->z + vec.z;
	return vecres;
}

vector vector::resta(vector vec)
{
	vector vecres;
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
	vector vecres;
	vecres.x = (this->y * ve.z) - (ve.y * this->z);
	vecres.y = (this->x * ve.z) - (ve.x * this->z);
	vecres.z = (this->x * ve.y) - (ve.x * this->y);
	return vecres;
}


float vector::producto_escalar(vector ve)
{
	float res;
	res = (this->x * ve.x) + (this->y * ve.y) + (this->z * z);
	return res;
}


vector vector::producto_escalar_porvector(float v)
{
	vector vecres;
	vecres.x = this->x * v;
	vecres.y = this->y * v;
	vecres.z = this->z * v;
	return vecres;
}