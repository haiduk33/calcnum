#ifndef NEWTONBAIRSTOW_H
#define NEWTONBAIRSTOW_H

#include <stdio.h>
#include <complex>

#include "eq2gpq.h"

using std::complex;
using std::abs;

double tol;
int nmi;

// Algoritmo NEWTON-BAIRSTOW(N,A)
complex<double>* newtonbairstow(int n, double a[n]) {
  complex<double>* raizes = new complex<double>[n];
  double t = a[n];
  double *v = new double[n + 1];

  for (int i = n; i >= 0; --i) {
    a[i] = a[i] / t;
    v[i] = a[i];
  }
  int m = n;

  // Não é nescessário ordenar os coeficientes do livro como
  // é feito no algoritmo original, apenas queremos os
  // tres maiores em módulo, então basta buscá-los
  double p0=0, q0=0, norm=0;
  for (int i = 0; i <= m; ++i) {
    if (abs(v[i]) > abs(norm)) {
      if (abs(v[i]) > abs(q0)) {
        norm = q0;
        if (abs(v[i]) > abs(p0)) {
          q0 = p0;
          p0 = v[i];
        } else {
          q0 = v[i];
        }
      } else {
        norm = v[i];
      }
    }
  }
  q0 = abs(q0 / norm);
  p0 = abs(p0 / norm);

  int j = 1;
  double *b = new double[n + 1];
  double *c = new double[n + 1];
  int k = 0;
  while (m > 2) {
    b[m + 1] = 0;
    b[m + 2] = 0;
    c[m + 1] = 0;
    c[m + 2] = 0;
    double p = p0;
    double q = q0;
    double dp = 1;
    double dq = 1;
    while (abs(dp) + abs(dq) > tol && k <= nmi) {
      for (int i = m; i > 0; --i) {
        b[i] = a[i] - p * b[i + 1] - q * b[i + 2];
        c[i] = b[i] - p * c[i + 1] - q * c[i + 2];
      }
      b[0] = a[0] - p * b[1] - q * b[2];
      double c1 = c[1] - b[1];
      double d = c[2] * c[2] - c1 * c[3];
      if (abs(d) > 0) {
        dp = (b[1] * c[2] - b[0] * c[3]) / d;
        dq = (b[0] * c[2] - b[1] * c1) / d;
        p = p + dp;
        q = q + dq;
      } else {
        m = 0;
      }
      ++k;
    }
    if (m != 0) {
      eq2gpq(p, q, raizes, j);
      --m;
      --m;
      for (int i = 0; i < m; ++i)
        a[m - i] = b[m + 2 - i];
      p0 = v[m + 1] / v[m + 2];
      q0 = v[m] / v[m - 1];
    }
  }
  if (m != 0 && k <= nmi) {
    if (m == 2) {
      double p = b[3];
      double q = b[2];
      eq2gpq(p, q, raizes, j);
    } else {
      raizes[n] = -b[2];
    }
  }
  if (k > nmi) fprintf(stderr, "Ultrapassou NMI.\n");
  if (m == 0) fprintf(stderr, "Nao convergiu com valores inicias p0 e q0.\n");
  return raizes;
}

#endif

