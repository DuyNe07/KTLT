//Ham chuyen mang 1 chieu co m * n phan tu sang mang 2 chieu co kich thuoc M x N
#include<iostream>
using namespace std;
void Nhap_mang_1_chieu(int A[], int n, int m);
void Chuyen_sang_mang_2_chieu(int A[], int m, int n);

void main()
{
	int A[100], m, n;
	cout << "Nhap m: ";
	cin >> m;
	cout << "Nhap n: ";
	cin >> n;
	Nhap_mang_1_chieu(A, m, n);
	Chuyen_sang_mang_2_chieu(A, m ,n);	
}

void Nhap_mang_1_chieu(int A[], int m, int n)
{
	cout << "Nhap mang 1 chieu co " << m*n << " phan tu:\n" ;
	for (int i=0; i<n*m; i++)
		cin >> A[i];
}

void Chuyen_sang_mang_2_chieu(int A[], int m, int n)
{
	cout << "Mang hai chieu kich thuoc " << m << " x " << n << "\n";
	int h=0;
	for (int j=0; j<m; j++)
	{
		for (int i=0; i<n; i++)
		{
			cout << A[h] << " ";
			h++;
		}
		cout << "\n";
	}
}

	