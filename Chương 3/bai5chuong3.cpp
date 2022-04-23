#include <iostream>
#include <math.h>
using namespace std;
void input(int &n);
int giaiThua(int n);
double tinh(int n);

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

int giaiThua(int n)
{
    if (n == 0 || n == 1)
    {
        return 1;
    }
    return n * giaiThua(n - 1);
}

double tinh(int n)
{
    double tong = 0;
    for (int i = 1; i <= n; i++)
    {
        tong += (float)1 / giaiThua(i);
    }
    return tong;
}