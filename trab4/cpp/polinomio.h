#ifndef POLINOMIO_H
#define POLINOMIO_H
#include <vector>

using std::vector;

// Essa classe é um vetor dos coeficientes
// também pode ser usada para calcular
template <typename tipo>
class Polinomio : public vector<tipo> {
  public:
    Polinomio(size_t n) : vector<tipo>(n, tipo()) {}
    Polinomio(tipo *comeco, tipo *fim) : vector<tipo>(comeco, fim) {}

    // Esse operador serve apenas para poder chamar o valor
    // do polinomio como se fosse um call, por exemplo:
    // Polinomio p = {2, 3, 4};
    // p(5); // deve retornar 2*5^2 + 3*5 + 4 = 69
    tipo operator()(tipo x) {/*TODO: implementar*/}
};

#endif

