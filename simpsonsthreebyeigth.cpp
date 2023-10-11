#include <iostream>
#include <cmath>

using namespace std;

double func(double x)
{
    return x * x;
}

double simpsons_three_eighth_rule(double (*func)(double), double a, double b, int n)
{
    double h = (b - a) / n;
    double integral = func(a) + func(b);

    for (int i = 1; i < n; i++)
    {
        double x = a + i * h;
        if (i % 3 == 0)
        {
            integral += 2 * func(x);
        }
        else
        {
            integral += 3 * func(x);
        }
    }

    integral *= 3 * h / 8.0;
    return integral;
}

int main()
{
    double a = 0.0;
    double b = 2.0;
    int n = 9; // n should be a multiple of 3 for Simpson's 3/8 rule

    double result = simpsons_three_eighth_rule(func, a, b, n);

    cout << "Approximate Integral using Simpson's 3/8 Rule: " << result << endl;

    return 0;
}
