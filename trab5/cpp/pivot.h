#ifndef CALCNUM_PIVOT_H
#define CALCNUM_PIVOT_H

#include <cmath>
#include <algorithm>
#include "matriz.h"

using std::abs;
using std::swap;

template<typename T>
bool MatrizT<T>::Pivot(const int i) {
  int l(i);
  T c = a(i, i);
  // Procurar um termo maior que o pivot dessa linha
  for (int k = i + 1; k < n_; ++k) {
    if (abs(c) < abs(a(k, i))) {
      c = a(k, i);
      l = k;
    }
  }
  // Se esse for encontrado trocar a linha inteira
  if (l != i) {
    for (int j = 0; j < n_; ++j)
      swap(a(i, j), a(j, i));
    return true;
  } else {
    return false;
  }
}

#endif

