#include <iostream>
using namespace std;

struct phanso
{
	int tuso;
	int mauso;
};

void nhapPhanSo(phanso &ps)
{
	cout << "Nhap tu so: ";
	cin >> ps.tuso;
	do
	{
		cout << "Nhap mau so:";
		cin >> ps.mauso;
	} while (ps.mauso == 0);
}

void xuatPhanSo(phanso ps)
{
	if (ps.mauso == 1 || ps.tuso == 0)
	{
		cout << ps.tuso;
	}
	else
	{
		cout << ps.tuso << "/" << ps.mauso;
	}
	cout << endl;
}

int UCLN(int A, int B)
{ // sử dụng thuật toán Euclid
	if (B == 0)
	{
		return A;
	}
	return UCLN(B, A % B);
}

void rutGonPhanSo(phanso ps)
{
	int a = UCLN(ps.tuso, ps.mauso);
	ps.mauso /= a;
	ps.tuso /= a;
}

phanso tongPhanSo(phanso ps1, phanso ps2)
{
	phanso ps = {ps1.tuso * ps2.mauso + ps2.tuso * ps1.mauso, ps1.mauso * ps2.mauso};
	rutGonPhanSo(ps);
	return ps;
}

phanso hieuPhanSo(phanso ps1, phanso ps2)
{
	phanso ps = {ps1.tuso * ps2.mauso - ps2.tuso * ps1.mauso, ps1.mauso * ps2.mauso};
	rutGonPhanSo(ps);
	return ps;
}

phanso tichPhanSo(phanso ps1, phanso ps2)
{
	phanso ps = {ps1.tuso * ps2.tuso, ps1.mauso * ps2.mauso};
	rutGonPhanSo(ps);
	return ps;
}

phanso thuongPhanSo(phanso ps1, phanso ps2)
{
	phanso ps = {ps1.tuso * ps2.mauso, ps1.mauso * ps2.tuso};
	rutGonPhanSo(ps);
	return ps;
}

void quiDong(phanso ps1, phanso ps2)
{
	ps1.mauso = ps2.mauso = ps1.mauso * ps2.mauso;
	ps1.tuso *= ps2.mauso;
	ps2.tuso *= ps1.tuso;
}

int soSanh(phanso ps1, phanso ps2)
{
	quiDong(ps1, ps2);
	if (ps1.tuso > ps2.mauso)
	{
		return 1;
	}
	else if (ps1.tuso < ps2.tuso)
	{
		return 2;
	}
	else
		return 0;
}

int main()
{
	phanso ps1, ps2;
	nhapPhanSo(ps1);
	nhapPhanSo(ps2);
	phanso ps;
	ps = tongPhanSo(ps1, ps2);
	cout << "Tong 2 phan so: ";
	xuatPhanSo(ps);
	ps = hieuPhanSo(ps1, ps2);
	cout << "Hieu 2 phan so:";
	xuatPhanSo(ps);
	ps = tichPhanSo(ps1, ps2);
	xuatPhanSo(ps);
	ps = thuongPhanSo(ps1, ps2);
	xuatPhanSo(ps);
	quiDong(ps1, ps2);
	cout << "So sanh phan so: " << soSanh(ps1, ps2) << endl;
}