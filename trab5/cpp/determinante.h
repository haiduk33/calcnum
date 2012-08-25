#ifndef CALCNUM_DETERMINANTE_H
#define CALCNUM_DETERMINANTE_H

#include "matriz.h"
#include "vetor.h"
#include "pivot.h"

template<typename T>
T MatrizT<T>::Determinante() {
  T det(1);
  for (int i = 1; i <= n_ && det != 0; ++i) {
    if (Pivot(i)) det *= -1;
    T p = a(i, i);
    det *= p;
    if (p != 0) {
      for (int j = i; j <= n_; ++j)
        a(i, j) /= p;
      for (int k = i + 1; k <= n_; ++k) {
        p = a(k, i);
        for (int j = i + 1; j <= n_; ++j)
          a(k, j) -= p * a(i, j);
      }
    }
  }
  return det;
}

#endif

