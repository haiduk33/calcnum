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
  double im = sqrt(delta) / 2;
  if (delta >= 0) {
    raizes[j] = complex<double>(r + im, 0);
    raizes[j] = complex<double>(r - im, 0);
  } else {
    raizes[j] = complex<double>(r, im);
    raizes[j] = complex<double>(r, -im);
  }
  ++j;
  ++j;
}

#endif

