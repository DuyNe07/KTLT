#include <iostream>
#include <math.h>
using namespace std;
void input(int &n);
long long tinh(int n);

int main()
{
    int n;
    input(n);
    cout << tinh(n);
    return 0;
}

void input(int &n)
{
    cin >> n;
}

long long tinh(int n)
{
    int tong = 0, temp = 1;
    for (int i = 1; i <= n; i++)
    {
        temp *= i;
        tong += temp;
    }
    return tong;
}