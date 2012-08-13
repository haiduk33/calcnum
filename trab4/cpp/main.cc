#include <complex>
#include <iostream>

#include "newtonbairstow.h"

using std::complex;

void imprimir_raiz(complex<double> raiz) {
  printf("%f", raiz.real());
  if (raiz.imag() != 0) {
    printf(" + %fi", raiz.imag());
  }
}

void imprimir(int n, complex<double> raizes[]) {
  printf("{");
  for (int i = 1; i < n; ++i) {
    imprimir_raiz(raizes[i]);
    printf(", ");
  }
  imprimir_raiz(raizes[n]);
  printf("}\n");
  std::cout << std::endl;
}

int main(int argc, char** argv) {
  nmi = 20;
  tol = 1e-15;

  // x4 + 2x3 -13x2 -14x + 24
  // raízes: {1, 3, -4, -2}
  double polinomio[] = {24, -14, -13, 2, 1};

  // Chamar o algoritmo
  complex<double> *raizes = newtonbairstow(4, polinomio);

  // Mostrar raízes
  imprimir(4, raizes);

  return 0;
}

