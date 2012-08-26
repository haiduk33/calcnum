#ifndef CALCNUM_GAUSSJORDAN_H
#define CALCNUM_GAUSSJORDAN_H

#include "matriz.h"

// Algoritmo GAUSS-JORDAN
template<typename T>
VetorT<T> MatrizT<T>::GaussJordan(VetorT<T> &b) {
  const int n(m_);
  T temp;
  for (int i = 1; i <= n && temp != 0; ++i) {
    Pivot(i, b);
    temp = a(i, i);
    if (temp != 0) {
      for (int j = i; j <= n; ++j)
        a(i, j) /= temp;
      b(i) /= temp;
      for (int k = 1; k <= n; ++k) {
        if (k != i) {
          T temp2 = a(k, i);
          for (int j = i; j <= n; ++j)
            a(k, j) -= temp2 * a(i, j);
          b(k) -= temp2 * b(i);
        }
      }
    }
  }
  //FIXME: resposta não é valida quando temp == 0
  return b;
}

#endif

