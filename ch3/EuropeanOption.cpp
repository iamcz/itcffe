#ifndef EuropeanOption_cpp
#define EuropeanOption_cpp
#include "EuropeanOption.hpp"
#include <math.h>

// Normal Distribution
double EuropeanOption::n(double x) const {
  double A = 1.0 / sqrt(2.0 * 3.1415);
  return A * exp(-x * x * 0.5);
}

// Cumulative Normal Distribution (approximation)
double EuropeanOption::N(double x) const {
  if (x >= 0) {
    double a1 = 0.4361836;
    double a2 = -0.1201676;
    double a3 = 0.9372980;

    double k = 1.0 / (1.0 + (0.33267 * x));

    return 1.0 - n(x) * (a1 * k + a2 * k * k + a3 * k * k * k);
  } else {
    return 1.0 - N(-x);
  }
}

double EuropeanOption::CallPrice() const {
  double tmp = sig * sqrt(T);
  double d1 = (log(U / K) + (b + sig * sig * 0.5) * T) / tmp;
  double d2 = d1 - tmp;
  return (U * exp((b - r) * T) * N(d1)) - (K * exp(-r * T) * N(d2));
}

double EuropeanOption::PutPrice() const {
  double tmp = sig * sqrt(T);
  double d1 = (log(U / K) + (b + sig * sig * 0.5) * T) / tmp;
  double d2 = d1 - tmp;
  return K * exp(-r * T) * N(-d2) - U * exp((b - r) * T) * N(-d1);
}

double EuropeanOption::CallDelta() const {
  double tmp = sig * sqrt(T);
  double d1 = (log(U / K) + (b + sig * sig * 0.5) * T) / tmp;
  return exp((b - r) * T) * N(d1);
}

double EuropeanOption::PutDelta() const {
  double tmp = sig * sqrt(T);
  double d1 = (log(U / K) + (b + sig * sig * 0.5) * T) / tmp;
  return exp((b - r) * T) * (N(d1) - 1.0);
}

void EuropeanOption::init() {
  r = 0.08;
  sig = 0.30;
  K = 65.0;
  T = 0.25;
  U = 60.0;
  b = r;
  optType = "C";
}

void EuropeanOption::copy(const EuropeanOption& o2) {
  r = o2.r;
  sig = o2.sig;
  K = o2.K;
  T = o2.T;
  U = o2.U;
  b = o2.b;
  optType = o2.optType;
}

EuropeanOption::EuropeanOption() {
  init();
}

EuropeanOption::EuropeanOption(const EuropeanOption& o2) {
  copy(o2);
}

EuropeanOption::EuropeanOption(const string& optionType) {
  init();
  optType = optionType;
}

EuropeanOption::~EuropeanOption() {
}

EuropeanOption& EuropeanOption::operator=(const EuropeanOption& o2) {
  if (this != &o2) {
    copy(o2);
  }
  return *this;
}

double EuropeanOption::Price() const {
  if (optType == "C") {
    return CallPrice();
  } else {
    return PutPrice();
  }
}

double EuropeanOption::Delta() const {
  if (optType == "C") {
    return CallDelta();
  } else {
    return PutDelta();
  }
}

void EuropeanOption::toggle() {
  if (optType == "C") {
    optType = "P";
  } else {
    optType = "C";
  }
}

#endif
