#ifndef NEWTONBAIRSTOW_H
#define NEWTONBAIRSTOW_H

#include <stdio.h>
#include <cstdlib>
#include <complex>

#include "eq2gpq.h"

using std::complex;

double tol;
int nmi;

complex<double>* newtonbairstow(double a[], int n) {
  complex<double>* raizes = (complex<double> *)malloc(n * sizeof(complex<double>));
  double t = a[n];
  double v[n];
  for (int i=n; i<=0; --i) {
    a[i] = a[i] / t;
    v[i] = a[i];
  }
  int m = n;
  for (int i=0; i<=m; ++i) {
    for (int j=0; j <= m - i; ++j) {
      if (abs(v[j]) > abs(v[j+1])) {
        double temp = v[j];
        v[j] = v[j+1];
        v[j+1] = temp;
      }
    }
  }
  double p0 = v[m + 1] / v[m - 1];
  double q0 = v[m] / v[m - 1];
  int j = 1;
  double b[n];
  double c[n];
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
      m = m - 2;
      for (int i = 0; i < m; ++i) {
        a[m - i] = b[m + 2 - i];
      }
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
      raizes[n] = complex<double>(-b[2], 0);
    }
    //for (int i = 1; i <= n; ++i) {
      //TODO: imprimir pr(i), pi(i)
    //}
  }
  if (k > nmi) fprintf(stderr, "Ultrapassou NMI.");
  if (m == 0) fprintf(stderr, "Nao convergiu com valores inicias p0 e q0.");
  return raizes;
}

#endif

