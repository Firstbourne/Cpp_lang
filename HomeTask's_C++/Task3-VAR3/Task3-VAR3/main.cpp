// Bakhtiarov A. V. Group: 3821B1PR2

#pragma once
#include <iostream>
#include <cmath>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

class Taylor {
protected:
	vector< long double> coff;
	double eps = 0.0001;
	double x = 10;
	int N = 100;
	std::string formula;
public:
	Taylor() {

	}

	~Taylor();

	void set_eps(double _eps) {
		eps = _eps;
	}
	void set_x(double _x) {
		x = _x;
	}
	void set_N(int _N) {
		N = _N;
	}

	double get_eps() {
		return eps;
	}
	double get_x() {
		return x;
	}
	int get_N() {
		return N;
	}

	// Factorial 
	long double factorial(double n) {
		if (n < 0) return 0;
		if (n == 1 || n == 0) return 1;
		return n * factorial(n - 1);
	}

	// Operation SinT
	long double sinT(double x, double eps, int N, int i) {
		double etalon = sin(x), different;
		long double result = 0, coeff = 0;
		int count = 0;

		for (i = 1; i < N; i++) {
			result += pow(-1, i + 1) * pow(x, 2 * i - 1) / factorial(2 * i - 1);
			coeff = pow(-1, i + 1) * pow(x, 2 * i - 1) / factorial(2 * i - 1);
			if (fabs(etalon - result) < eps) break;
			coff.push_back(coeff);
		}
		different = fabs(etalon - result);
		count = i - 1;
	}
};

int main() {
	std::cout << "Hello, programm started! \n";

	double epsT, xT;
	int Nt;

	Taylor taylor = Taylor();

	std::cout << "Enter eps: \n";
	std::cin >> epsT;
	std::cout << "Enter x: \n";
	std::cin >> xT;
	std::cout << "Enter N: \n";
	std::cin >> Nt;

	taylor.set_eps(epsT);
	taylor.set_x(xT);
	taylor.set_N(Nt);
}