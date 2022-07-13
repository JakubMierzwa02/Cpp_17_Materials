#pragma once

#include "Vector.h"
#include <list>

class Container
{
public:
	virtual double& operator[](int) = 0;
	virtual int size() const = 0;
	virtual ~Container() {}
};

class Vector_container : public Container
{
	Vector v;

public:
	Vector_container(int s) : v(s) {}
	~Vector_container() {}

	double& operator[](int i) override { return v[i]; }
	int size() const override { return v.size(); }
};

class List_container : public Container
{
	std::list<double> ld;

public:
	List_container() {}
	List_container(std::initializer_list<double> il) : ld{ il } {}
	~List_container() {}
	double& operator[](int i) override;
	int size() const override { return ld.size(); }
};