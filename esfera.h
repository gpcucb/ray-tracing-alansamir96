#ifndef ESFERA_H
#define ESFERA_H

#include "vector.h"
#include "rayo.h"
#include "rgb.h"


class esfera
{
private:
	vector posicion;
	float radio;
	//rgb color;
public:
	esfera();
	esfera(vector posicion, float radio /*, rgb color*/ );
	~esfera();
	vector getposicion();
	float getradio();
	void setposicion(vector pos);
	void setradio(float rad);
	float interseccion11(vector d);
	float calculaDiscriminante(float a, float b, float c);
	bool interseccion(rayo ray, float t);
};

#endif