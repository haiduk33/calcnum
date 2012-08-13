#ifndef EQ2GPQ_H
#define EQ2GPQ_H

#include <complex>
#include <cmath>

using std::sqrt;
using std::complex;

// Algoritmo EQ2GPQ
void eq2gpq(double p, double q, complex<double> *raizes, int &j) {
  double delta = p*p - 4*q;
  double r = -p / 2;
  double im = sqrt(abs(delta)) / 2;
  if (delta >= 0) {
    raizes[j++] = r + im;
    raizes[j++] = r - im;
  } else {
    raizes[j++] = r + 1i*im;
    raizes[j++] = r - 1i*im;
  }
}

#endif

