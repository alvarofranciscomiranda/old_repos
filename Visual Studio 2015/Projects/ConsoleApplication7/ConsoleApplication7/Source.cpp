#include <iostream>
#include <string>
#include <fstream>
#include<cmath>
#include<vector>

using namespace std;

double funcao1(double x) {
	return (1.2 - x) + pow((sin(x + 1.6)), 3);
}

double funcao1d(double x) {
	return 3 * cos(x + 1.6) * pow(sin(x + 1.6), 2) - 1;
}

double zero_newton(double x0) {

	double x1 = x0 - (funcao1(x0) / funcao1d(x0));
	cout << x1 << endl;
	return x1;
}
//_______________________________________________________________________________
double f1(double x, double y) {
	return sin(x + y) - exp(x - y);
}

double f1x(double x, double y) {
	return cos(y + x) - exp(x - y);
}

double f1y(double x, double y) {
	return cos(y + x) + exp(x - y);
}

double f2(double x, double y) {
	return cos(x + y) - pow(x, 2)*pow(y, 2);
}

double f2x(double x, double y) {
	return -sin(y + x) - 2 * x * pow(y, 2);
}

double f2y(double x, double y) {
	return -sin(y + x) - 2 * y * pow(x, 2);
}

double newton(double x, double y) {

	int n = 0;

	while (n != 2) {
		double x0 = x;
		double y0 = y;

		x = x0 - (f1(x0, y0) * f2y(x0, y0) - f2(x0, y0) * f1y(x0, y0)) / (f1x(x0, y0)*f2y(x0, y0) - f2x(x0, y0)*f1y(x0, y0));
		y = y0 - (f2(x0, y0) * f1x(x0, y0) - f1(x0, y0) * f2x(x0, y0)) / (f1x(x0, y0)*f2y(x0, y0) - f2x(x0, y0)*f1y(x0, y0));

		cout << x << "\t" << y << endl;
		n++;
	}
	return 0;
}
//________________________________________________________________________________________
double gauss_seidel(double x1, double x2, double x3, double x4) {

	vector< vector<double> > m = { { 6,0.5,3,0.25,25 },{ 1.2,3,0.25,0.2,10 }, {-1,0.25,4,2,7 }, {2,4,1,8,-12 } };


	for (int i = 0; i < 1; i++)
	{
		double xi1 = x1;
		double xi2 = x2;
		double xi3 = x3;
		double xi4 = x4;

		x1 = (m[0][4] - (m[0][1] * xi2 + m[0][2] * xi3 + m[0][3] * xi4)) / m[0][0];
		x2 = (m[1][4] - (m[1][0] * x1 + m[1][2] * xi3 + m[1][3] * xi4)) / m[1][1];
		x3 = (m[2][4] - (m[2][0] * x1 + m[2][1] * x2 + m[2][3] * xi4)) / m[2][2];
		x4 = (m[3][4] - (m[3][0] * x1 + m[3][1] * x2 + m[3][2] * x3)) / m[3][3];

		cout << x1 << "\t" << x2 << "\t" << x3 << "\t" << x4 << "\t" << endl;
	}


	return 0;
}
//__________________________________________________________________________
double funcao2(double x) {
	if (x == 0.00) return 1.14;
	if (x == 0.25) return 0.49;
	if (x == 0.50) return 0.53;
	if (x == 0.75) return 1.02;
	if (x == 1.00) return 1.18;
	if (x == 1.25) return 1.20;
	if (x == 1.50) return 0.41;
	if (x == 1.75) return 0.78;
	if (x == 2.00) return 0.35;
}

double trapezio(double a, double b) {
	double n = 8;
	double h = (b - a) / n;

	double ST = 0;
	double ST1 = 0;
	double ST2 = 0;

	for (unsigned int i = 1; i < n; i++) {
		ST += 2* funcao2(a + i*h);
	}
	ST += funcao2(a) + funcao2(b);
	ST *= h / 2;


	n = 4;
	h = (b - a) / n;
	for (unsigned int i = 1; i < n; i++) {
		ST1 += 2 * funcao2(a + i*h);
	}
	ST1 += funcao2(a) + funcao2(b);
	ST1 *= h / 2;

	n = 2;
	h = (b - a) / n;
	for (unsigned int i = 1; i < n; i++) {
		ST2 += 2 * funcao2(a + i*h);
	}
	ST2 += funcao2(a) + funcao2(b);
	ST2 *= h/2;

	cout << ST << endl;
	cout << ST1 << endl;
	cout << ST2 << endl;

	cout << (ST - ST1) / 3;


	return ST;
}

double funcao3(double x, double y) {
	if (x == 0 && y == 0) return 1.1;
	if (x == 0.9 && y == 0) return 1.4;
	if (x == 1.8 && y == 0) return 7.7;
	if (x == 0 && y == 0.9) return 2.1;
	if (x == 0.9 && y == 0.9) return 3.1;
	if (x == 1.8 && y == 0.9) return 2.2;
	if (x == 0 && y == 1.8) return 7.3;
	if (x == 0.9 && y == 1.8) return 1.5;
	if (x == 1.8 && y == 1.8) return 1.2;
}
double cubatura(double a1, double a2, double b1, double b2) {
	double hx = (a2 - a1) / 2;
	double hy = (b2 - b1) / 2;

	return hx * hy / 9 * ((5.7 + 1.1 + 1.7 + 1.2) + 4 * (2.1 + 1.5 + 2.2 + 1.4) + 16 * 4.7);
}

//double g1(double x, double y, double z) { return (z); }
//
//double g2(double x, double y, double z) { return (2 + pow(z,2) + z); }
//
//void euler(double x0, double y0, double z0, double h, unsigned int num_iter) {
//
//	// Variables
//	double x = x0;
//	double y = y0;
//	double z = z0;
//	double xn, yn, zn;
//
//	cout << 0 << ":\t" << x << "\t" << y << "\t" << z << endl;
//
//	for (unsigned int i = 1; i <= num_iter; i++) {
//		// Compute the values
//		yn = y + h*g1(x, y, z);
//		zn = z + h*g2(x, y, z);
//		xn = x + h;
//
//		x = xn;
//		y = yn;
//		z = zn;
//
//		// Print the current values
//		cout << i << ":\t" << x << "\t" << y << "\t" << z << endl;
//	}
//}



int main() {
	cout << fixed;
	cout.precision(6);
	
	//const double x0 = 1;
	//const double y0 = 0;
	//const double z0 = 1;
	//const double h = 0.2;
	//const unsigned int num_iter = 2;

	//// Perform the method
	//euler(x0, y0, z0, h, num_iter);


		return 0;
}