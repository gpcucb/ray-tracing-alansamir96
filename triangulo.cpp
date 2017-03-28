#include "triangulo.h"


triangulo::triangulo()
{
}

triangulo::triangulo(vector a, vector b, vector c, rgb color)
{
	this->a = a;
	this->b = b;
	this->c = c;
	this->color = color;
}

triangulo::~triangulo()
{
}

vector triangulo::geta()
{
	return a;
}

vector triangulo::getb()
{
	return b;
}

vector triangulo::getc()
{
	return c;
}

void triangulo::seta(vector a)
{
	this->a = a;
}

void triangulo::setb(vector b)
{
	this->b = b;
}

void triangulo::setc(vector c)
{
	this->c = c;
}

bool triangulo::interseccion(rayo ray)
{
	float t, gama, beta;
	float a, b, c, d, e, f, g, h, i, j, k, l;
	a = this->a.getX() - this->b.getX();
	b = this->a.getY() - this->b.getY();
	c = this->a.getZ() - this->b.getZ();
	d = this->a.getX() - this->c.getX();
	e = this->a.getY() - this->c.getY();
	f = this->a.getZ() - this->c.getZ();

	vector dir_rayo = ray.getdir();
	vector pos_rayo = ray.getpos();

	g = dir_rayo.getX();
	h = dir_rayo.getY();
	i = dir_rayo.getZ();

	j = this->a.getX() - pos_rayo.getX();
	k = this->a.getY() - pos_rayo.getY();
	l = this->a.getZ() - pos_rayo.getZ();

	float m;

	m = a*(e*i - h*f) + b*(g*f - d*i) + c*(d*h - e*g);

	t = -1 * ((f*(a*k - j*b) + e*(j*c - a*l) + d*(b*l - k*c)) / m);
	//if ((t<t0) || (t>t1))
	//	return false;
	gama = (i*(a*k - j*b) + h*(j*c - a*l) + g*(b*l - k*c)) / m;
	if ((gama < 0) || (gama > 1))
		return false;
	beta = (j*(e*i - h*f) + k*(g*f - d*i) + l*(d*h - e*g)) / m;
	if ((beta < 0) || (beta > 1 - gama))
		return false;

	cout << "beta: " << beta << ", gama: " << gama << " ,t: " << t << endl;

	return true;
}