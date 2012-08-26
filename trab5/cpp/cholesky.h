#ifndef CALCNUM_CHOLESKY_H
#define CALCNUM_CHOLESKY_H

#include <cmath>
#include "matriz.h"

using std::sqrt;

// Algoritmo CHOLESKY
template<typename T>
VetorT<T> MatrizT<T>::Cholesky() {
  int n(m_);
  VetorT<T> x(n);
  T temp, soma = 0;
  // geração dos lij e solução de [L].{X*}={B}
  for (int i = 1; i <= n; ++i) {
    x(i) = 0;
    for (int j = i; j <= n + 1; ++j) {
      soma = a(i, j);
      for (int k = 1; k <= i - 1; ++k)
        soma -= a(k, i) * a(k, j);
      if (i != j) {
        a(i, j) = temp * soma;
      } else {
        temp = 1 / sqrt(soma);
        a(i, j) = temp;
      }
    }
  }
  // solução de [L]t.{X} = {X*}
  for (int i = n; i >= 1; --i) {
    soma = a(i, n + 1);
    for (int k = i + 1; k <= n; ++k)
      soma -= a(i, k) * x(k);
    x(i) = soma * a(i, i);
  }
  return x;
}

#endif

