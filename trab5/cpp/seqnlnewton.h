#ifndef CALCNUM_SEQNLNEWTON_H
#define CALCNUM_SEQNLNEWTON_H

#include <cmath>
#include "matriz.h"
#include "vetor.h"

#ifndef TOLNMI
#define TOLNMI
double tol;
int nmi;
#endif

using std::abs;

// Algoritmo SEQNL-NEWTON
template<typename T>
VetorT<T> SeqnlNewton(VetorT<T> &x,
                      T (*f)(int, VetorT<T> &),
                      VetorT<T> (*metodo)(MatrizT<T> &, VetorT<T>)) {
  const int n = x.n();
  MatrizT<T> a(n);
  VetorT<T> b(n);
  int k = 0;
  T zm = 1;
  while (k <= nmi && abs(zm) > tol) {
    for (int i = 1; i <= n; ++i) {
      for (int j = 1; j <= n; ++j) {
        x(j) += tol;
        a(i, j) = f(i, x);
        x(j) -= 2 * tol;
        a(i, j) = (a(i, j) - f(i, x)) / (2 * tol);
        x(j) += tol;
      }
      b(i) = -f(i, x);
    }
    VetorT<T> z = metodo(a, b);
    zm = 0;
    for (int i = 1; i <= n; ++i) {
      zm = abs(z(i)) > abs(zm) ? z(i) : zm;
      x(i) += z(i);
    }
    ++k;
  }
  //TODO: verificar se ultrapassou nmi
  return x;
}

#endif

