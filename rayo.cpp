#include "rayo.h"


rayo::rayo()
{
}

rayo::rayo(vector posicion, vector direccion)
{
	this->posicion = posicion;
	this->direccion = direccion;
}


rayo::~rayo()
{
}


vector rayo::getpos()
{
	return posicion;
}

vector rayo::getdir()
{
	return direccion;
}

void rayo::setpos(vector pos)
{
	this->posicion = pos;
}

void rayo::setdir(vector dir)
{
	this->direccion = dir;
}

void rayo::show()
{
	cout << "Posicion: ";
	this->posicion.show();
	cout << "Direccion: ";
	this->direccion.show();
}