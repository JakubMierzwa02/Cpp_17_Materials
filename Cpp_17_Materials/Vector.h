#pragma once

#include <iostream>
#include <stdexcept>
#include <numeric>
#include <algorithm>
#include <thread>

enum class Color { red, blue, green };
enum class Traffic_light { green, yellow, red };

template<typename T>
class Vector
{
private:
	T* elem;
	int sz;

public:
	explicit Vector(int s);

	Vector(int s) : elem{ new double[s] }, sz{ s }
	{
		for (int i = 0; i != s; i++)
		{
			elem[i] = 0;
		}
	}

	Vector(std::initializer_list<T> lst) : elem{new T[lst.size()]}, sz{static_cast<int>(lst.size())}
	{
		std::copy(lst.begin(), lst.end(), elem);
	}

	~Vector() { delete[] elem; }

	Vector(const Vector& a) : elem{ new double[a.sz] }, sz{ a.sz }
	{
		for (int i = 0; i != sz; i++)
			elem[i] = a.elem[i];
	}

	Vector& operator=(const Vector& a)
	{
		double* p = new double[a.sz];
		for (int i = 0; i != a.sz; ++i)
			p[i] = a.elem[i];
		delete[] elem;
		elem = p;
		sz = a.sz;
		return *this;
	}

	Vector(Vector&& a) : elem{ a.elem }, sz{ a.sz }
	{
		a.elem = nullptr;
		a.sz = 0;
	}

	Vector& operator=(Vector&& a);

	/*Vector operator+(const Vector& a, const Vector& b)
	{
		if (a.size() != b.size())
			throw "Error!";
	}*/

	T& operator[](int);
	const T& operator[](int) const;

	int size();

	void write(const Vector<std::string>& ws)
	{
		for (int i = 0; i != vs.size(); ++i)
			std::cout << vs[i] << '\n';
	}

	template<typename T>
	T* begin(Vector<T>& x)
	{
		return x.size() ? &x[0] : nullptr;
	}

	template<typename T>
	T* end(Vector<T>& x)
	{
		return x.size() ? &x[0] + x.size() : nullptr;
	}
};

double read_and_sum(int);

Traffic_light& operator++(Traffic_light&);

template<typename T>
void f(Vector<T>& v);

template<typename T>
void user(int sz) noexcept
{
	Vector<int> v(sz);
	std::iota(&v[0], &v[sz], 1);
	// ...
}