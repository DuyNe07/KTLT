#include <iostream>
using namespace std;

int tinhFn(int Fn)
{
    if (Fn == 0)
    {
        return 1;
    }
    else if (Fn == 1)
    {
        return 2;
    }
    else if (Fn == 2)
    {
        return 3;
    }
    else
    {
        return tinhFn(Fn - 3) + 2 * tinhFn(Fn - 2) + 3 * tinhFn(Fn - 1);
    }
}

void timn(int n)
{
    for (int i = 0; i <= n; i++)
    {
        if (tinhFn(i) > n)
        {
            cout << i - 1;
            break;
        }
    }
}

int main()
{
    int M;
    cin >> M;
    timn(M);
    return 0;
}