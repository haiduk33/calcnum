#include <complex>
#include <iostream>

#include "newtonbairstow.h"

using std::complex;

void imprimir_raiz(complex<double> raiz) {
  if (raiz.real() != 0.0) printf("%f", raiz.real());
  if (raiz.imag() != 0.0) printf("%+fi", raiz.imag());
  if (raiz == 0.0) printf("0");

}

void imprimir(int n, complex<double> raizes[]) {
//void imprimir(int n, vector<complex<double> > &raizes) {
  printf("{");
  for (int i = 0; i < n - 1; ++i) {
    imprimir_raiz(raizes[i]);
    printf(", ");
  }
  imprimir_raiz(raizes[n - 1]);
  printf("}\n\n");
}

void mostrar(int n, double coeficientes[]) {
  printf("%f*x^%i ", coeficientes[n], n);
  for(int i = n - 1; i > 1; --i) {
    printf("%+f*x^%i ", coeficientes[i], i);
  }
  printf("%+f*x ", coeficientes[1]);
  printf("%+f\n", coeficientes[0]);
}

void exemplo(int n, double polinomio[]) {
  printf("Polinomio: ");
  mostrar(n, polinomio);
  printf("Raizes: ");
  //vector<complex<double> > raizes(n);
  complex<double> *raizes = newtonbairstow(n, polinomio);
  imprimir(n, raizes);
}

int main(int argc, char** argv) {
  nmi = 100;
  tol = 1e-4;

  // x4 + 2x3 -13x2 -14x + 24
  // raízes: {1, 3, -4, -2}
  double pol0[] = {24, -14, -13, 2, 1};
  exemplo(4, pol0);

  // x5 + 2x4 -13x3 -14x2 + 24x + 0
  // raízes: {1, 3, -4, -2, 0}
  double pol1[] = {0, 24, -14, -13, 2, 1};
  exemplo(5, pol1);

  // 9x5 +7.5x4 -2x3 + 10x2 -11x +2.5
  // raízes: {i, -i, 1/2, -5/3, 1/3}
  double pol2[] = {0, 2.5, -11, 10, -2, 7.5, 9};
  exemplo(6, pol2);

  // x7 -3x6 +6x5 -2x3 +7x2 -x +8
  // raízes: {-0.122+-0.834i, 1.1487+-0.724i, 0.660+-1.869i, -1.049}
  double pol3[] = {8, -1, 7, -2, -5, 6, -3, 1};
  exemplo(7, pol3);

  // x9 -44x8 +21x7 -13x6 +15.1x5 -3x4 +2x2 -11x +2.4
  double pol4[] = {2.4, -11, 2, 0, -3, 15.1, -13, 21, -44, 1};
  exemplo(9, pol4);

  return 0;
}

