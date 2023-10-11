#include <iostream>

using namespace std;

double func(double x)
{
    return x * x;
}

double trapezoidal_rule(double (*func)(double), double a, double b, int n)
{
    double h = (b - a) / n;
    double integral = (func(a) + func(b)) / 2.0;

    for (int i = 1; i < n; i++)
    {
        double x = a + i * h;
        integral += func(x);
    }

    integral *= h;
    return integral;
}

int main()
{
    double a = 0.0;
    double b = 2.0;
    int n = 100;

    double result = trapezoidal_rule(func, a, b, n);

    cout << "Approximate Integral: " << result << endl;

    return 0;
}
