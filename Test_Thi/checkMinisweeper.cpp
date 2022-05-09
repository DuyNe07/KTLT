#include <iostream>

#define SIZE 100

using namespace std;

void nhap(int &m, int &n, int arr[][SIZE])
{
    cin >> m >> n;
    for (int hang = 1; hang <= m; hang++)
    {
        for (int cot = 1; cot <= n; cot++)
        {
            cin >> arr[hang][cot];
        }
    }
}

int quetMin(int arr[][SIZE], int a, int b)
{
    int dem = 0;
    int x[8] = {-1, -1, -1, 0, 1, 1, 1, 0};
    int y[8] = {-1, 0, 1, 1, 1, 0, -1, -1};
    for (int i = 0; i < 8; i++)
    {
        if (arr[a + x[i]][b + y[i]] == 9)
        {
            dem += 1;
        }
    }
    return dem;
}

int kiemTra(int m, int n, int arr[][SIZE])
{
    int dem = 0;
    for (int hang = 1; hang <= m; hang++)
    {
        for (int cot = 1; cot <= n; cot++)
        {
            if (arr[hang][cot] != 9)
            {
                if  (quetMin(arr, hang, cot) != arr[hang][cot])
                {
                    dem += 1;
                }
            }
        }
    }
    return dem;
}

int main()
{
    int m, n;
    int arr[SIZE][SIZE] = {0};
    nhap(m, n, arr);
    cout << kiemTra(m, n, arr);
    return 0;
}