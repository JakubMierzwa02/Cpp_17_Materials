#pragma once

#include <list>
#include "Vector.h"

template<typename T>
class Less_than
{
	const T val;

public:
	Less_than(const T& v) : val{ v } { }
	bool operator()(const T& x) const { return x < val; }

	template<typename C, typename P>
	int count(const C& c, P pred)
	{
		int cnt = 0;
		for (const auto& x : c)
			if (pred(x))
				++cnt;
		return cnt;
	}

	void f(const Vector<int>& vec, const std::list<std::string>& lst, int x, const std::string& s)
	{
		std::cout << "Liczba wartosci mniejszych niz " << x << ": " << count(vec, Less_than{ x }) << '\n';
		std::cout << "Liczba wartosci mniejszych niz " << s << ": " << count(lst, Less_than{ s }) << '\n';
	}
};