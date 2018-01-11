#ifndef Complex_CPP
#define Complex_CPP

#include "Complex.hpp"
#include <math.h>

Complex mpi(const Complex& z) {
  return Complex(-z.y, z.x);
}

Complex::Complex() {
  x = 1.0;
  y = 0.0;
}

Complex::Complex(const Complex &p) {
  x = p.x;
  y = p.y;
}

Complex::Complex(double real) {
  x = real;
  y = 0.0;
}

Complex::Complex(double dx, double dy) {
  x = dx;
  y = dy;
}

Complex::~Complex() {
}

Complex& Complex::operator=(const Complex& c) {
  // Avoid doing assign to myself
  if (this == &c) {
    return *this;
  }
  x = c.x;
  y = c.y;
  return *this;
}

Complex& Complex::operator += (const Complex& c) {
  x += c.x;
  y += c.y;
  return *this;
}

Complex& Complex::operator-=(const Complex& c) {
  x -= c.x;
  y -= c.y;
  return *this;
}

Complex& Complex::operator/=(const Complex& c) {
  Complex tmp = (*this) / c;
  *this = tmp;
  return *this;
}

Complex& Complex::operator *= (const Complex& c) {
  Complex tmp = (*this) * c;
  *this = tmp;

  return *this;
}


double Complex::xVal() const {
  return x;
}

double Complex::yVal() const {
  return y;
}

double real(const Complex& c) {
  return c.x;
}

double imag(const Complex& c) {
  return c.y;
}

double rad(const Complex& c) {
  double res = ::sqrt((c.x*c.x) + (c.y*c.y));
  return res;
}

double modulus(const Complex& c) {
  return rad(c);
}

double abs(const Complex& c) {
  return rad(c);
}

// Functionality
double Complex::distance(const Complex& c2) {
  return sqrt((x-c2.x)*(x-c2.x) + (y-c2.y)*(y-c2.y));
}


Complex Complex::operator-() const {
  return Complex(-x, -y);
}

Complex Complex::add(const Complex& c2) const {
  Complex result;
  result.x = x + c2.x;
  result.y = y + c2.y;
  return result;
}

Complex Complex::operator+(const Complex& c2) const {
  return Complex(x + c2.x, y + c2.y);
}

Complex Complex::operator-(const Complex& c2) const {
  return Complex(x - c2.x, y - c2.y);
}

Complex Complex::operator*(const Complex& c2) const {
  return Complex((x * c2.x) - (y * c2.y), (x * c2.y) + (y * c2.x));
}

Complex Complex::operator/(const Complex& c2) const {
  Complex res;
  double r = ::modulus(c2);
  double d = r * r;
  Complex tmp1 = conjugate(c2);
  Complex tmp2 = tmp1 * (*this);
  res =tmp2/d;
  return res;
}

Complex Complex::operator/(double d) const {

  return Complex(x / d, y / d);
}

// Global operator overloading
Complex operator*(const Complex& c, double d) {
  return Complex(c.x * d, c.y * d);
}

Complex operator*(double d, const Complex& c) {
  return c * d;
}

Complex operator+(const Complex& c, double d) {
  return Complex(c.x + d, c.y);
}

Complex operator+(double d, const Complex& c) {
  return c + d;
}
Complex operator-(const Complex& c, double d) {
  return Complex(c.x - d, c.y);
}

Complex operator - (double d, const Complex& c) {
  return Complex(d - c.x, -c.y);
}


// Other functions
Complex conjugate(const Complex& z) {
  return Complex(z.x, -z.y);
}

Complex inverse(const Complex& z) {
  return Complex(1.0,0.0) / z;
}


Complex exp(const Complex& c) {
  double ex = exp(c.x);
  return Complex(ex * cos(c.y), ex * sin(c.y));
}


Complex cos(const Complex& z) {
  Complex term1 = exp(mpi(z));
  Complex term2 = exp(- mpi(z));

  Complex result = 0.5 * (term1 + term2);

  return result;
}

Complex sin(const Complex& z) {
  Complex term1 = exp(mpi(z));
  Complex term2 = exp(-mpi(z));
  Complex result = -0.5 * mpi(term1 - term2);
  return result;
}

Complex cosh(const Complex& z) {
  return (exp(z)  + exp(- (z))) * 0.5;
}

Complex sinh(const Complex& z) {
  return (exp(z) - exp(- (z))) * 0.5;
}

Complex tanh(const Complex& z) {
  return sinh(z) / cosh(z);
}

Complex sech(const Complex& z) {
  return Complex (2.0, 0.0)/(exp(z) + exp(-z));
}

Complex csch(const Complex& z) {
  return Complex (2.0, 0.0)/(exp(z) - exp(-z));
}

Complex coth(const Complex& z) {
  return cosh(z) / sinh(z);
}

Complex tan(const Complex& c) {
  return sin(c) / cos(c);
}

Complex cgt(const Complex& c) {
  return cos(c) / sin(c);
}

ostream& operator << (ostream& os, const Complex& cmp) {
  os << "Complex { " << cmp.x <<  " + " << cmp.y << "i }";
  return os;
}

#endif
