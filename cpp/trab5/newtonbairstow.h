#ifndef NEWTONBAIRSTOW_H
#define NEWTONBAIRSTOW_H

#include <complex>
#include <algorithm>
#include <iomanip>
#include <vector>

#include "eq2gpq.h"

#define MAXN 20

using std::complex;
using std::abs;
using std::sort;

#ifndef TOLNMI
#define TOLNMI
double tol;
int nmi;
#endif


bool abscmp(const double &a, const double &b) {
  return abs(a) < abs(b);
}

// Algoritmo NEWTON-BAIRSTOW(N,A)
complex<double> *newtonbairstow(int n, double *a) {
  static complex<double> raizes[MAXN];
  double v[MAXN + 1], b[MAXN + 3], c[MAXN + 2];
  double p, q, dp, dq;
  int m, k;

  // Normalizar coeficientes e aproveitar para copiar a para v
  for (int i = n; i >= 0; --i) {
    a[i] = a[i] / a[n];
    v[i] = a[i];
  }
  m = n;

  // O vetor v é uma cópia de a, vamos ordenar-lo pelos valores
  // absolutos dos coeficientes para esolher p e q iniciais
  sort(v, v + n + 1, abscmp);
  p = v[m] / v[m - 2];
  q = v[m - 1] / v[m - 2];

  int raiz_atual = 0;
  while (m > 2) {
    // Resetando os primeiros valores de b e c, bem como dp e dq
    b[m + 2] = b[m + 1] = c[m + 1] = c[m + 0] = 0;
    dp = dq = 1;
    k = 0;
    //printf(" k      p      q\n");
    //printf("%2i % 2.3f % 2.3f\n", k, p, q);
    while (abs(dp) + abs(dq) > tol && k <= nmi) {
      // Computa-se os coeficientes de b e c assim como o resto
      // que serão aproximadamente b[1], b[2], c[0] e c[1].
      // Note que é nescessário fazer isso em cada iteração
      // pois p e q mudam.
      for (int i = m; i >= 0; --i) {
        b[i] = a[i] - p * b[i + 1] - q * b[i + 2];
        c[i] = b[i + 1] - p * c[i + 1] - q * c[i + 2];
      }
      // Newton-Raphson para duas dimensões
      // a seguinte operação é a inversão de uma matriz 2x2
      // primeiro calculamos um termo que será nulo quando não
      // for inversível, depois o resto da inversão.
      double d = c[1] * c[1] - (c[0] - b[1]) * c[2];
      if (abs(d) > 0) {
        dp = (b[1] * c[1] - b[0] * c[2]) / d;
        dq = (b[0] * c[1] - b[1] * (c[0] - b[1])) / d;
        p = p + dp;
        q = q + dq;
        //printf("%2i % 2.3f % 2.3f\n", k, p, q);
      } else {
        // nesse caso não é inversível, podemos sair do loop
        // e avisar que tais p e q não convergíram
        m = 0;
        break;
      }
      ++k;
    }
    //printf("\n");
    if (m != 0) {
      // Uma vez calculada a aproximação resolvemos a equação
      // do segundo grau
      eq2gpq(p, q, raizes, raiz_atual);
      // Esse é um jeito eficiente de incrementar m:
      --m; --m;
      // Deve-se atualizar o vetor dos coeficientes com o resultado
      // da divisão já que encontramos duas raízes.
      for (int i = 0; i <= m; ++i) {
        a[m - i] = b[m + 2 - i];
      }
      // Novas aproximações de p e q, vale ressaltar que ainda
      // está sendo utilizado os coeficientes antigos.
      p = v[m] / v[m - 2];
      q = v[m - 1] / v[m - 2];
    } else {
      if(k > nmi) {
        ;//fprintf(stderr, "Ultrapassou NMI.\n");
      } else {
        ;//fprintf(stderr, "Nao convergiu com valores inicias p e q.\n");
        //TODO: pedir outros valores de p e q e tentar denovo.
      }
      return NULL;
    }
  }
  if (m != 0 && k <= nmi) {
    // Caso restem 3 coeficientes (m=2) temos uma equação do
    // segundo grau, caso contrário a raiz é imediata
    if (m == 2) {
      eq2gpq(b[3], b[2], raizes, raiz_atual);
    } else {
      raizes[raiz_atual] = -b[2];
    }
  }
  return raizes;
}

#endif

