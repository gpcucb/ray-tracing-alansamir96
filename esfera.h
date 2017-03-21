#ifndef ESFERA_H
#define ESFERA_H
#include "vector.h"
#include "rayo.h"


class esfera
{
private:
	vector posicion;
	float radio;
	
public:
	esfera();
	esfera(vector posicion, float radio);
	~esfera();
	vector getposicion();
	float getradio();
	void setposicion(vector pos);
	void setradio(float rad);
	float interseccion11(vector d);
	void interseccion(rayo ray);
	float calculaT();
};

#endif