#include <iostream>
#include <math.h>
using namespace std;

struct so_phuc
{
	int phan_thuc;
	int phan_ao;
};
// 1024751223
//  khai báo hàm
void nhap_so_phuc(so_phuc &x);
so_phuc cong(so_phuc a, so_phuc b);
so_phuc tru(so_phuc a, so_phuc b);
so_phuc tich(so_phuc a, so_phuc b);
void insophuc(so_phuc a);
void in_ra_man_hinh(so_phuc a, so_phuc b)
{
	cout << "Tong 2 so phuc la: ";
	insophuc(cong(a, b));
	cout << "Hieu 2 so phuc la: ";
	insophuc(tru(a, b));
	cout << "Tich 2 so phuc la: ";
	insophuc(tich(a, b));
}

void insophuc(so_phuc a)
{
	cout << a.phan_ao << "+" << a.phan_thuc << "i" << endl;
}
int main()
{
	so_phuc a, b;
	cout << "Nhap so phuc thu nhat': " << endl;
	nhap_so_phuc(a);
	cout << "Nhap so phuc thu hai: " << endl;
	nhap_so_phuc(b);
	in_ra_man_hinh(a, b);
	return 0;
}

void nhap_so_phuc(so_phuc &x)
{
	cout << "Nhap phan thuc: ";
	cin >> x.phan_thuc;
	cout << "Nhap phan ao: ";
	cin >> x.phan_ao;
}

so_phuc cong(so_phuc a, so_phuc b)
{
	so_phuc ket_qua;
	ket_qua.phan_thuc = a.phan_thuc + b.phan_thuc;
	ket_qua.phan_ao = a.phan_ao + b.phan_ao;
	return ket_qua;
}

so_phuc tru(so_phuc a, so_phuc b)
{
	so_phuc ket_qua;
	ket_qua.phan_thuc = a.phan_thuc - b.phan_thuc;
	ket_qua.phan_ao = a.phan_ao - b.phan_ao;
	return ket_qua;
}

so_phuc tich(so_phuc a, so_phuc b)
{
	so_phuc ket_qua;
	ket_qua.phan_thuc = a.phan_thuc * b.phan_thuc - a.phan_ao * b.phan_ao;
	ket_qua.phan_ao = a.phan_thuc * b.phan_ao + a.phan_ao * b.phan_thuc;
	return ket_qua;
}