#include <iostream>
using namespace std;

#define EPSILON 0.001

double func(double x)
{
    return x*x*x - x*x + 2;
}

double root_through_bisection(double x, double y)
{

    if (func(x) * func(y) >= 0)
    {
        cout << "The initial interval does not contain a root." << endl;
        return 0.0;
    }
    
    double middle = x;
    while (y - x >= EPSILON)
    {
        middle = (x + y) / 2;
        if (func(middle) == 0.0)
        {
            return middle;
        }
        else if (func(middle) * func(x) < 0)
        {
            y = middle;
        }
        else
        {
            x = middle;
        }
    }

    return middle;
}

int main()
{
    cout << "root of the given equation is: " << root_through_bisection(-500, 100) << endl;
    return 0;
}