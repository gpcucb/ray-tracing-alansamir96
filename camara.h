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
	vector vectorW();
	vector vectorU();
	vector vectorV();
	vector DireccionRayo(float i, float j, float nx, float ny);
	float calcularT();
	float calcularR(float nx, float ny);
};

