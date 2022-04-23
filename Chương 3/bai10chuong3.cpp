#include <iostream>
#include <cstring>
#include <vector>
#define MAX 100
using namespace std;

void inra(vector<char> x)
{
    for (int i = 0; i < x.size(); i++)
    {
        cout << x[i] << " ";
    }
    cout << endl;
}

void phanLoai(char *A)
{
    // tao 4 vector thuoc 4 kieu du lieu de them vao ma khong can biet so luong truoc
    vector<char> chuthuong;
    vector<char> chuhoa;
    vector<char> so;
    vector<char> khac;
    for (int i = 0; i <= strlen(A); i++)
    {
        // kiem tra dieu kien cac cac kieu
        if (A[i] >= '0' && A[i] <= '9')
        {
            so.push_back(A[i]);
        }
        else if (A[i] >= 'a' && A[i] <= 'z')
        {
            chuthuong.push_back(A[i]);
        }
        else if (A[i] >= 'A' && A[i] <= 'Z')
        {
            chuhoa.push_back(A[i]);
        }
        else
        {
            khac.push_back(A[i]);
        }
    }
    cout << "Chuoi chu thuong la: ";
    inra(chuthuong);
    cout << "Chuoi chu hoa la: ";
    inra(chuhoa);
    cout << "Chuoi so la: ";
    inra(so);
    cout << "Cac ki tu con lai la: ";
    inra(khac);
}

int main()
{
    char A[MAX];
    cin >> A;
    phanLoai(A);
    return 0;
}