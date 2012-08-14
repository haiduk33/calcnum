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

void mostrar(int n, double coeficientes[]) {
  for(int i = n; i > 1; --i) {
    printf("%f*x^%i + ", coeficientes[i], i);
  }
  printf("%f*x + ", coeficientes[1]);
  printf("%f\n", coeficientes[0]);
}

void exemplo(int n, double polinomio[]) {
  printf("Polinomio: ");
  mostrar(n, polinomio);
  printf("Raizes: ");
  imprimir(n, newtonbairstow(n, polinomio));
}

int main(int argc, char** argv) {
  nmi = 100;
  tol = 1e-15;

  // x4 + 2x3 -13x2 -14x + 24
  // raízes: {1, 3, -4, -2}
  double pol1[] = {24, -14, -13, 2, 1};
  exemplo(4, pol1);

  // 9x5 +7.5x4 -2x3 + 10x2 -11x +2.5
  // raízes: {i, -i, 1/2, -5/3, 1/3}
  double pol2[] = {2.5, -11, 10, -2, 7.5, 9};
  exemplo(5, pol2);

  return 0;
}

