#include <iostream>

using namespace std;

struct sophuc
{
	int phanthuc, phanao;
};

void main()
{
	int n;
	cout << "Nhap so phan luong ptu: ";
	cin >> n;
	sophuc *sp = new sophuc[n];
	nhapDuLieu(sp, n);
}

void nhapDuLieu(sophuc *sp, int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << "Nhap phan thuc:";
		cin >> sp[i].phanthuc;
		cout << "Nhap phan ao:";
		cin >> sp[i].phanao;
	}
}

sophuc tong(sophuc *sp, int n)
{
	sophuc ketqua = {0, 0};
	for (int i = 0; i < n; i++)
	{
		ketqua.phanthuc += sp[i].phanthuc;
		ketqua.phanao += sp[i].phanao;
	}
	return ketqua;
}

sophuc hieu(sophuc *sp, int n)
{
	sophuc ketqua = {0, 0};
	for (int i = 0; i < n; i++)
	{
		ketqua.phanthuc -= sp[i].phanthuc;
		ketqua.phanao -= sp[i].phanao;
	}
	return ketqua;
}

sophuc hieu(sophuc *sp, int n)
{
	sophuc ketqua = {0, 0};
	for (int i = 0; i < n - 1; i++)
	{
		ketqua.phanthuc = sp[i].phanthuc * sp[i + 1].phanthuc - sp[i].phanao * sp[i + 1].phanao;
		ketqua.phanao = sp[i].phanthuc * sp[i + 1].phanao + sp[i].phanao * sp[i + 1].phanthuc;
	}
	return ketqua;
}