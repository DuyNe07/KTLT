#include <iostream>
#include <math.h>
using namespace std;
void input(float &n);
int output(float n);

int main()
{
    float n;
    input(n);
    cout << output(n);
    return 0;
}

void input(float &n)
{
    cin >> n;
}

int output(float n)
{
    float tong = 1;
    int i = 1;
    while (tong <= n)
    {
        i++;
        tong += (float)1 / i;
    }
    return i;
}