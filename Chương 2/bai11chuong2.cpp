#include <iostream>
using namespace std;
#include <string.h>
void Phep_cong(char A[], int la, char B[], int lb);
void Chuyen_int(char s, int &t);
void Chuyen_char(char &s, int t);
void Phep_tru(char A[], int la, char B[], int lb);

void main()
{
	char A[100000], B[100000];
	cout << "Nhap so thu nhat: ";
	cin.getline(A, 100000);
	cout << "Nhap so thu hai:  ";
	cin.getline(B, 100000);
	int l1 = strlen(A);
	int l2 = strlen(B);
	strrev(A);
	strrev(B);
	if (l1 > l2)
		for (int i = l2; i < l1; i++)
		{
			B[i] = '0';
			B[i + 1] = '\0';
		}
	else if (l1 < l2)
		for (int i = l1; i < l2; i++)
		{
			A[i] = '0';
			A[i + 1] = '\0';
		}
	int la = strlen(A);
	int lb = strlen(B);
	Phep_cong(A, la, B, lb);
	if (l1 > l2)
		Phep_tru(A, la, B, lb);
	else if (l1 < l2)
		Phep_tru(B, lb, A, la);
	else
		for (int o = la - 1; o >= 0; o--)
		{
			if (A[o] > B[o])
			{
				Phep_tru(A, la, B, lb);
				break;
			}
			else if (A[o] < B[o])
			{
				Phep_tru(B, la, A, lb);
				break;
			}
			if (A[0] == B[0])
			{
				cout << 0 << "\n";
				break;
			}
		}
}

void Phep_cong(char A[], int la, char B[], int lb)
{
	char C[100000];
	int i = 0, h, k, t, p;
	while (i < la && i < lb)
	{
		Chuyen_int(A[i], h);
		Chuyen_int(B[i], k);
		if (p == 1)
		{
			t = h + k + 1;
			p = 0;
		}
		else
			t = h + k;
		if (t > 9)
		{
			t -= 10;
			p = 1;
		}
		Chuyen_char(C[i], t);
		i++;
	}
	if (p == 1)
	{
		C[la] = '1';
		C[la + 1] = '\0';
	}
	else
		C[la] = '\0';
	strrev(C);
	cout << C << "\n";
}

void Phep_tru(char A[], int la, char B[], int lb)
{
	char C[100000];
	int i = 0, h, k, t, p;
	while (i < la && i < lb)
	{
		Chuyen_int(A[i], h);
		Chuyen_int(B[i], k);
		if (p == 1)
		{
			t = h - k - 1;
			p = 0;
		}
		else
			t = h - k;
		if (t < 0)
		{
			t += 10;
			p = 1;
		}
		Chuyen_char(C[i], t);
		i++;
	}
	if (C[la - 1] == '0')
		C[la - 1] = '\0';
	else
		C[la] = '\0';
	strrev(C);
	cout << C << "\n";
}

void Chuyen_int(char s, int &t)
{
	t = s - 48;
}

void Chuyen_char(char &s, int t)
{
	s = char(t + 48);
}