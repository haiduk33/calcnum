//#define USAR_FLOAT

#include <iostream>
#include <string>
//#include "seqnlnewton.h"
#include "gaussjordan.h"
#include "lu.h"
//#include "policar.h"

using namespace std;

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
    } else if (comando == "seqnlnewton") {
      string metodo;
      cin >> metodo;
      cout << "TODO" << endl;
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
      cout << "TODO" << endl;
    } else if (comando == "autovetor") {
      cin >> n;
      Matriz m(n);
      cin >> m;
      cout << "TODO" << endl;
    } else {
      cout << "Comando desconhecido." << endl;
    }
  }
  return 0;
}

