#include <iostream>
#include <cmath>

using namespace std;

double Function(double x)
{
    return (x * x * x) + (x * x) - 4;
}

double secantMethod(double initialGuess1, double initialGuess2, double tolerance, int maxIterations)
{
    double rootApproximation;
    int iterations = 0;

    do
    {
        rootApproximation = initialGuess2 - (Function(initialGuess2) * (initialGuess2 - initialGuess1)) / (Function(initialGuess2) - Function(initialGuess1));
        initialGuess1 = initialGuess2;
        initialGuess2 = rootApproximation;
        iterations++;

        if (iterations >= maxIterations)
        {
            cout << "Maximum iterations reached." << endl;
            break;
        }

    } while (abs(Function(rootApproximation)) > tolerance);

    return rootApproximation;
}

int main()
{
    double initialGuess1, initialGuess2, tolerance, root;
    int maxIterations;

    cout << "Enter initial guess 1: ";
    cin >> initialGuess1;
    cout << "Enter initial guess 2: ";
    cin >> initialGuess2;
    cout << "Enter tolerance (e.g., 1e-6): ";
    cin >> tolerance;
    cout << "Enter maximum iterations: ";
    cin >> maxIterations;

    root = secantMethod(initialGuess1, initialGuess2, tolerance, maxIterations);

    cout << "Approximate root: " << root << endl;

    return 0;
}
