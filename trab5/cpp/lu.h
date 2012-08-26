#ifndef CALCNUM_LU_H
#define CALCNUM_LU_H

#include "matriz.h"
#include "vetor.h"
#include "pivot.h"

// Algoritmo LU
template<typename T>
VetorT<T> MatrizT<T>::LU(VetorT<T> &b) {
  const int n = m_;
  VetorT<T> x(n);
  T soma = 0;
  // geração das matrizes [L] e [U]
  for (int i = 1; i <= n; ++i) {
    Pivot(i, b);
    for (int j = 1; j <= n; ++j) {
      int l = j < i ? j - 1 : i - 1;
      soma = a(i, j);
      for (int k = 1; k <= l; ++k)
        soma -= a(i, k) * a(k, j);
      a(i, j) = j <= i ? soma : soma / a(i, i);
    }
    x(i) = 0;
  }
  // solução de [L].{X*} = {B}
  for (int i = 1; i <= n; ++i) {
    soma = b(i);
    for (int k = 1; k <= i - 1; ++k)
      soma -= a(i, k) * x(k);
    x(i) = soma / a(i, i);
  }
  // solução de [U].{X} = {X*}
  for (int i = n; i >= 1; --i) {
    soma = x(i);
    for (int j = i + 1; j <= n; ++j)
      soma -= a(i, j) * x(j);
    x(i) = soma;
  }
  return x;
}

#endif

