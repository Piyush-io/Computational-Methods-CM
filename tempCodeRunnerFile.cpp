#include <iostream>
using namespace std;

int fibonacci(int N)
{
    if (N == 1 || N == 0)
    {
        cout << "Fib is " << 1 << endl;
        return 1;
    }

    int a = 1;
    int b = 1;
    int c;

    for (int i = 2; i <= N; i++)
    {
        c = a + b;
        a = b;
        b = c;
    }

    cout << "Fib is " << b << endl;

    return b;
}

int function_value(int x)
{
    return (x * x) + (54 / x);
}

int fibonacci_search(int interval_start, int interval_end, int n)
{
    int L = interval_end - interval_start;
    int k = 2;
    int result;

    while (k <= n)
    {
        int Delta = (fibonacci(n - k + 1) * L) / (fibonacci(n + 1));
        cout << "Delta is : " << Delta << endl;
        int x1 = interval_start + Delta;
        int x2 = interval_end - Delta;
        if (function_value(x1) > function_value(x2))
        {
            interval_start = x1;
            result = x2;
            L = interval_end - interval_start;
        }
        else if (function_value(x1) < function_value(x2))
        {
            interval_end = x2;
            result = x1;
            L = interval_end - interval_start;
        }

        k++;
    }

    return result;
}

int main()
{
    int interval_start;
    int interval_end;
    int n;
    cout << "\nEnter Interval start: ";
    cin >> interval_start;
    cout << "\nEnter Interval end: ";
    cin >> interval_end;
    cout << "\nEnter number of iterations: ";
    cin >> n;

    int result = fibonacci_search(interval_start, interval_end, n);

    cout << "The result of the Fibonacci search: " << result << endl;

    return 0;
}