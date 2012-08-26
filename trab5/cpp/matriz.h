#ifndef CALCNUM_MATRIZ_H
#define CALCNUM_MATRIZ_H

#include <algorithm>
#include <iostream>

using std::ostream;
using std::istream;
using std::copy;

template<typename T> class VetorT;

// Matriz m x n de elementos do tipo T
// segue disposição mostrada no link abaixo
// <http://en.wikipedia.org/wiki/Matrix_(mathematics)>
template<typename T>
class MatrizT {
 public:
  // Matriz quadrada de ordem n
  MatrizT(const int n) : m_(n), n_(n), matriz_(new T[n * n]) {}
  // Matriz retangular m x n
  MatrizT(const int m, const int n) : m_(m), n_(n), matriz_(new T[m * n]) {}
  // Copiar outra matriz
  MatrizT(const MatrizT &outra)
      : m_(outra.m_),
        n_(outra.n_),
        matriz_(new T[outra.m_ * outra.n_]) {
    copy(outra.matriz_, outra.matriz_ + m_ * n_, matriz_);
  }
  ~MatrizT() { delete[] matriz_; }

  // Operador para acessar o elemento i,j chamando m(i,j).
  // Se i ou j estiver fora do tamanho da matriz o comportamento
  // não é definido, pode ser retornado o termo errado ou ocorrerá
  // um erro de acesso na memória.
  inline T &operator()(const int i, const int j) { return matriz_[j - 1 + (i - 1) * n_]; }
  inline T operator()(const int i, const int j) const { return matriz_[j - 1 + (i - 1) * n_]; }

  // Métodos para ler a ordem da matriz.
  inline int m() const { return m_; }
  inline int n() const { return n_; }
  // Retorna true se for quadrada.
  inline bool Quadrada() const { return m_ == n_; }

  //// Os seguintes algoritmos são implementados em .h próprios.
  // Calcula o determinante assumindo que a matriz é quadrada.
  // Métodos que não são const são destrutivos e alteram a própria matriz
  T Determinante();
  MatrizT Inversa() const;
  // inversa local
  void Inversa();
  // Pivoteamento da i-ésima linha pra baixo, retorna k se trocar com a k-ésima
  // linha, se não houver troca retorna 0 (poderia retorna i, mas 0 é mais pratico).
  int Pivot(const int i);
  // Faz a troca também no vetor b.
  int Pivot(const int i, VetorT<T> &b);
  // Faz a troca também na matriz m
  int Pivot(const int i, MatrizT<T> &m);
  /// Resolução de sistemas usando os métodos de (b é o vetor dos coeficientes):
  VetorT<T> LU(VetorT<T> &b);
  // Assume-se que m = n + 1 e a última coluna é o vetor dos coeficientes.
  VetorT<T> LUC();
  VetorT<T> GaussJordan(VetorT<T> &b);
  VetorT<T> GaussJacobi(VetorT<T> &b);
  VetorT<T> GaussSeidel(VetorT<T> &b);
  // Assume-se que m = n + 1 e a última coluna é o vetor dos coeficientes.
  VetorT<T> Cholesky();
  // Assume que a matriz é tridiagonal (não verifica se é).
  VetorT<T> Tridiagonal() const;

 private:
  // syntatic sugar
  inline T &a(const int i, const int j) { return (*this)(i, j); }

  int m_, n_;
  T *matriz_;
};

// Definindo como imprimir uma matriz
template<typename T>
ostream &operator<< (ostream &out, const MatrizT<T> &matriz) {
  //TODO: implementar
  return out;
}

// Definindo como ler uma matriz
template<typename T>
istream &operator>> (istream &in, MatrizT<T> &matriz) {
  for (int i = 1; i <= matriz.m(); ++i)
    for (int j = 1; j <= matriz.n(); ++j)
      in >> matriz(i, j);
  return in;
}

#ifdef USAR_FLOAT
typedef MatrizT<float> Matriz;
#elif USAR_LONG_DOUBLE
typedef MatrizT<long double> Matriz;
#else
typedef MatrizT<double> Matriz;
#endif

#endif

