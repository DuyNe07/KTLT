/*- Trước hết ta phải xây dựng hàm nhập và xuất cho 1 học sinh.
- Xây dựng hàm nhập và xuất ngày tháng năm (Kiểu dữ liệu DATE).
- Sau đó mới xây dựng hàm nhập và xuất cho danh sách học sinh*/
#include <iostream>
#include <string>
#include <stdio.h>
using namespace std;

struct date
{
    int ngay;
    int thang;
    int nam;
};

struct sinhvien
{
    string MSHS;
    string hoten;
    date ngaysinh;
    string diachi;
    string gioi_tinh;
    float diemtb;
};

// khai báo hàm
void nhapdanhsach(sinhvien danhsach[], int n);
void nhapsinhvien(sinhvien &SV);
void nhap_ngay_thang(date ngaythang);
void nhap_diem(float &diem);
int len_lop(sinhvien danhsach[], int n);

int main()
{
    int n;
    cout << "Nhap so sinh vien: ";
    cin >> n;
    sinhvien HS[50];
    nhapdanhsach(HS, n);
    cout << "So sinh vien du dieu kien len lop la: " << len_lop(HS, n) << endl; // in ra màn hình số học sinh được lên lớp
    system("pause");
    return 0;
    // khai báo hàm
}

void nhapsinhvien(sinhvien &SV)
{
    cout << "Nhap mssv: ";
    getline(cin, SV.MSHS);
    cout << "Nhap ho va ten: ";
    fflush(stdin);
    getline(cin, SV.hoten);
    nhap_ngay_thang(SV.ngaysinh);
    cout << "Nhap gioi tinh: ";
    fflush(stdin);
    getline(cin, SV.gioi_tinh);
    cout << "Nhap diem tb: ";
    fflush(stdin);
    cin >> SV.diemtb;
}

void nhapdanhsach(sinhvien danhsach[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << "Nhap thong tin sinh vien thu " << i + 1 << endl;
        
        nhapsinhvien(danhsach[i]);
        cout << "--------------------------" << endl;
    }
}

int len_lop(sinhvien danhsach[], int n)
{
    int dem(0);
    for (int i = 0; i < n; i++)
    {
        if (danhsach[i].diemtb >= 5)
        {
            dem++;
        }
    }
    return dem;
}

void nhap_ngay_thang(date ngaythang)
{
    cout << "Nhap ngay sinh: ";
    fflush(stdin);
    cin >> ngaythang.ngay;
    cout << "Nhap thang sinh: ";
    fflush(stdin);
    cin >> ngaythang.thang;
    cout << "Nhap nam sinh: ";
    fflush(stdin);
    cin >> ngaythang.nam;
    fflush(stdin);
}