#include <iostream>
using namespace std;

long tinhLT(int x, int p)
{
    if (p == 0)
    {
        return 1;
    }
    else
    {
        long z = tinhLT(x, p / 2);
        if (p % 2 == 0)
        {
            return z * z;
        }
        else
        {
            return z * z * x;
        }
    }
}