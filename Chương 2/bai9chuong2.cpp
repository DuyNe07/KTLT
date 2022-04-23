#include <iostream>
#include <string.h>
using namespace std;

void Nhap(int &n)
{
	cin >> n;
}

void chuyensanghenhiphan(int a[], int n)
{
	cout << "he nhi phan: ";
	int i;
	for (i = 0; n > 0; i++)
	{
		a[i] = n % 2;
		n = n / 2;
	}
	for (int j = i - 1; j >= 0; j--)
	{
		cout << a[j];
	}
	cout << endl;
}
void chuyensanghethapluc(char a[], int n)
{
	cout << "he thap luc phan: ";
	int i = 0;
	while (n > 0)
	{
		int x = n % 16;
		n = n / 16;
		if (x < 0)
		{
			a[i] = x + '0';
		}
		else
		{
			a[i] = x - 10 + 'A';
		}
		i++;
	}
	a[i] = '\0';
	strrev(a);
	cout << a << endl;
}

void chuyensanghebatphan(int a[], int n)
{
	cout << "he bat phan: ";
	int i;
	for (i = 0; n > 0; i++)
	{
		a[i] = n % 8;
		n = n / 8;
	}
	for (int j = i - 1; j >= 0; j--)
	{
		cout << a[j];
	}
	cout << endl;
}

int main()
{
	int a[100];
	char b[100];
	int n;
	Nhap(n);
	chuyensanghenhiphan(a, n);
	chuyensanghebatphan(a, n);
	chuyensanghethapluc(b, n);
}
