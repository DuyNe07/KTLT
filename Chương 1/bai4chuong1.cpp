#include <iostream>
using namespace std;

struct thoigian
{
	int ngay;
	int thang;
	int nam;
};

void nhap(thoigian &a)
{
	cout << "nhap ngay thang nam: " << endl;
	cin >> a.ngay >> a.thang >> a.nam;
}

void xuat(thoigian a)
{
	cout << a.ngay << "/" << a.thang << "/" << a.nam << endl;
}

int namNhuan(int i)
{
	if (i % 4 == 0 && i % 100 != 0 || i % 400 == 0)
		return 1;
	return 0;
}

int ngayThang(int i, int y)
{
	if (i == 2)
	{
		if (namNhuan(y))
			return 29;
		else
			return 28;
	}
	else if (i == 1 || i == 3 || i == 5 || i == 7 || i == 8 || i == 10 || i == 12)
		return 31;
	else
		return 30;
}

int dem(thoigian a)
{
	int kc = 0;
	for (int i = 1; i < a.nam; i++)
	{
		if (namNhuan(i))
			kc = kc + 366;
		else
			kc = kc + 365;
	}
	for (int i = 1; i < a.thang; i++)
	{
		kc = kc + ngayThang(i, a.nam);
	}
	kc = kc + a.ngay;
	return kc;
}

thoigian kc(thoigian a, thoigian b)
{
	int kc1 = dem(a);
	int kc2 = dem(b);
	int kc = kc1 - kc2;
	if (kc < 0)
		kc = kc * (-1);
}
int main()
{
	thoigian a, b;
	nhap(a);
	nhap(b);
	xuat(a);
	xuat(b);
	kc(a, b);
}
