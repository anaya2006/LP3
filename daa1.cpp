#include <iostream>
using namespace std;

// Non-Recursive Fibonacci
void fibonacci(int n)
{
    int a = 0, b = 1;

    for (int i = 0; i < n; i++)
    {
        cout << a << " ";

        int next = a + b;
        a = b;
        b = next;
    }
}

// Recursive Fibonacci
void fibonacciRecursive(int a, int b, int n)
{
    if (n == 0)
        return;

    cout << a << " ";

    fibonacciRecursive(b, a + b, n - 1);
}

int main()
{
    int n;

    cout << "Enter total numbers to print in fibonacci series:\t";
    cin >> n;

    // Non-Recursive
    cout << "Fibonacci Series (non-recursive):\t";
    fibonacci(n);

    cout << endl;

    // Recursive
    cout << "Fibonacci Series (recursive):\t\t";
    fibonacciRecursive(0, 1, n);

    cout << endl;

    return 0;
}
/*OUTPUT 

C:\Users\HP\OneDrive\Desktop\sem7>g++ daa1.cpp

C:\Users\HP\OneDrive\Desktop\sem7>a.exe
Enter total numbers to print in fibonacci series:       5
Fibonacci Series (non-recursive):       0 1 1 2 3
Fibonacci Series (recursive):           0 1 1 2 3

C:\Users\HP\OneDrive\Desktop\sem7>a.exe
Enter total numbers to print in fibonacci series:       0
Fibonacci Series (non-recursive):
Fibonacci Series (recursive):

C:\Users\HP\OneDrive\Desktop\sem7>a.exe
Enter total numbers to print in fibonacci series:       1
Fibonacci Series (non-recursive):       0
Fibonacci Series (recursive):           0

C:\Users\HP\OneDrive\Desktop\sem7>*/