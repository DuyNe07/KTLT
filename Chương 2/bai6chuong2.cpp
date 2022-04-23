#include <iostream>
using namespace std;

void ghepChuoi(int A[], int B[], int C[], int a, int b, int &c)
{
    c = 0;
    int i = 0;
    while (true)
    {
        if (i < a)
        {
            C[c++] = A[i++];
        }
        if (i <= b)// vì i++ nên dùng điều kiện i < b có thể bị sót số cuối cung của b, thay vào đó dùng <= và ở dưới ta để --i
        {
            C[c++] = B[--i];
            i++;
        }
        if ((i == a && a > b) || (i == b && b > a))
        {
            break;
        }
    }
}

int main()
{
    int A[] = {1, 2, 3, 4};
    int B[] = {5, 6};
    int C[100];
    int c = 0;
    ghepChuoi(A, B, C, 4, 2, c);
    for (int i = 0; i < c; i++)
    {
        cout << C[i] << " ";
    }
    return 0;
}