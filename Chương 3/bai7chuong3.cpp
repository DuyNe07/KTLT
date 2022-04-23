#include <iostream>
using namespace std;

int Fibonacci(int n)
{
    if (n == 1 || n == 2)
        return 1;
    return Fibonacci(n - 1) + Fibonacci(n - 2);
}
int nhap()
{
    int n;
    cout << "nhap n:";
    cin >> n;
    return n;
}
int main()
{
    int n = nhap();
    cout << "so Fibonacci thu " << n << " la: " << Fibonacci(n);
    return 0;
}
