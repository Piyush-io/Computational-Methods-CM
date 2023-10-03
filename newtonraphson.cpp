#include <iostream>
using namespace std;

#define EPSILON 0.001

double func(double x)
{
    return x * x * x - x * x + 2;
}

double derivate_func(double x)
{
    return 3 * x * x - 2 * x;
}

double NewtonRaphson(double a)
{
    double h = func(a) / derivate_func(a);
    while (abs(h) >= EPSILON)
    {
        h = func(a) / derivate_func(a);
        a = a - h;
    }

    return a;
}

int main()
{
    cout << "root of the given equation is: " << NewtonRaphson(-4) << endl;
    return 0;
}