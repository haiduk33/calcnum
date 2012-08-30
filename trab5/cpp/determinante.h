#ifndef CALCNUM_DETERMINANTE_H
#define CALCNUM_DETERMINANTE_H

#include "matriz.h"
#include "vetor.h"
#include "pivot.h"

// Algoritmo DETERMINANTE
template<typename T>
T MatrizT<T>::Determinante() {
  const int n(m_);
  T temp, det = 1;
  for (int i = 1; i <= n && det != (T)0; ++i) {
    if (Pivot(i)) det *= -1;
    temp = a(i, i);
    det *= temp;
    if (temp != (T)0) {
      for (int j = i; j <= n; ++j)
        a(i, j) /= temp;
      for (int k = i + 1; k <= n; ++k) {
        temp = a(k, i);
        for (int j = i + 1; j <= n; ++j)
          a(k, j) -= temp * a(i, j);
      }
    }
  }
  return det;
}

#endif

