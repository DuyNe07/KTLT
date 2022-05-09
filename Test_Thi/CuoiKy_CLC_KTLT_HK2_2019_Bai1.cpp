#include <iostream>

using namespace std;

int muN(int n)
{
    if (n % 2 == 0)
    {
        return -1;
    }
    else
        return 1;
}

void Sn(int &tong, int n, int &dem)
{
    for (int i = 1; i <= n; i++)
    {
        dem += i;
        tong += muN(i) * dem;
    }
}

int main()
{
    int n;
    cin >> n;
    int tong = 0;
    int dem = 0;
    Sn(tong, n, dem);
    cout << tong;
    return 0;
}