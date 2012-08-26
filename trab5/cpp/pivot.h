#ifndef CALCNUM_PIVOT_H
#define CALCNUM_PIVOT_H

#include <cmath>
#include <algorithm>
#include "matriz.h"

using std::abs;
using std::swap;

// Algoritmos PIVOT

template<typename T>
int MatrizT<T>::Pivot(const int i) {
  int l(i);
  T c = a(i, i);
  // Procurar um termo maior que o pivot dessa linha
  for (int k = i + 1; k <= m_; ++k) {
    if (abs(a(k, i)) > abs(c)) {
      c = a(k, i);
      l = k;
    }
  }
  // Se esse for encontrado trocar a linha inteira
  if (l != i) {
    for (int j = 1; j <= n_; ++j)
      swap(a(i, j), a(l, j));
    return l;
  } else {
    return 0;
  }
}

template<typename T>
int MatrizT<T>::Pivot(const int i, VetorT<T> &b) {
  int l = Pivot(i);
  if (l) swap(b(i), b(l));
  return l;
}

template<typename T>
int MatrizT<T>::Pivot(const int i, MatrizT<T> &m) {
  int l = Pivot(i);
  if (l)
    for (int j = 1; j <= n_; ++j)
      swap(m(i, j), m(l, j));
  return l;
}

#endif

