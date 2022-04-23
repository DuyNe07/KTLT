#include <iostream>
#include <math.h>

void input(int &n);
float tinhS(int n);

int main()
{
    int n;
    input(n);
    std::cout << tinhS(n);
    return 0;
}

void input(int &n)
{
    std::cin >> n;
}

float tinhS(int n)
{
    float tong = 0;
    int temp = 0;
    for (int i = 1; i <= n; i++)
    {
        temp += i;
        tong += (float)1 / temp;
    }
    return tong;
}