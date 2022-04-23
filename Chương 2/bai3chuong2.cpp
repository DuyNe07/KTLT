#include <iostream>
using namespace std;

// 0 1 2 3 4 5 6 7 i
// 1 2 3 5 6 7 8 x
// 1 2 3 4 5 6 7 8 n

void them_Mot_Ptu(int arr[], int n, int vi_tri_them, int gia_tri_them)
{
    n++; // 8
    for (int i = n - 1; i >= vi_tri_them; i--)
    {
        arr[i + 1] = arr[i];
    }
    arr[vi_tri_them] = gia_tri_them;
}

void xoa_Mot_Ptu(int arr[], int n, int vi_tri_xoa)
{
    for (int i = vi_tri_xoa; i < n - 1; i++)
    {
        arr[i] = arr[i + 1];
    }
    n--;
}

void sua_Mot_Ptu(int arr[], int n, int vi_tri_can_xoa, int gia_tri)
{
    arr[vi_tri_can_xoa] = gia_tri;
}

bool tiem_Kiem(int arr[], int n, int gia_tri)
{
    int i = 0;
    arr[n] = gia_tri;
    while (arr[i] != gia_tri)
    {
        i++;
    }
    if (i < n)
    {
        return true;
    }
    else
        return false;
}