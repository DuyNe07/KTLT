#include <iostream>
#include <iomanip>
#define SIZE 100
int x[8] = {-1, -1, -1, 0, 1, 1, 1, 0};
int y[8] = {-1, 0, 1, 1, 1, 0, -1, -1};
using namespace std;

void taoMang(int &m, int &n, float A[][SIZE])
{
    cin >> m >> n;
    for (int hang = 0; hang < m; hang++)
    {
        for (int cot = 0; cot < n; cot++)
        {
            cin >> A[hang][cot];
        }
    }
}

void tongTemp(float &tong_temp, int hang, int cot, float A[][SIZE])
{

    for (int i = 0; i < 8; i++)
    {
        tong_temp += A[hang + x[i]][cot + y[i]];
    }
}

void tongLonNhat(int m, int n, float A[][SIZE])
{
    float tong = -1;
    float tong_temp = 0;
    for (int hang = 1; hang < m - 1; hang++)
    {
        for (int cot = 1; cot < n - 1; cot++)
        {
            tong_temp = A[hang][cot];
            tongTemp(tong_temp, hang, cot, A);
            if (tong_temp >= tong)
            {
                tong = tong_temp;
            }
        }
    }
    cout << fixed << setprecision(2) << tong;
}

int main()
{
    float A[SIZE][SIZE] = {0};
    int m, n;
    taoMang(m, n, A);
    tongLonNhat(m, n, A);
    return 0;
}