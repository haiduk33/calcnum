#include "magnitude.hpp"
#include "precisao.hpp"

int main(int argc, char** argv) {
	cout << "Magnitude usando float:" << endl;
	magnitude<float>();
	cout << endl;

	cout << "Magnitude usando double:" << endl;
	magnitude<double>();
	cout << endl;

	cout << "Magnitude usando long double:" << endl;
	magnitude<long double>();
	cout << endl;

	cout << "Precisão usando float:" << endl;
	precisao<float>();
	cout << endl;

	cout << "Precisão usando double:" << endl;
	precisao<double>();
	cout << endl;

	cout << "Precisão usando long double:" << endl;
	precisao<long double>();
	cout << endl;
}
