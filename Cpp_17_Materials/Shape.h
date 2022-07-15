#pragma once

#include <vector>

struct Point
{
	float x;
	float y;
};

class Shape
{
public:
	virtual Point center() const = 0;
	virtual void move(Point to) = 0;
	virtual void draw() const = 0;
	virtual void rotate(int angle) = 0;

	virtual ~Shape() {}
};

class Circle : public Shape
{
	Point x;
	int r;

public:
	Circle(Point p, int rad);

	Point center() const override
	{
		return x;
	}

	void move(Point to) override {}
};

class Smiley : public Circle
{
	std::vector<Shape*> eyes;
	Shape* mouth;

public:
	Smiley(Point p, int rad) : Circle{ p,r }, mouth{ nullptr } { }

	~Smiley()
	{
		delete mouth;
		for (auto p : eyes)
			delete p;
	}

	void move(Point to) override;
	void draw() const override;
	void rotate(int) override;

	void add_eye(Shape* s)
	{
		eyes.push_back(s);
	}
	void set_mouth(Shape* s);
	virtual void wink(int i);
};