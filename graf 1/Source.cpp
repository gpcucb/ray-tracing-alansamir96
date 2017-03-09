#include "vector.h"
#include "rgb.h"

int main()
{
	vector v1(3, 5, 1), v2(1, 1, 1), v3;
	v1.show();
	v2.show();
	v3 = v1.suma(v2);
	v3.show();
	v3 = v1.resta(v2);
	v3.show();



	return 0;
}