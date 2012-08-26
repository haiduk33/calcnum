#ifndef CALCNUM_INVERSA
#define CALCNUM_INVERSA

#include "matriz.h"

template<typename T>
MatrizT<T> MatrizT<T>::Inversa() {
  const int n(m_);
  // geração da matriz identidade [AI]
  MatrizT<T> ai(n);
  for (int i = 1; i <= n; ++i)
    for (int j = 1; j <= n; ++j)
      ai(i, j) = i == j ? 1 : 0;
  // caçulo da inversa que será [AI] no final
  T temp, det = 1;
  for (int i = 1; i <= n && det != 0 ; ++i) {
    Pivot(i, ai);
    temp = a(i, i);
    det *= temp;
    if (temp != 0) {
      for (int j = 1; j <= n; ++j) {
        a(i, j) /= temp;
        ai(i, j) /= temp;
      }
      for (int k = 1; k <= n; ++k) {
        if (k != i) {
          temp = a(k, i);
          for (int j = 1; j <= n; ++j) {
            a(k, j) -= temp * a(i, j);
            ai(k, j) -= temp * ai(i, j);
          }
        }
      }
    }
  }
  return ai;
}

#endif

