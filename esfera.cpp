#include "esfera.h"


esfera::esfera()
{
}

esfera::esfera(vector posicion, float radio)
{
	this->posicion = posicion;
	this->radio = radio;
}

esfera::~esfera()
{
}

vector esfera::getposicion()
{
	return posicion;
}

float esfera::getradio()
{
	return radio;
}

void esfera::setposicion(vector pos)
{
	this->posicion = pos;
}

void esfera::setradio(float rad)
{
	this->radio = rad;
}

float esfera::interseccion11(vector d)
{
	float A, B, C, t;
	t = calculaT();
	A = (d.producto_escalar(d)) * (t*t);
	//B = (d.producto_escalar_porvector(2)).producto_escalar((camara.geteje()).resta(posicion));
	C = 3;
	return C;
}

void esfera::interseccion(rayo ray)
{
	float a, b, c;
	vector e = ray.getpos();
	vector d = ray.getdir();
	vector e_c;
	a = d.producto_escalar(d);
	e_c = e.resta(this->posicion);
	b = d.producto_escalar_porvector(2).producto_escalar(e_c);
	c = e_c.producto_escalar(e_c) - pow(radio, 2);
	cout << "a: " << a << " , b: " << b << " , c: " << c << endl;
}

float esfera::calculaT()
{
	return 3;
}