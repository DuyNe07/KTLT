#include <iostream>
#include <cstring>
using namespace std;

struct sach
{
	char masosach[11];
	char tensach[31];
	char tacgia[31];
	int soluong;
};

void nhap(sach &x)
{
	cout << " nhap ma so sach: " << endl;
	cin.getline(x.masosach, 11);
	cout << " nhap ten sach:" << endl;
	cin.getline(x.tensach, 31);
	cout << " nhap ten tac gia" << endl;
	cin.getline(x.tacgia, 31);
	cout << " nhap so luong sach" << endl;
	cin >> x.soluong;
	cin.ignore();
	cout << endl;
}

void xuat(sach x)
{
	cout << "===========================================" << endl;
	cout << "Maso sach: " << x.masosach << endl;
	cout << "Tac gia: " << x.tacgia << endl;
	cout << "So luong: " << x.soluong << endl;
	cout << "===========================================" << endl;
}
void nhapmangsach(sach x[], int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << " nhap thong tin sach thu" << i + 1 << " :" << endl;
		nhap(x[i]);
	}
	cout << endl;
}
void xuatmangsach(sach x[], int n)
{
	for (int i = 0; i < n; i++)
	{
		xuat(x[i]);
	}
	cout << endl;
}
void timsach(sach x[], int n)
{
	sach c;
	cout << "ten sach can tim la: " << endl;
	cin.getline(c.tensach, 31);
	int d = 0;
	for (int i = 0; i < n; i++)
	{
		if (strcmp(x[i].tensach, c.tensach) == 0)
		{
			xuat(x[i]);
			d++;
		}
	}
	if (d == 0)
		cout << "Khong tim thay" << endl;
}
void tong(sach x[], int n)
{
	int tong = 0;
	for (int i = 0; i < n; i++)
	{
		tong = tong + x[i].soluong;
	}
	cout << " tong so sach la: " << tong << endl;
}

int main()
{
	sach x[101];
	int n;
	cout << "nhap n: " << endl;
	cin >> n;
	cin.ignore();
	nhapmangsach(x, n);
	xuatmangsach(x, n);
	tong(x, n);
	timsach(x, n);
}
