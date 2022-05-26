#define _USE_MATH_DEFINES
#include <iostream>
#include <cmath>

using namespace std;

double F(double x)
{
	if (x <= 1)
		return 1;
	return x * F(x - 1);
}

double CalcCos(double x, double e, int k = 1)
{
	double d = pow(-1.0, k) * pow(x, 2.0 * k) / F(2.0 *k);
	if (abs(d) < e)
		return 1 + d;
	return d + CalcCos(x,e,k+1);
}

double Cos(double x, double e) {
	return round(CalcCos(x, e) * 10000) / 10000;
}

int main()
{
	cout << "cos(Pi): " << Cos(M_PI, 0.001) << endl;
	cout << "cos(Pi/2): " << Cos(M_PI / 2, 0.001) << endl;
	cout << "cos(0): " << Cos(0, 0.001) << endl;
	cout << "cos(2): "<< Cos(2, 0.001) << endl;
}