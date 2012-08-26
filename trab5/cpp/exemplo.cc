//#define USAR_FLOAT

#include <iostream>
#include <string>
#include "determinante.h"
#include "cholesky.h"
#include "lu.h"
#include "luc.h"
#include "inversa.h"
#include "inversalocal.h"

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
      Matriz m(n);
      cin >> m;
      cout << m.Determinante() << endl;
    } else if (comando == "cholesky") {
      cin >> n;
      Matriz m(n, n + 1);
      cin >> m;
      cout << m.Cholesky() << endl;
    } else if (comando == "lu") {
      cin >> n;
      Matriz m(n);
      cin >> m;
      Vetor b(n);
      cin >> b;
      cout << m.LU(b) << endl;
    } else if (comando == "luc") {
      cin >> n;
      Matriz m(n, n + 1);
      cin >> m;
      cout << m.LUC() << endl;
    } else if (comando == "inversa") {
      cin >> n;
      Matriz m(n);
      cin >> m;
      cout << m.Inversa() << endl;
    } else if (comando == "inversalocal") {
      cin >> n;
      Matriz m(n);
      cin >> m;
      if (m.InversaLocal()) {
        cout << m << endl;
      } else {
        cout << "Matriz nao possui inversa." << endl;
      }
    } else {
      cout << "Comando desconhecido." << endl;
    }
  }
  return 0;
}

