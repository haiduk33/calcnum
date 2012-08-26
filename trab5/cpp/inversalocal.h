#ifndef CALCNUM_INVERSALOCAL_H
#define CALCNUM_INVERSALOCAL_H

#include <algorithm>
#include "matriz.h"
#include "pivot.h"

using std::swap;

template<typename T>
bool MatrizT<T>::InversaLocal() {
  const int n(m_);
  VetorT<int> v(n);
  T temp, det = 1;
  for (int i = 1; i <= n && det != 0 ; ++i) {
    v(i) = Pivot(i);
    temp = a(i, i);
    a(i, i) = 1;
    det *= temp;
    if (temp != 0) {
      for (int j = 1; j <= n; ++j)
        a(i, j) /= temp;
      for (int k = 1; k <= n; ++k) {
        if (k != i) {
          temp = a(k, i);
          a(k, i) = 0;
          for (int j = 1; j <= n; ++j)
            a(k, j) -= temp * a(i, j);
        }
      }
    }
  }
  if (det != 0) {
    for (int j = n; j >= 1; --j)
      if (v(j))
        for (int i = 1; i <= n; ++i)
          swap(a(i, j), a(i, v(j)));
    return true;
  } else {
    return false;
  }
}

#endif

