#ifndef CALCNUM_POLINOMIO_H
#define CALCNUM_POLINOMIO_H

#include "vetor.h"

// Polinomio de ordem n de elementos do tipo T
template<typename T>
class PolinomioT : public VetorT<T> {
 public:
  // Retorna o valor do 
};

#ifdef USAR_FLOAT
typedef PolinomioT<complex<float> > PolinomioC;
#else
#ifdef USAR_LONG_DOUBLE
typedef PolinomioT<complex<long double> > PolinomioC;
#else
typedef PolinomioT<complex<double> > PolinomioC;
#endif
#endif
#ifdef USAR_FLOAT
typedef PolinomioT<float> Polinomio;
#else
#ifdef USAR_LONG_DOUBLE
typedef PolinomioT<long double> Polinomio;
#else
typedef PolinomioT<double> Polinomio;
#endif
#endif

#endif

