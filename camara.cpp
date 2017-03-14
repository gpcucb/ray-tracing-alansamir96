#include "camara.h"


camara::camara()
{

}

camara::camara(vector eje, vector center, vector up, float fov, float df)
{
	this->eje = eje;
	this->center = center;
	this->up = up;
	this->fov = fov;
	this->df = df;
}


camara::~camara()
{
}

vector camara::vectorW()
{
	vector vecres,d;
	float m;
	d = eje.resta(up);
	m = d.modulo();
	vecres.setX(d.getX() / m);
	vecres.setY(d.getY() / m);
	vecres.setZ(d.getZ() / m);
	return vecres;
}

vector camara::vectorU()
{
	vector vecres,vecaux;
	float m;
	vecaux = up.producto_vectorial(vectorW());
	m = vecaux.modulo();
	vecres.setX(vecaux.getX() / m);
	vecres.setY(vecaux.getY() / m);
	vecres.setZ(vecaux.getZ() / m);
	return vecres;
}

vector camara::vectorV()
{
	vector vecres;
	vecres = vectorW().producto_vectorial(vectorU());
	return vecres;
}

vector camara::DireccionRayo(float i, float j, float nx, float ny)
{
	vector dw, uu, vv, vecres;
	float t, r, l, b, u, v;

	t = calcularT();
	r = calcularR(nx,ny);
	b = -t;
	l = -r;

	u = l + ((r - l)*(i + 0.5)) / nx;
	v = b + ((t - b)*(j + 0.5)) / ny;

	dw = vectorW().producto_escalar_porvector(-df);
	uu = vectorU().producto_escalar_porvector(u);
	vv = vectorV().producto_escalar_porvector(v);

	vecres = (dw.suma(uu)).suma(vv);

	return vecres;
}

float camara::calcularT()
{
	float res;
	res = this->df * tan(this->fov / 2);
	return res;
}

float camara::calcularR(float nx, float ny)
{
	float res;
	res = (calcularT() - nx) / ny;
	return res;
}