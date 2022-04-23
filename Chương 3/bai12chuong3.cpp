#include <iostream>
using namespace std;

int S(int n, int &x)
{
    if (n == 1)
    {
        return 1;
    }
    else
    {
        x += n;
        return x + S(n - 1, x);
    }
}