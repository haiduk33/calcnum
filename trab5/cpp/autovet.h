#ifndef CALCNUM_AUTOVET_H
#define CALCNUM_AUTOVET_H

#include "matriz.h"
#include "vetor.h"

// Algoritmo AUTOVET
template<typename T>
MatrizT<T> MatrizT<T>::Autovet(VetorT<T> autoval) const {
  const int n = m_;
  MatrizT<T> b(*this);
  MatrizT<T> x(n);
  VetorT<T> c(n);
  for (int i = 1; i <= n; ++i)
    for (int j = 1; j <= n; ++j)
      x(i, j) = i == j ? 1 : 0;
  // k varia de 1 até n-1
  for (int k = 1; k < n; ++k) {
    T p = 0;
    for (int i = 1; i <= n; ++i)
      p += b(i, i);
    p /= k;
    for (int i = 1; i <= n; ++i) {
      b(i, i) -= p;
      for (int j = 1; j <= n; ++j)
        x(i, j) = autoval(j) * x(i, j) + b(i, j);
    }
    for (int i = 1; i <= n; ++i) {
      for (int j = 1; j <= n; ++j) {
        c(j) = b(j, i);
        b(j, i) = 0;
      }
      for (int j = 1; j <= n; ++j)
        for (int l = 1; l <= n; ++l)
          b(j, i) += a(j, l) * c(l);
    }
  }
  return x;
}

#endif

