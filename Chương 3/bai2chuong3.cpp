#include <iostream>
using namespace std;

int cau2(int n)
{
    int tong = 0;
    if (n == 1)
    {
        return 1;
    }
    else
    {
        for (int i = 1; i <= n; i++)
        {
            tong += i;
        }
        return tong + cau2(n - 1);
    }
}

int main()
{
    cout << cau2(5) << endl;
    return 0;
}