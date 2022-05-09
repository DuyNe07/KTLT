#include <iostream>
#define SIZE 200

using namespace std;

void nhapMang(int &m, int &n, int arr[][SIZE])
{
    cin >> m >> n;
    for (int hang = 0; hang < m; hang++)
    {
        for (int cot = 0; cot < n; cot++)
        {
            cin >> arr[hang + 2][cot + 2];
        }
    }
}

bool nhoHon(int hang, int cot, int arr[][SIZE])
{

    int x[8] = {-2, -1, -1, 0, 0, 1, 1, 2};
    int y[8] = {0, -1, 1, -2, 2, -1, 1, 0};
    for (int i = 0; i < 8; i++)
    {

        if (arr[hang][cot] >= arr[hang + x[i]][cot + y[i]])
        {
            return false;
        }
    }
    return true;
}

int kiemTra(int m, int n, int arr[][SIZE])
{
    int tong = 0;
    for (int hang = 0; hang < m; hang++)
    {
        for (int cot = 0; cot < n; cot++)
        {
            if (nhoHon(hang + 2, cot + 2, arr) == true)
            {
                tong += arr[hang + 2][cot + 2];
            }
        }
    }
    return tong;
}

int main()
{
    int m;
    int n;
    int arr[200][200] = {200};
    nhapMang(m, n, arr);
    cout << kiemTra(m, n, arr);
    return 0;
}