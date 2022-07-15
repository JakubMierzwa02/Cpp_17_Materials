#pragma once

#include <iostream>
#include <stdexcept>
#include <numeric>
#include <algorithm>

enum class Color { red, blue, green };
enum class Traffic_light { green, yellow, red };

class Vector
{
private:
	double* elem;
	int sz;
public:
	Vector(int s) : elem{ new double[s] }, sz{ s }
	{
		for (int i = 0; i != s; i++)
		{
			elem[i] = 0;
		}
	}

	Vector(std::initializer_list<double> lst) : elem{new double[lst.size()]}, sz{static_cast<int>(lst.size())}
	{
		std::copy(lst.begin(), lst.end(), elem);
	}

	~Vector() { delete[] elem; }
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