#include "complex.hpp"

struct Complex {
	long double r, i;

	Complex(long double nr, long double ni) {
		r = nr;
		i = ni;
	}

	Complex() {}
};

Complex operator + (Complex a, Complex b) {
	Complex c;
	c.r = a.r + b.r;
	c.i = a.i + b.i;
	return c;
}

Complex operator * (Complex a, Complex b) {
	Complex c;
	c.r = a.r * a.r - a.i * b.i;
	c.i = a.i * b.r + b.i * a.r;
    return c;
}
Complex operator * (long double a, Complex b) {
	Complex c;
	c.r = a * b.r;
	c.i = a * b.i;
	return c;
}

long double abs(Complex a) {
	return sqrt(a.i * a.i + a.r * a.r);
}
