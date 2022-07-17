#include "Vector.h"

template<typename T>
T& Vector<T>::operator[](int i)
{
	if (i < 0 || size() <= i)
		throw std::out_of_range{ "Vector::operator[]" };
	return elem[i];
}

int Vector<int>::size()
{
	return sz;
}

double read_and_sum(int s)
{
	Vector<int> v(s);
	for (int i = 0; i != v.size(); i++)
		std::cin >> v[i];

	double sum = 0;
	for (int i = 0; i != v.size(); i++)
		sum += v[i];

	return sum;
}

Traffic_light& operator++(Traffic_light& t)
{
	switch (t)
	{
	case Traffic_light::green: return t = Traffic_light::yellow;
	case Traffic_light::yellow: return t = Traffic_light::red;
	case Traffic_light::red: return t = Traffic_light::green;
	}
}

template<typename T>
void f(Vector<T>& v)
{
	// ...
	try
	{
		v[v.size()] = 7;
	}
	catch (std::out_of_range& err)
	{
		std::cerr << err.what() << '\n';
	}
	// ...
}
