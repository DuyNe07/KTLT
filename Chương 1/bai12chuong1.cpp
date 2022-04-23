#include <iostream>
#include <cstring>
using namespace std;

struct video
{
	char tenphim[101];
	char theloai[51];
	char tendaodien[51];
	char namchinh[51];
	char nuchinh[51];
	int namsanxuat;
	char hangsanxuat[51];
};
void nhap(video &x)
{
	cout << " nhap ten phim: " << endl;
	cin.getline(x.tenphim, 101);
	cout << " nhap the loai: " << endl;
	cin.getline(x.theloai, 51);
	cout << " nhap ten dao dien: " << endl;
	cin.getline(x.tendaodien, 51);
	cout << " nhap ten nam chinh: " << endl;
	cin.getline(x.namchinh, 51);
	cout << " nhap ten nu chinh: " << endl;
	cin.getline(x.nuchinh, 51);

	cout << " nhap nam san xuat" << endl;
	cin >> x.namsanxuat;
	cout << " nhap hang san xuat" << endl;
	cin.ignore();
	cin.getline(x.hangsanxuat, 51);
}

void xuat(video x)
{
	cout << "=======================================" << endl;
	cout << " Ten phim: " << x.tenphim << endl;
	cout << " The loai: " << x.theloai << endl;
	cout << " Dao dien: " << x.tendaodien << endl;
	cout << " Nam chinh:" << x.namchinh << endl;
	cout << " Nu chinh:" << x.nuchinh << endl;
	cout << " Nam san xuat:" << x.namsanxuat << endl;
	cout << " Hang san xuat: " << x.hangsanxuat << endl;
	cout << "========================================" << endl;
}

void nhapdsvideo(video x[], int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << "Nhap phim thu " << i + 1 << ": " << endl;
		nhap(x[i]);
	}
	cout << endl;
}
void xuatdsvideo(video x[], int n)
{
	for (int i = 0; i < n; i++)
	{
		xuat(x[i]);
	}
	cout << endl;
}
void timkiemtheloai(video x[], int n)
{
	video c;
	cout << " nhap the loai can tim: " << endl;
	cin.getline(c.theloai, 51);
	cout << " danh sach ten phim trung the loai la: ";
	for (int i = 0; i < n; i++)
	{
		if (strcmp(x[i].theloai, c.theloai) == 0)
		{
			cout << x[i].tenphim << " ";
		}
	}
	cout << endl;
}
void timkiemdienviennam(video x[], int n)
{
	video c;
	cout << " nhap dien vien can tim:" << endl;
	cin.getline(c.namchinh, 51);
	cout << " danh sach ten phim co nam dien vien dong la:";
	for (int i = 0; i < n; i++)
	{
		if (strcmp(x[i].namchinh, c.namchinh) == 0)
		{
			cout << x[i].tenphim << " ";
		}
	}
	cout << endl;
}
void timkiemdaodien(video x[], int n)
{
	video c;
	cout << " nhap the loai can tim: " << endl;
	cin.getline(c.tendaodien, 51);
	cout << " danh sach ten phim trung the loai la: ";
	for (int i = 0; i < n; i++)
	{
		if (strcmp(x[i].tendaodien, c.tendaodien) == 0)
		{
			cout << x[i].tenphim << " ";
		}
	}
	cout << endl;
}
int main()
{
	video x[101];
	int n;
	cout << " nhap n" << endl;
	cin >> n;
	cin.ignore();
	nhapdsvideo(x, n);
	xuatdsvideo(x, n);
	timkiemtheloai(x, n);
	timkiemdienviennam(x, n);
	timkiemdaodien(x, n);
	return 0;
}
