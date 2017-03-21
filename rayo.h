#ifndef RAYO_H
#define RAYO_H
#include "vector.h"

class rayo
{
private:
	vector posicion;
	vector direccion;
public:
	rayo();
	rayo(vector posicion, vector direccion);
	~rayo();
	vector getpos();
	vector getdir();
	void setpos(vector pos);
	void setdir(vector dir);
	void show();
};

#endif