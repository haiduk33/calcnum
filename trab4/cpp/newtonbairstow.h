#ifndef NEWTONBAIRSTOW_H
#define NEWTONBAIRSTOW_H

#include <stdio.h>
#include <complex>
#include <algorithm>
#include <iomanip>
#include <vector>

#include "eq2gpq.h"

#define MAXN 20
//#define LAMEAPROX

using std::complex;
using std::abs;
using std::sort;

double tol;
int nmi;

namespace {
bool abscmp(const double &a, const double &b) {
  return abs(a) < abs(b);
}
}

// Algoritmo NEWTON-BAIRSTOW(N,A)
complex<double> *newtonbairstow(int n, double a[n]) {
  static complex<double> raizes[MAXN];
  double v[MAXN + 1], b[MAXN + 3], c[MAXN + 2];
  double p, q, dp, dq;
  int m, k;

  // Normalizar coeficientes e aproveitar para copiar a para v
  for (int i = n; i >= 0; --i) {
    a[i] = a[i] / a[n];
    v[i] = a[i];
  }
  m = n;

  // O vetor v é uma cópia de a, vamos ordenar-lo pelos valores
  // absolutos dos coeficientes para esolher p e q iniciais
  sort(v, v + n + 1, abscmp);
  p = v[m] / v[m - 2];
  q = v[m - 1] / v[m - 2];

  int raiz_atual = 0;
  while (m > 2) {
    b[m + 2] = 0;
    b[m + 1] = 0;
    c[m + 1] = 0;
    c[m + 0] = 0;
    dp = 1;
    dq = 1;
    k = 0;
    while (abs(dp) + abs(dq) > tol && k <= nmi) {
      for (int i = m; i >= 0; --i) {
        b[i] = a[i] - p * b[i + 1] - q * b[i + 2];
        c[i] = b[i + 1] - p * c[i + 1] - q * c[i + 2];
      }
      double d = c[1] * c[1] - (c[0] - b[1]) * c[2];
      if (abs(d) > 0) {
        dp = (b[1] * c[1] - b[0] * c[2]) / d;
        dq = (b[0] * c[1] - b[1] * (c[0] - b[1])) / d;
        p = p + dp;
        q = q + dq;
      } else {
        m = 0;
        break;
      }
      ++k;
    }
    if (m != 0) {
      eq2gpq(p, q, raizes, raiz_atual);
      --m;
      --m;
      for (int i = 0; i <= m; ++i) {
        a[m - i] = b[m + 2 - i];
      }
      p = v[m] / v[m - 2];
      q = v[m - 1] / v[m - 2];
    } else {
      if(k > nmi) {
        fprintf(stderr, "Ultrapassou NMI.\n");
      } else {
        fprintf(stderr, "Nao convergiu com valores inicias p e q.\n");
        //TODO: pedir outros valores de p e q e tentar denovo.
      }
      return NULL;
    }
  }
  if (m != 0 && k <= nmi) {
    if (m == 2) {
      eq2gpq(b[3], b[2], raizes, raiz_atual);
    } else {
      raizes[raiz_atual] = -b[2];
    }
  }
  return raizes;
}

#endif

