#include <iostream>
#include <math.h>
#include <iomanip>
using namespace std;

int muN(int n)
{
    if (n % 2 == 0)
    {
        return 1;
    }
    else
        return -1;
}

void tinhS(long double &S, int n, long long &giaithua, long long &tuso, double x)
{
    for (int i = 1; i <= n; i++)
    {
        giaithua *= i;
        tuso *= x;
        S += muN(i) * (float)tuso / giaithua;
    }
    cout << fixed << setprecision(2) << S;
}

int main()
{
    int n;
    double x;
    cin >> x >> n;
    long long giaithua = 1;
    long long tuso = 1;
    long double S = 1;
    tinhS(S, n, giaithua, tuso, x);
    return 0;
}