#include <iostream>
using namespace std;

struct Data
{
    double x, y; // represent a pair of corresponding x and y values
};

double interpolate(Data f[], int xi, int n)
{
    double result = 0; // Initialize result

    for (int i = 0; i < n; i++)
    {
        double term = f[i].y;
        for (int j = 0; j < n; j++)
        {
            if (j != i)
                term = term * (xi - f[j].x) / double(f[i].x - f[j].x);
        }
        result += term;
    }

    return result;
}

int main()
{
    Data f[] = {{150, 12.247}, {152, 12.239}, {154, 12.410}, {156, 12.490}};

    cout << "Value of f(3) is : " << interpolate(f, 155, 4);

    return 0;
}
