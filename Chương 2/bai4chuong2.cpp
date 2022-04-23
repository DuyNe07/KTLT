#include <iostream>
using namespace std;
#define Max 20
void Chuyen_thanh_mang_1_chieu(int A[][Max], int m, int n);
void Nhap_mang_2_chieu(int A[][Max], int &m, int &n);
void Xuat(int k);

void main()
{
	int A[Max][Max], m, n;
	Nhap_mang_2_chieu(A, m, n);
	Chuyen_thanh_mang_1_chieu(A, m, n);
}

void Nhap_mang_2_chieu(int A[][Max], int &m, int &n)
{
	cout << "Nhap so dong: ";
	cin >> m;
	cout << "Nhap so cot: ";
	cin >> n;
	for (int i = 0; i < m; i++)
		for (int j = 0; j < n; j++)
			cin >> A[i][j];
}

void Chuyen_thanh_mang_1_chieu(int A[][Max], int m, int n)
{
	for (int i = 0; i < m; i++)
		for (int j = 0; j < n; j++)
			Xuat(A[i][j]);
}

void Xuat(int k)
{
	cout << k << " ";
}
