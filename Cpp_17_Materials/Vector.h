#pragma once

#include <iostream>

enum class Color { red, blue, green };
enum class Traffic_light { green, yellow, red };

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