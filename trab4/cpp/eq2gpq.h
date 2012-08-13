#ifndef EQ2GPQ_H
#define EQ2GPQ_H

#include <complex>
#include <cmath>

using std::sqrt;
using std::complex;

// Algoritmo EQ2GPQ
void eq2gpq(double p, double q, complex<double> *raizes, int &j) {
  complex<double> delta = p*p - 4*q;
  raizes[j++] = (-p - sqrt(delta)) / 2.;
  raizes[j++] = (-p + sqrt(delta)) / 2.;
}

#endif

