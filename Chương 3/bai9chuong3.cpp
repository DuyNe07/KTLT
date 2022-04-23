#include <iostream>
#include <math.h>

using namespace std;

void input(int &n, int a[]);
void sapXep(int n, int a[]);
void output(int n, int a[]);
void inputX(int &x);
void chenPhanTu(int n, int a[], int x);

int main()
{
    int n, a[100];
    input(n, a);
    sapXep(n, a);
    output(n, a);
    //----------//
    int x;
    inputX(x);
    chenPhanTu(n, a, x);
    return 0;
}

void input(int &n, int a[])
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
}

void sapXep(int n, int a[])
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (a[i] < a[j])
            {
                int temp = a[i];
                a[i] = a[j];
                a[j] = temp;
            }
        }
    }
}

void output(int n, int a[])
{
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
    cout << endl;
}

void inputX(int &x)
{
    cin >> x;
}

void chenPhanTu(int n, int a[], int x)
{
    if (x > a[0])
    {
        for (int i = n; i > 0; i--)
        {
            a[i] = a[i - 1];
        }
        a[0] = x;
        n++;
    }
    else if (x < a[n - 1])
    {
        a[n] = x;
        n++;
    }
    else
    {
        for (int i = 0; i < n - 1; i++)
        {
            if (a[i] >= x && x >= a[i + 1])
            {
                n++;
                for (int j = n; j > i + 1; j--)
                {
                    a[j] = a[j - 1];
                }
                a[i + 1] = x;
                break;
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
}