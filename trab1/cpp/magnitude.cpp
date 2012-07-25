#include <cstdlib>
#include <iostream>
#include <cmath>

using namespace std;

template <typename T>
void precisao() {
	T z, m;
	int n;

	//Algoritmo MAGNITUDE
	z = 1;// Z <- 1
	while (z > 0) {// Enquanto Z > 0 executar
		m = z;// M <- Z
		z /= 2;// Z <- Z/2
	}// Fim (Enquanto)
	n = floor(log2(abs(log(m))) + 1);// N1 <- int(log(abs(log(M)/log(2))+1)/log(2))
	cout << "Magnitude: " << m << endl;// Escrever "Magnitude:"; M
	cout << "Numero de bits do expoente: " << n << endl;// Escrever "Número de bits do expoente:"; N1
}

int main(int argc, char** argv) {
	cout << "Magnitude usando float:" << endl;
	precisao<float>();
	cout << endl;

	cout << "Magnitude usando double:" << endl;
	precisao<double>();
}

