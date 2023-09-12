#include <iostream>
#include <cmath>

using namespace std;

// Define the function for which you want to find the root
double targetFunction(double x) {
    return x * x - 4;
}

// Secant method to find the root
double secantMethod(double initialGuess1, double initialGuess2, double tolerance, int maxIterations) {
    double rootApproximation;
    int iterations = 0;

    do {
        rootApproximation = initialGuess2 - (targetFunction(initialGuess2) * (initialGuess2 - initialGuess1)) / (targetFunction(initialGuess2) - targetFunction(initialGuess1));
        initialGuess1 = initialGuess2;
        initialGuess2 = rootApproximation;
        iterations++;

        if (iterations >= maxIterations) {
            cout << "Maximum iterations reached." << endl;
            break;
        }

    } while (abs(targetFunction(rootApproximation)) > tolerance);

    return rootApproximation;
}

int main() {
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