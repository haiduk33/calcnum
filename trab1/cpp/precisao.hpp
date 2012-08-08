#include <cstdlib>
#include <iostream>
#include <cmath>

using namespace std;

template <typename T>
void precisao() {
	T p, d;
	int n;

	// Algoritmo PRECISÃO
	p = 1;// P <- 1
	while (p + 1 > 1) {// Enquanto P+1 > 1 executar
		p /= 2;// P <- P/2
	}// Fim (Enquanto)
	p *= 2;// P <- 2 * P
	d = abs(floor(log10(p)));// D <- abs(int(log(P)))
	n = floor(abs(log2(p)));// N2 <- int(abs(log(P))/log(2)) *sic
	cout << "Precisao: " << p << endl;// Escrever "Precisão:"; P
	cout << "Numero de digitos significativos decimais: " << d << endl;// Escrever "Núm. digitos significativos decimais:"; D
	cout << "Numero de bits da mantissa: " << n << endl;// Escrever "Núm. bits da mantissa:"; N2
}

