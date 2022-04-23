#include <iostream>
#include <math.h>
#include <iomanip>
using namespace std;

bool tim(int *A, int begin, int end, int x);
void nhap(int *&A, int n);
void in_Ra(bool check);

int main()
{
    int n;
    cin >> n;
    int *A;
    nhap(A, n);
    int x;
    cout << "Nhap x: ";
    cin >> x;
    bool check = tim(A, 0, n - 1, x);
    in_Ra(check);
    delete[] A;
    return 0;
}

bool tim(int *A, int begin, int end, int x)
{
    int mid = begin + (end - begin) / 2;
    if (mid > 1)
    {
        if (A[mid] == x)
        {
            return true;
        }
        if (A[mid] < x)
        {
            return tim(A, mid + 1, end, x);
        }
        else
        {
            return tim(A, begin, mid - 1, x);
        }
    }
    return false;
}

void nhap(int *&A, int n)
{
    A = new int[n];
    cout << "Nhap mang theo thu tu tang dan " << endl;
    for (int i = 0; i < n; i++)
    {
        cout << "Nhap ptu thu " << i + 1 << ":";
        cin >> A[i];
    }
}

void in_Ra(bool check)
{
    if (check == true)
    {
        cout << "Co ne !" << endl;
    }
    else
        cout << "Khong co";
}