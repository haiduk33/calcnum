#include <complex>
#include <iostream>

#include "newtonbairstow.h"

using std::complex;

int main(int argc, char** argv) {
  nmi = 100;
  tol = 1e-5;
  double p[] = {1, 2, -13, -14, 24};
  //double p[] = {24, -14, -13, 2, 1};
  complex<double> *raizes = newtonbairstow(p, 5);
  for (int i = 0; i < 4; ++i) {
    std::cout << raizes[i];
  }
  std::cout << std::endl;
  return 0;
}

