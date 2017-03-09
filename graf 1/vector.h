#include<stdio.h>
#include<iostream>
#include<math.h>
using namespace std;
class vector
{
private:
	float x;
	float y;
	float z;
public:
	vector();
	vector(float x1, float y1, float z1);
	~vector();
	void show();
	vector suma(vector ve);
	vector resta(vector ve);
	float modulo();
	vector producto_vectorial(vector ve);
	float producto_escalar(vector ve);
};

