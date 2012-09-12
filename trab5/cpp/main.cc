//#define USAR_FLOAT

#include <iostream>
#include <string>
#include <cmath>
#include "seqnlnewton.h"
#include "gaussjordan.h"
#include "lu.h"
#include "policar.h"
#include "newtonbairstow.h"
#include "autovet.h"

using namespace std;

double sisnlin(int i, Vetor &x) {
  switch (i) {
    case 1: return 7 * pow(x(1), 2) * x(3) + 2 * x(2) - 78.625;
    case 2: return 14 * x(1) - x(2) * x(3) + 3 * pow(x(1), 2) - 233.76;
    case 3: return 7 * x(1) * x(2) + 5 * pow(x(1), 4) - 2403.6155;
  }
}

Vetor GaussJordan(Matriz &a, Vetor b) {
  return a.GaussJordan(b);
}

Vetor DecLU(Matriz &a, Vetor b) {
  return a.LU(b);
}

int main() {
  string comando;
  while(cin >> comando) {
    int n;
    if (comando == "") {
      continue;
    } else if (comando[0] == '#') {
      string c;
      getline(cin, c);
      c.erase(0, 1);
      cout << c;
      cout << endl;
    } else if (comando == "nmi") {
      cin >> nmi;
    } else if (comando == "tol") {
      cin >> tol;
    } else if (comando == "seqnlnewton") {
      string metodo;
      cin >> metodo;
      cin >> n;
      Vetor x(n);
      cin >> x;
      if (metodo == "gaussjordan") {
        cout << SeqnlNewton(x, sisnlin, GaussJordan) << endl;
      } else if (metodo == "lu") {
        cout << SeqnlNewton(x, sisnlin, DecLU) << endl;
      } else {
        cout << "Metodo invalido." << endl;
      }
    } else if (comando == "lu") {
      cin >> n;
      MatrizC m(n);
      cin >> m;
      VetorC b(n);
      cin >> b;
      cout << m.LU(b) << endl;
    } else if (comando == "gaussjordan") {
      cin >> n;
      MatrizC m(n);
      cin >> m;
      VetorC b(n);
      cin >> b;
      cout << m.GaussJordan(b) << endl;
    } else if (comando == "autovalor") {
      cin >> n;
      Matriz m(n);
      cin >> m;
      Vetor vp = m.PoliCar();
      //TODO: generalizar ordem de p, usar new
      double p[] = {-vp(3), -vp(2), -vp(1), 1};
      complex<double> *r = newtonbairstow(n, p);
      VetorC av(n);
      for (int i = 1; i <= n; ++i) av(i) = r[n - i];
      cout << av << endl;
    } else if (comando == "autovetor") {
      cin >> n;
      Matriz m(n);
      cin >> m;
      Vetor vp = m.PoliCar();
      //TODO: generalizar ordem de p, usar new
      double p[] = {-vp(3), -vp(2), -vp(1), 1};
      complex<double> *r = newtonbairstow(n, p);
      VetorC av(n);
      for (int i = 1; i <= n; ++i) av(i) = r[n - i];
      MatrizC mc(m);
      MatrizC uv = mc.Autovet(av);
      // normalizando
      for (int i = 1; i <= n; ++i) {
        complex<double> max = 0;
        for (int j = 1; j <= n; ++j)
          max = abs(uv(i, j)) > abs(max) ? uv(i, j) : max;
        for (int j = 1; j <= n; ++j)
          uv(i, j) /= max;
      }
      cout << uv << endl;
    } else {
      cout << "Comando desconhecido." << endl;
    }
  }
  return 0;
}

