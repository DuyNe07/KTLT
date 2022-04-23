#include <iostream>
#include <string>
using namespace std;

void nhapVao(int &d, int &m, int &y);
bool kiemTraNam(int nam);
void dieuChinhThang(int nam, int ngaythang[]);
bool kiemTra(int d, int m, int ngaythang[]);
void inKetQua(bool ketqua, int d, int m, int y, int ngaythang[]);

int main()
{
	int ngaythang[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	int d, m, y;
	nhapVao(d, m, y);
	dieuChinhThang(y, ngaythang);
	if (kiemTra(d, m, ngaythang) == false)
	{
		inKetQua(false, d, m, y, ngaythang);
	}
	else
	{
		inKetQua(true, d, m, y, ngaythang);
	}
	return 0;
}

void inKetQua(bool ketqua, int d, int m, int y, int ngaythang[])
{
	if (ketqua == false)
	{
		cout << "Ngay thang nam ban khong tao thanh mot ngay thang nam !!!" << endl;
	}
	else
	{
		if (d == ngaythang[m])
		{
			if (m == 12)
			{
				cout << "1/1/" << y + 1 << endl;
			}
			else
			{
				cout << "1/" << m + 1 << "/" << y << endl;
			}
		}
		else
		{
			cout << d + 1 << "/" << m << "/" << y << endl;
		}
	}
}

bool kiemTra(int d, int m, int ngaythang[])
{
	if (m < 0 || m > 12)
	{
		return false;
	}
	else if (d < 0 || d > ngaythang[m])
	{
		return false;
	}
	else
		return true;
}

void dieuChinhThang(int nam, int ngaythang[])
{
	if (kiemTraNam(nam) == true)
	{
		ngaythang[2] = 29;
	}
}

bool kiemTraNam(int nam)
{
	if (nam % 400 == 0 || (nam % 4 == 0 && nam % 100 != 0))
	{
		return true;
	}
	else
		return false;
}

void nhapVao(int &d, int &m, int &y)
{
	cout << "Nhap ngay: ";
	cin >> d;
	cout << "Nhap thang: ";
	cin >> m;
	cout << "Nhap nam: ";
	cin >> y;
}