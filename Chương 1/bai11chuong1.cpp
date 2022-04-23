#include <iostream>
#include <string>
#include <math.h>

using namespace std;

struct DIEM
{
	float toan;
	float ly;
	float hoa;
	double diemtb;
};
typedef struct DIEM diem;

struct SINHVIEN
{
	char mssv[100];
	char ten[100];
	int nam;
	diem diemso;
};
typedef struct SINHVIEN sinhvien;
void Nhap_danh_sach_sinh_vien(sinhvien x[], int n);
void Nhap_diem(diem &x);
void Xuat_diem(diem x);
void Xuat_danh_sach_sinh_vien(sinhvien x[], int n);
void Sinh_vien_co_diem_TB_cao_nhat(sinhvien x[], int n);
void Xuat_thong_tin_mot_sinh_vien(sinhvien x);
void Sap_xep_tang_dan_theo_diem_TB(sinhvien x[], int n);
void Sap_xep_giam_dan_theo_diem_Toan(sinhvien x[], int n);
void In_cac_sinh_vien_co_diem_TB_tren_5_va_khong_co_mon_duoi_3(sinhvien x[], int n);
void Sinh_vien_gia_nhat(sinhvien x[], int n);
void Tim_thong_tin_qua_ten(sinhvien x[], int n);

void main()
{
	sinhvien x[100];
	int n;
	cout << "Nhap so luong: ";
	cin >> n;
	Nhap_danh_sach_sinh_vien(x, n);
	Xuat_danh_sach_sinh_vien(x, n);
	Sinh_vien_co_diem_TB_cao_nhat(x, n);
	Sap_xep_tang_dan_theo_diem_TB(x, n);
	Sap_xep_giam_dan_theo_diem_Toan(x, n);
	In_cac_sinh_vien_co_diem_TB_tren_5_va_khong_co_mon_duoi_3(x, n);
	Sinh_vien_gia_nhat(x, n);
	Tim_thong_tin_qua_ten(x, n);
}

void Nhap_danh_sach_sinh_vien(sinhvien x[], int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << "\nNhap thong tin sinh vien thu " << i + 1 << ": ";

		cin.ignore();
		cout << "\nNhap ma so sinh vien: ";
		cin.getline(x[i].mssv, 100);

		cout << "Nhap ten sinh vien: ";
		cin.getline(x[i].ten, 100);

		cout << "Nhap nam sinh: ";
		cin >> x[i].nam;

		cout << "Nhap diem so: ";
		Nhap_diem(x[i].diemso);
	}
}

void Nhap_diem(diem &x)
{
	cout << "\nNhap diem Toan: ";
	cin >> x.toan;

	cout << "Nhap diem Ly: ";
	cin >> x.ly;

	cout << "Nhap diem Hoa: ";
	cin >> x.hoa;

	x.diemtb = (double)(x.toan + x.ly + x.hoa) / 3.0;
}

void Xuat_diem(diem x)
{
	cout << "\nDiem Toan: " << x.toan;

	cout << "\nDiem Ly: " << x.ly;

	cout << "\nDiem Hoa: " << x.hoa;

	cout << "\nDiem trung binh: " << x.diemtb;
}

void Xuat_danh_sach_sinh_vien(sinhvien x[], int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << "\n\nThong tin sinh vien thu " << i + 1 << ": ";

		Xuat_thong_tin_mot_sinh_vien(x[i]);
	}
}

void Xuat_thong_tin_mot_sinh_vien(sinhvien x)
{
	cout << "\nMa so sinh vien: " << x.mssv;

	cout << "\nTen sinh vien: " << x.ten;

	cout << "\nNam sinh: " << x.nam;

	cout << "\nDiem so: ";
	Xuat_diem(x.diemso);
}

void Sinh_vien_co_diem_TB_cao_nhat(sinhvien x[], int n)
{
	double max = x[0].diemso.diemtb;
	int k = 0;
	for (int i = 0; i < n; i++)
	{
		if (x[i].diemso.diemtb > max)
		{
			max = x[i].diemso.diemtb;
			k = i;
		}
	}
	cout << "\n\nSinh vien co diem trung binh cao nhat: " << x[k].ten;
}

void Hoan_doi(sinhvien &x, sinhvien &y)
{
	sinhvien T = x;
	x = y;
	y = T;
}

void Sap_xep_tang_dan_theo_diem_TB(sinhvien x[], int n)
{
	cout << "\n\nSap xep thong tin sinh vien theo thu tu tang dan cua diem TB: ";
	for (int i = 0; i < n; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			if (x[i].diemso.diemtb > x[j].diemso.diemtb)
				Hoan_doi(x[i], x[j]);
		}
		Xuat_thong_tin_mot_sinh_vien(x[i]);
	}
}

void Sap_xep_giam_dan_theo_diem_Toan(sinhvien x[], int n)
{
	cout << "\n\nSap xep thong tin sinh vien theo thu tu giam dan cua diem Toan: ";
	for (int i = 0; i < n; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			if (x[i].diemso.toan < x[j].diemso.toan)
				Hoan_doi(x[i], x[j]);
		}
		Xuat_thong_tin_mot_sinh_vien(x[i]);
	}
}

void In_cac_sinh_vien_co_diem_TB_tren_5_va_khong_co_mon_duoi_3(sinhvien x[], int n)
{
	cout << "\n\nSinh vien co diem TB tren 5 va khong co mon duoi 3: ";
	for (int i = 0; i < n; i++)
	{
		if (x[i].diemso.diemtb > 5 && x[i].diemso.toan >= 3 && x[i].diemso.ly >= 3 && x[i].diemso.hoa >= 3)
			cout << x[i].ten << " ";
	}
}

void Sinh_vien_gia_nhat(sinhvien x[], int n)
{
	int min = x[0].nam;
	cout << "\n\nSinh vien lon tuoi nhat: ";
	for (int i = 0; i < n; i++)
	{
		if (x[i].nam < min)
			min = x[i].nam;
	}
	for (int j = 0; j < n; j++)
		if (x[j].nam == min)
			cout << x[j].ten;
}

void Tim_thong_tin_qua_ten(sinhvien x[], int n)
{
	char t[100];
	cout << "NHAP TEN SINH VIEN CAN TIM: ";
	cin.getline(t, 100);
	cin.ignore();
	for (int i = 0; i < n; i++)
	{
		if (x[i].ten == t)
			Xuat_thong_tin_mot_sinh_vien(x[i]);
	}
}