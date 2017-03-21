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

vector camara::geteje()
{
	return this->eje;
}

vector camara::getcenter()
{
	return this->center;
}

vector camara::getup()
{
	return this->up;
}

float camara::getfov()
{
	return this->fov;
}

float camara::getdf()
{
	return this->df;
}

void camara::seteje(vector eje1)
{
	this->eje.setX(eje1.getX());
	this->eje.setY(eje1.getY());
	this->eje.setZ(eje1.getZ());
}

void camara::setcenter(vector center1)
{
	this->center.setX(center1.getX());
	this->center.setY(center1.getY());
	this->center.setZ(center1.getZ());
}

void camara::setup(vector up1)
{
	this->up.setX(up1.getX());
	this->up.setY(up1.getY());
	this->up.setZ(up1.getZ());
}

void camara::setfov(float fov1)
{
	this->fov = fov1;
}

void camara::setdf(float df1)
{
	this->df = df1;
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