#include <iostream>
#include <cmath>

using namespace std;

double func(double x)
{
    return x * x;
}

double simpsons_one_third_rule(double (*func)(double), double a, double b, int n)
{
    double h = (b - a) / n;
    double integral = func(a) + func(b);

    for (int i = 1; i < n; i++)
    {
        double x = a + i * h;
        if (i % 2 == 0)
        {
            integral += 2 * func(x);
        }
        else
        {
            integral += 4 * func(x);
        }
    }

    integral *= h / 3.0;
    return integral;
}

int main()
{
    double a = 0.0;
    double b = 2.0;
    int n = 10;

    double result = simpsons_one_third_rule(func, a, b, n);

    cout << "Approximate Integral using Simpson's 1/3 Rule: " << result << endl;

    return 0;
}