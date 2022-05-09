#include <iostream>
#include <math.h>

using namespace std;

struct pso
{
    int tuso, mauso;
};

int UCLN(int A, int B)
{
    if (B == 0)
    {
        return A;
    }
    else
        return UCLN(B, A % B);
}

void rutGon(pso &a)
{
    int ucln = UCLN(a.tuso, a.mauso);
    a.tuso /= ucln;
    a.mauso /= ucln;
}

bool lonHon(pso a, pso b)
{
    rutGon(a);
    rutGon(b);
    if ((a.tuso * b.mauso - b.tuso * a.mauso) > 0)
    {
        return true;
    }
    else
        return false;
}

int nhapVaXuLi(pso arr[], int n)
{
    pso min = {1, 100};
    int viTri = -1;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i].tuso >> arr[i].mauso;
        if (lonHon(arr[i], min) == true)
        {
            min.tuso = arr[i].tuso;
            min.mauso = arr[i].mauso;
            viTri = i;
        }
    }
    return viTri;
}

int main()
{
    int n;
    cin >> n;
    pso *arr = new pso[n];
    cout << nhapVaXuLi(arr, n);
    delete[] arr;
    return 0;
}