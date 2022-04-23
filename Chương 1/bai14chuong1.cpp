#include <iostream>
#include <cstring>
using namespace std;
struct maytinh
{
	char loai[31];
	char noisanxuat[31];
	int thoigian;
};

void nhap(maytinh &x)
{
	cout << " nhap loai may tinh " << endl;
	cin.getline(x.loai, 31);
	cout << " nhap noi san xuat " << endl;
	cin.getline(x.noisanxuat, 31);
	cout << " nhap thoi gian bao hanh" << endl;
	cin >> x.thoigian;
	cin.ignore();
	cout << endl;
}

void xuat(maytinh x)
{
	cout << "========================" << endl;
	cout << "Loai may: " << x.loai << endl;
	cout << "Noi san xuat: " << x.noisanxuat << endl;
	cout << "Thoi gian bao hanh: " << x.thoigian << endl;
	cout << "========================" << endl;
}
void nhapmang(maytinh x[], int &n)
{
	for (int i = 0; i < n; i++)
	{
		nhap(x[i]);
	}
	cout << endl;
}
void xuatmang(maytinh x[], int n)
{
	for (int i = 0; i < n; i++)
	{
		xuat(x[i]);
	}
}

void kiemtra(maytinh x[], int n)
{
	int d = 0;
	cout << "So may tinh co bao hanh mot nam la:" << endl;
	for (int i = 0; i < n; i++)
	{
		if (x[i].thoigian == 1)
		{
			d++;
		}
	}
	cout << d << endl;
}

void xuattumy(maytinh x[], int n)
{
	cout << "Cac loai may co xuat xu tu My la: " << endl;
	for (int i = 0; i < n; i++)
	{
		if (strcmp(x[i].noisanxuat, "My") == 0)
		{
			cout << x[i].loai << " ";
		}
	}
}

int main()
{
	maytinh x[101];
	int n;
	cout << "nhap n" << endl;
	cin >> n;
	cin.ignore();
	nhapmang(x, n);
	xuatmang(x, n);
	kiemtra(x, n);
	xuattumy(x, n);
	return 0;
}
