#include <iostream>
#include <cstring>
using namespace std;
struct mathang
{
	char mahang[11];
	char tenhang[51];
	int soluong;
	int dongia;
	int soluongton;
	int thoigian;
};
void nhap(mathang &x)
{
	cout << "nhap ma:" << endl;
	cin.getline(x.mahang, 11);
	cout << "nhap ten hang: " << endl;
	cin.getline(x.tenhang, 51);
	cout << "nhap so luong hang: " << endl;
	cin >> x.soluong;
	cout << "nhap don gia hang: " << endl;
	cin >> x.dongia;
	cout << "nhap so luong ton hang: " << endl;
	cin >> x.soluongton;
	cout << "nhap thoi gian bao hanh: " << endl;
	cin >> x.thoigian;
	cin.ignore();
	cout << endl;
}
void xuat(mathang x)
{
	cout << "===============================================" << endl;
	cout << "Ma: " << x.mahang << endl;
	cout << "Ten: " << x.tenhang << endl;
	cout << "So luong: " << x.soluong << endl;
	cout << "Don gia:" << x.dongia << endl;
	cout << "So luong ton:  " << x.soluongton << endl;
	cout << "Thoi gian bao hanh: " << x.thoigian << endl;
	cout << "================================================" << endl;
}
void nhapmang(mathang x[], int &n)
{
	for (int i = 0; i < n; i++)
	{
		cout << " nhap thong tin hang thu " << i + 1 << " : " << endl;
		nhap(x[i]);
	}
	cout << endl;
}

void xuatmang(mathang x[], int n)
{
	for (int i = 0; i < n; i++)
	{
		xuat(x[i]);
	}
	cout << endl;
}
void soluongtonmax(mathang x[], int n)
{
	int max = x[0].soluongton;
	int vitri = 0;
	for (int i = 0; i < n; i++)
	{
		if (x[i].soluongton > max)
		{
			max = x[i].soluongton;
			vitri = i;
		}
	}
	cout << " mat hang co so luong ton lon nhat la: " << x[vitri].tenhang << endl;
}
void soluongtonmin(mathang x[], int n)
{
	int min = x[0].soluongton;
	int vitri = 0;
	for (int i = 0; i < n; i++)
	{
		if (x[i].soluongton < min)
		{
			min = x[i].soluongton;
			vitri = i;
		}
	}
	cout << " mat hang co so luong ton be nhat la: " << x[vitri].tenhang << endl;
}
void tienmax(mathang x[], int n)
{
	int max = x[0].dongia;
	int vitri = 0;
	for (int i = 0; i < n; i++)
	{
		if (x[i].dongia > max)
		{
			max = x[i].dongia;
			vitri = i;
		}
	}
	cout << " mat hang co gia tien lon nhat la: " << x[vitri].tenhang << endl;
}
void baohanhhon12thang(mathang x[], int n)
{
	cout << " mat hang co thoi gian bao hanh tren 12 thang la " << endl;
	for (int i = 0; i < n; i++)
	{
		if (x[i].thoigian > 12)
		{
			cout << x[i].tenhang << " ";
		}
	}
	cout << endl;
}

void sapxep(mathang x[], int n)
{
	int max = x[0].soluongton;
	int vitri = 0;
	for (int i = 1; i < n; i++)
	{
		for (int j = 0; j < n - 1; j++)
		{
			if (x[i].soluongton < x[j].soluongton)
			{
				swap(x[i].soluongton, x[j].soluongton);
			}
		}
	}
	cout << " mat hang tang dan theo slt la: " << endl;
	for (int i = 0; i < n; i++)
	{
		cout << x[i].tenhang << " ";
	}
	cout << endl;
}

int main()
{
	mathang x[101];
	int n;
	cout << " nhap n" << endl;
	;
	cin >> n;
	cin.ignore();
	nhapmang(x, n);
	xuatmang(x, n);
	soluongtonmax(x, n);
	soluongtonmin(x, n);
	tienmax(x, n);
	sapxep(x, n);
	baohanhhon12thang(x, n);
	return 0;
}
