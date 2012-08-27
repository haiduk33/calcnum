#ifndef CALCNUM_GAUSSSIEDEL_H
#define CALCNUM_GAUSSSIEDEL_H

#include <cmath>
#include "matriz.h"
#include "vetor.h"

#ifndef TOLNMI
#define TOLNMI
double tol;
int nmi;
#endif

using std::abs;

// Algoritmo GAUSS-SEIDEL
template<typename T>
VetorT<T> MatrizT<T>::GaussSeidel(VetorT<T> &x) {
  const int n(m_);
  bool ok = false;
  for (int k = 1; k <= nmi && !ok; ++k) {
    ok = true;
    for (int i = 1; i <= n; ++i) {
      T soma = a(i, n + 1);
      for (int j = 1; j <= n; ++j)
        if (j != i) soma -= a(i, j) * x(j);
      T temp = x(i);
      x(i) = soma / a(i, i);
      if (abs(x(i) - temp) > tol)
        ok = false;
    }
  }
  //FIXME: se k > nmi, x não é válido.
  return x;
}

#endif

