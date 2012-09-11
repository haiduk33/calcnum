//#define USAR_FLOAT

#include <iostream>
#include <string>
#include "determinante.h"
#include "cholesky.h"
#include "lu.h"
#include "luc.h"
#include "inversa.h"
#include "inversalocal.h"
#include "gaussjordan.h"
#include "gaussjacobi.h"
#include "gaussseidel.h"

#ifndef TOLNMI
#define TOLNMI
double tol;
int nmi;
#endif

using namespace std;

int main() {
  string comando;
  while(cin >> comando) {
    int n;
    if (comando == "") {
      continue;
    } else if (comando[0] == '#') {
      char c;
      while (cin.peek() != '\n')
        cin >> c;
    } else if (comando == "determinante") {
      cin >> n;
      MatrizC m(n);
      cin >> m;
      cout << m.Determinante() << endl;
    } else if (comando == "cholesky") {
      cin >> n;
      MatrizC m(n, n + 1);
      cin >> m;
      cout << m.Cholesky() << endl;
    } else if (comando == "lu") {
      cin >> n;
      MatrizC m(n);
      cin >> m;
      VetorC b(n);
      cin >> b;
      cout << m.LU(b) << endl;
    } else if (comando == "luc") {
      cin >> n;
      MatrizC m(n, n + 1);
      cin >> m;
      cout << m.LUC() << endl;
    } else if (comando == "inversa") {
      cin >> n;
      MatrizC m(n);
      cin >> m;
      cout << m.Inversa() << endl;
    } else if (comando == "inversalocal") {
      cin >> n;
      MatrizC m(n);
      cin >> m;
      if (m.InversaLocal()) {
        cout << m << endl;
      } else {
        cout << "Matriz nao possui inversa." << endl;
      }
    } else if (comando == "gaussjordan") {
      cin >> n;
      MatrizC m(n);
      cin >> m;
      VetorC b(n);
      cin >> b;
      cout << m.GaussJordan(b) << endl;
    } else if (comando == "nmi") {
      cin >> nmi;
    } else if (comando == "tol") {
      cin >> tol;
    } else if (comando == "gaussjacobi") {
      cin >> n;
      MatrizC m(n, n + 1);
      cin >> m;
      VetorC x0(n);
      cin >> x0;
      cout << m.GaussJacobi(x0) << endl;
    } else if (comando == "gaussseidel") {
      cin >> n;
      MatrizC m(n, n + 1);
      cin >> m;
      VetorC x0(n);
      cin >> x0;
      cout << m.GaussSeidel(x0) << endl;
    } else {
      cout << "Comando desconhecido." << endl;
    }
  }
  return 0;
}

