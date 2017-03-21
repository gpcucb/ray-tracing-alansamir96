#ifndef CAMARA_H
#define CAMARA_H
#include "vector.h"


class camara
{
private:
	vector eje;
	vector center;
	vector up;
	float fov;
	float df;
public:
	camara();
	camara(vector eje, vector center, vector up, float fov, float df);
	~camara();
	vector geteje();
	vector getcenter();
	vector getup();
	float getfov();
	float getdf();
	void seteje(vector eje1);
	void setcenter(vector center1);
	void setup(vector up1);
	void setfov(float fov1);
	void setdf(float df1);
	vector vectorW();
	vector vectorU();
	vector vectorV();
	vector DireccionRayo(float i, float j, float nx, float ny);
	float calcularT();
	float calcularR(float nx, float ny);
};

#endif