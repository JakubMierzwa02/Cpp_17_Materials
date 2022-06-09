#include "Vector.h"

double read_and_sum(int s)
{
	Vector v(s);
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