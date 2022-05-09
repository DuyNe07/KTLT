#include <iostream>

#define SIZE 200
using namespace std;

bool check(int m, int n, int arr[][SIZE])
{
    int x[8] = {-2, -1, -2, -1, 2, 1, 2, 1};
    int y[8] = {-2, -1, 2, 1, -2, -1, 2, 1};
    for (int i = 0; i < 8; i++)
    {
        if (arr[m][n] <= arr[m + x[i]][n + y[i]])
        {
            return false;
        }
    }
    return true;
}

int kiemtra(int m, int n, int arr[][SIZE])
{
    int dem = 0;
    for (int hang = 0; hang < m; hang++)
    {
        for (int cot = 0; cot < n; cot++)
        {
            if (check(hang + 2, cot + 2, arr) == true)
            {
                dem += 1;
            }
        }
    }
    return dem;
}

void nhapMang(int m, int n, int arr[][SIZE])
{
    for (int hang = 0; hang < m; hang++)
    {
        for (int cot = 0; cot < n; cot++)
        {
            cin >> arr[hang + 2][cot + 2];
        }
    }
}

void xuat(int m, int n, int arr[][SIZE])
{
    for (int hang = 0; hang < m + 5; hang++)
    {
        for (int cot = 0; cot < n + 5; cot++)
        {
            cout << arr[hang][cot] << " ";
        }
        cout << endl;
    }
}

int main()
{
    int m, n;
    cin >> m >> n;
    int arr[SIZE][SIZE] = {0};
    nhapMang(m, n, arr);
    xuat(m, n, arr);
    cout << kiemtra(m, n, arr);
    return 0;
}