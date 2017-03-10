#include "vector.h"


class camara
{
private:
	vector e;
	vector center;
	vector up;
public:
	camara();
	~camara();
	vector vectorW();
	vector vectorU();
	vector vectorV();
};

