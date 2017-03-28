#ifndef TRIANGULO_H
#define TRIANGULO_H

#include "vector.h"
#include "rgb.h"
#include "rayo.h"

class triangulo
{
private:
	vector a;
	vector b;
	vector c;
	rgb color;
public:
	triangulo();
	triangulo(vector a, vector b, vector c, rgb color);
	~triangulo();
	vector geta();
	vector getb();
	vector getc();
	void seta(vector a);
	void setb(vector b);
	void setc(vector c);
	bool interseccion(rayo ray);
};

#endif