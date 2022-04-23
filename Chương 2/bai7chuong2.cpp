#include <iostream>
#include <string.h>
#define MAX 100
using namespace std;

void xuat(char A[]);
void xoaDau(char A[]);
void xoaGiua(char A[]);
void xoaCuoi(char A[]);
void xoaBo(char A[]);
void vietHoa(char A[]);

int main()
{
    char A[MAX];
    cin.getline(A, MAX);
    xoaBo(A);
    vietHoa(A);
    xuat(A);
    return 0;
}

void xuat(char A[])
{
    for (int i = 0; i < strlen(A); i++)
    {
        cout << A[i];
    }
}

void xoaDau(char A[])
{
    while (A[0] == ' ')
    {
        strcpy(&A[0], &A[1]);
    }
}

void xoaGiua(char A[])
{
    for (int i = 0; i < strlen(A); i++)
    {
        if (A[i] == ' ' && A[i + 1] == ' ')
        {
            strcpy(&A[i], &A[i + 1]);
            i--;
        }
    }
}

void xoaCuoi(char A[])
{
    while (A[strlen(A)] == ' ')
    {
        strcpy(&A[strlen(A) - 1], &A[strlen(A)]);
    }
}

void xoaBo(char A[])
{
    xoaDau(A);
    xoaGiua(A);
    xoaCuoi(A);
}

void vietHoa(char A[])
{
    A[0] = A[0] - 32;
    for (int i = 1; i < strlen(A); i++)
    {
        if (A[i] == ' ')
        {
            A[i + 1] = A[i + 1] - 32;
        }
    }
}