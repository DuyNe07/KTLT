#include <iostream>

#define MAX 100
using namespace std;

void nhap(int A[][MAX], int &m, int &n);
void xuat(int A[][MAX], int &m, int &n);
void taoBaiMin(int A[][MAX], int m, int n);
void chuyenDoi(int A[][MAX], int m, int n);

int main()
{
    int A[MAX][MAX] = {0}; // Tạo ra 1 mạng toàn số 0 để tạo viền ngoài
    int m, n;
    nhap(A, m, n);
    taoBaiMin(A, m, n);
    xuat(A, m, n);
    return 0;
}

void chuyenDoi(int A[][MAX], int m, int n)
{
    for (int hang = 1; hang <= m; hang++)
    {
        for (int cot = 1; cot <= n; cot++)
        {
            if (A[hang][cot] == 1)
            {
                A[hang][cot] = 9;
            }
        }
    }
}

void taoBaiMin(int A[][MAX], int m, int n)
{
    int x[8] = {-1, -1, -1, 0, 1, 1, 1, 0};
    int y[8] = {-1, 0, 1, 1, 1, 0, -1, -1};
    chuyenDoi(A, m, n);
    for (int hang = 1; hang <= m; hang++)
    {
        for (int cot = 1; cot <= n; cot++)
        {
            if (A[hang][cot] != 9)
            {
                for (int i = 0; i < 8; i++)
                {
                    if (A[hang + x[i]][cot + y[i]] == 9)
                    {
                        A[hang][cot] += 1;
                    }
                }
            }
        }
    }
}

void nhap(int A[][MAX], int &m, int &n)
{
    cin >> m >> n;
    for (int hang = 1; hang <= m; hang++)
    {
        for (int cot = 1; cot <= n; cot++)
        {
            cin >> A[hang][cot];
        }
    }
}
void xuat(int A[][MAX], int &m, int &n)
{
    for (int hang = 1; hang <= m; hang++)
    {
        for (int cot = 1; cot <= n; cot++)
        {
            cout << A[hang][cot] << " ";
        }
        cout << endl;
    }
}