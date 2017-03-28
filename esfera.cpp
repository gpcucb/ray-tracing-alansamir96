#include "esfera.h"


esfera::esfera()
{
}

esfera::esfera(vector posicion, float radio /* , rgb color  */ )
{
	this->posicion = posicion;
	this->radio = radio;
	//this->color = color;
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
//	float A, B, C, t;
	//t = calculaT();
	//A = (d.producto_escalar(d)) * (t*t);
	//B = (d.producto_escalar_porvector(2)).producto_escalar((camara.geteje()).resta(posicion));
//	C = 3;
	return 111111;
}

float esfera::calculaDiscriminante(float a, float b, float c)
{
	float res;
	res = pow(b, 2) - (4 * a*c);
	return res;
}

bool esfera::interseccion(rayo ray, float t)
{
	float a, b, c, discr, t0, t1;
	bool intersec;
	vector e = ray.getpos();
	vector d = ray.getdir();
	vector e_c;
	a = d.producto_escalar(d);
	e_c = e.resta(this->posicion);
	b = d.producto_escalar_porvector(2).producto_escalar(e_c);
	c = e_c.producto_escalar(e_c) - pow(radio, 2);

	cout << "a: " << a << " , b: " << b << " , c: " << c << endl;

	discr = calculaDiscriminante(a, b, c);
	
	if (discr < 0.0)
	{
		return false;
	}
	t0 = ((b * -1) - sqrt(discr)) / (2 * a);
	t1 = ((b * -1) + sqrt(discr)) / (2 * a);

	intersec = false;

	if ((t0>0.0) && (t0 < t))
	{
		intersec = true;
		t = t0;
	}
	if ((t1>0.0) && (t1 < t))
	{
		intersec = true;
		t = t1;
	}

	return intersec;
}

