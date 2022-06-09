#pragma once

#include <iostream>

class Vector
{
private:
	double* elem;
	int sz;
public:
	Vector(int);
	double& operator[](int);
	int size();
};