#include <iostream>
#include <math.h>
using namespace std;

struct hon_so
{
	int phan_nguyen;
	int tu_so;
	int mau_so;
};

struct phan_so
{
	int tu_so;
	int mau_so;
};

int UCLN(int A, int B);
void nhap(hon_so &x);
phan_so honso_pso(hon_so x);
hon_so pso_honso(phan_so x);
hon_so tich(hon_so a, hon_so b);
hon_so tong(hon_so a, hon_so b);
phan_so tong_2pso(phan_so a, phan_so b);
void in(hon_so a, hon_so b);
phan_so rut_gon(phan_so x);

int main()
{
	hon_so a, b;
	cout << "Nhap hon so de chuyen doi: " << endl;
	nhap(a);
	cout << "Nhap hon so thu 1: " << endl;
	nhap(a);
	cout << "Nhap hon so thu 2: " << endl;
	nhap(b);
	in(a, b);
	return 0;
}

void in(hon_so a, hon_so b)
{
	cout << "Tong 2 hon so ban vua nhap la: " << tong(a, b).phan_nguyen << "*(" << tong(a, b).tu_so << "/" << tong(a, b).mau_so << ")" << endl;
	cout << "Tich 2 hon so ban vua nhap la: " << tich(a, b).phan_nguyen << "*(" << tich(a, b).tu_so << "/" << tich(a, b).mau_so << ")" << endl;
}

void nhap(hon_so &x)
{
	cout << "Nhap phan nguyen: ";
	cin >> x.phan_nguyen;
	cout << "Nhap tu so: ";
	cin >> x.tu_so;
	cout << "Nhap mau so: ";
	cin >> x.mau_so;
	// thực hiện rà soát lại việc nhập
	// tránh trường hợp nhập tử só lớn hơn mẫu, tử bằng mẫu ta rút gọn luôn hỗn số khi người dùng nhập từ bàn phím
	while (x.tu_so > x.mau_so)
	{
		x.phan_nguyen += 1;
		x.tu_so -= x.mau_so;
	}
	if (x.mau_so == x.tu_so)
	{
		x.phan_nguyen += 1;
		x.tu_so = 1;
		x.mau_so = 1;
	}
}

phan_so honso_pso(hon_so x) // chuyển hỗn số thành phân số bằng cách quy đồng cộng vào tử số
{
	phan_so ketqua = {x.phan_nguyen * x.mau_so + x.tu_so, x.mau_so};
}

hon_so pso_honso(phan_so x)
{
	hon_so ketqua = {0, x.tu_so, x.mau_so}; // gán tử với mẫu của phân số cho hỗn số
	if (ketqua.tu_so < ketqua.mau_so)		// nếu phân số <1 thì phân nguyên hỗn số = 1
	{
		ketqua.phan_nguyen = 1;
	}
	while (x.tu_so > x.mau_so) // nếu tư > mẫu thì lặp lại vòng lắp cho tới khi nào phần phân số <1 thì thôi
	{
		ketqua.phan_nguyen += 1;	   // thực hiện cộng thêm khi tử > mẫu
		ketqua.tu_so -= ketqua.mau_so; // trừ đi tử số theo mẫu số đến khi nào phần phân số <1
	}
	if (ketqua.tu_so == ketqua.mau_so) // nếu tử bằng mẫu thì phần phân số =1 và cộng thêm phần nguyên 1
	{
		ketqua.phan_nguyen += 1;
		x.tu_so = 1;
		x.mau_so = 1;
	}
}

hon_so tich(hon_so a, hon_so b)
{
	phan_so x;
	x.tu_so = honso_pso(a).tu_so * honso_pso(b).tu_so;
	x.mau_so = honso_pso(a).mau_so * honso_pso(b).mau_so;
	hon_so ketqua = {pso_honso(x).phan_nguyen, pso_honso(x).tu_so, pso_honso(x).mau_so};
	return ketqua;
}

int UCLN(int A, int B)
{ // sử dụng thuật toán Euclid
	if (B == 0)
		return A;
	return UCLN(B, A % B);
}

phan_so rut_gon(phan_so x)
{
	int ucln = UCLN(x.tu_so, x.mau_so);
	x.tu_so = x.tu_so / ucln;
	x.mau_so = x.mau_so / ucln;
	return x;
}

phan_so tong_2pso(phan_so a, phan_so b)
{
	phan_so ketqua;
	if (a.mau_so == b.mau_so)
	{
		ketqua.mau_so;
		ketqua.tu_so = a.tu_so = b.tu_so;
		ketqua = rut_gon(ketqua);
		return ketqua;
	}
	else
	{
		ketqua.mau_so = a.mau_so * b.mau_so;
		ketqua.tu_so = a.tu_so * b.mau_so + a.mau_so * b.tu_so;
		ketqua = rut_gon(ketqua);
		return ketqua;
	}
}

hon_so tong(hon_so a, hon_so b)
{
	phan_so x = tong_2pso(honso_pso(a), honso_pso(b));
	return pso_honso(x);
}