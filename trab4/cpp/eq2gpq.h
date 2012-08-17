#ifndef EQ2GPQ_H
#define EQ2GPQ_H

#include <complex>
#include <cmath>
#include <vector>

using std::sqrt;
using std::complex;
using std::vector;

// Algoritmo EQ2GPQ
//void eq2gpq(double p, double q, complex<double> *raizes, int &j) {
void eq2gpq(double p, double q, complex<double> raizes[], int &pos) {
  complex<double> delta = p*p - 4*q;
  raizes[pos++] = (-p - sqrt(delta)) / 2.;
  raizes[pos++] = (-p + sqrt(delta)) / 2.;
}

#endif

