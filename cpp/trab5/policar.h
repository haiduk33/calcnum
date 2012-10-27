#ifndef CALCNUM_POLICAR_H
#define CALCNUM_POLICAR_H

#include "matriz.h"
#include "vetor.h"

// Algoritmo POLICAR
template<typename T>
VetorT<T> MatrizT<T>::PoliCar() const {
  const int n = m_;
  VetorT<T> p(n);
  VetorT<T> c(n);
  MatrizT<T> b(*this);
  for (int i = 1; i <= n; ++i) {
    p(i) = 0;
    for (int j = 1; j <= n; ++j)
      p(i) += b(j, j);
    p(i) /= i;
    for (int j = 1; j <= n; ++j)
      b(j, j) -= p(i);
    for (int j = 1; j <= n; ++j) {
      for (int k = 1; k <= n; ++k) {
        c(k) = b(k, j);
        b(k, j) = 0;
      }
      for (int k = 1; k <= n; ++k)
        for (int l = 1; l <= n; ++l)
          b(k, j) += a(k, l) * c(l);
    }
  }
  return p;
}

#endif

