#pragma once

#include <iostream>
#include <stdexcept>
#include <numeric>

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

double read_and_sum(int);

Traffic_light& operator++(Traffic_light&);

void f(Vector& v);

void user(int sz) noexcept
{
	Vector v(sz);
	std::iota(&v[0], &v[sz], 1);
	// ...
}