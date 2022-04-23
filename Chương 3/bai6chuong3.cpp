#include <iostream>
#include <math.h>
using namespace std;
void input(int &n);
int giaiThua(int n);
double tong(int x, int n);

int main()
{
    int x, n;
    input(x);
    input(n);
    cout << tong(x, n);
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

double tong(int x, int n)
{
    double tong = 1;
    for (int i = 1; i <= n; i++)
    {
        tong += (float)pow(x, i) / giaiThua(i);
    }
    return tong;
}