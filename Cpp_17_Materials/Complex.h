#pragma once

#include <complex>

class Complex
{
	double re = 0;
	double im = 0;

public:
	Complex(double r, double i) : re{ r }, im{ i } {}
	Complex(double r) : re{ r } {}
	Complex() {}

	double real() const { return re; }
	void real(double d) { re = d; }
	double imag() const { return im; }
	void imag(double d) { im = d; }

	Complex& operator+=(Complex x)
	{
		re += z.re;
		im += z.im;
		return *this;
	}

	Complex& operator-=(Complex z)
	{
		re -= z.re;
		im -= z.im;
		return *this;
	}

	Complex& operator*=(Complex z);
	Complex& operator/=(Complex z);

	Complex operator+(Complex a, Complex b) { return a += b; }
	Complex operator-(Complex a, Complex b) { return a -= b; }
	Complex operator-(Complex a) { return { -a.real(), -a.imag()}; }
	Complex operator*(Complex a, Complex b) { return a *= b; }
	Complex operator/(Complex a, Complex b) { return a /= b; }

	bool operator==(Complex a, Complex b)
	{
		return a.real() == b.real() && a.imag() == b.imag();
	}

	bool operator!=(Complex a, Complex b)
	{
		return !(a == b);
	}

	constexpr std::complex<double> operator""i(long double arg)
	{
		return { 0, arg };
	}
};