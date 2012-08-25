#ifndef CALCNUM_LUC
#define CALCNUM_LUC

#include "matriz.h"
#include "vetor.h"
#include "pivot.h"

template<typename T>
VetorT<T> MatrizT<T>::LUC() {
  const int n(m_);
  VetorT<T> x(n);
  T soma = 0;
  // geração das matrizes [L] e [U] e solução de [L].{X*} = {B}
  for (int i = 1; i <= n; ++i) {
    Pivot(i);
    for (int j = 1; j <= n + 1; ++j) {
      int l = j < i ? j - 1 : i - 1;
      soma = a(i, j);
      for (int k = 1; k <= l; ++k)
        soma -= a(i, k) * a(k, j);
      a(i, j) = j <= i ? soma : soma / a(i, i);
    }
    x(i) = 0;
  }
  // solução de [U].{X} = {X*}
  for (int i = n; i >= 1; --i) {
    soma = a(i, n + 1);
    for (int j = i + 1; j <= n; ++j)
      soma -= a(i, j) * x(j);
    x(i) = soma;
  }
  return x;
}

#endif

