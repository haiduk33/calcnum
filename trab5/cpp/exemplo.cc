#define USAR_FLOAT

#include <iostream>
#include <string>
#include "determinante.h"
#include "cholesky.h"

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
    }
  }
  return 0;
}

