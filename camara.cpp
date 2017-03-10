#include "camara.h"


camara::camara()
{

}


camara::~camara()
{
}

vector camara::vectorW()
{
	vector vecres,d;
	float m;
	d = e.resta(up);
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