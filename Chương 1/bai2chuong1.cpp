/*
- Trước hết ta phải xây dựng hàm nhập và xuất cho 1 phân số.
- Xây dựng hàm tính tổng, hiệu, tích, thương, rút gọn, so sánh và
nghịch đảo cho 2 phân số.
- Sau đó mới xây dựng hàm nhập, xuất, tính tổng, tích cho mảng các
phân số
*/
#include <algorithm>
#include <iostream>
#include <string>
#include <math.h>
using namespace std;

struct phan_so
{
    int tu_so;
    int mau_so;
};

// khai báo các hàm sẽ sử dụng
// hàm UCLN để phục vụ việc rút gọn phân số
int UCLN(int A, int B);
void nhap_phan_so(phan_so &x);
void nhap_mang_phan_so(phan_so arr[], int n);
void xuat_phan_so(phan_so x);
void xuat_pso(int x, int y);
void xuat_mang_phan_so(phan_so arr[], int n);
phan_so rut_gon(phan_so x);
phan_so tinh_tong_2_phan_so(phan_so x, phan_so y);
phan_so tinh_hieu_2_phan_so(phan_so x, phan_so y);
phan_so tinh_tich_2_phan_so(phan_so x, phan_so y);
phan_so tinh_thuong_2_phan_so(phan_so x, phan_so y);
phan_so so_sanh_2_phan_so(phan_so x, phan_so y);
phan_so nghich_dao(phan_so x);
phan_so tim_max(phan_so arr[], int n);
void in_ra_man_hinh(phan_so arr[], int n, int pso1, int pso2);

int main()
{
    int n;
    cout << "Nhap so phan tu: ";
    cin >> n;
    phan_so *arr = new phan_so[n];
    nhap_mang_phan_so(arr, n);
    cout << "Mang phan so ban vua nhap la: \n";
    xuat_mang_phan_so(arr, n);
    cout << "Chon vi tri 2 phan so trong mang de thuc hien tinh toan: " << endl;
    int pso1, pso2;
    cout << "Vi tri phan so 1: ";
    cin >> pso1;
    cout << "Vi tri phan so 2: ";
    cin >> pso2;
    cout << "\n\n-------------------------" << endl;
    in_ra_man_hinh(arr, n, pso1, pso2);
    delete[] arr;
    system("pause");
    return 0;
}

int UCLN(int A, int B)
{ // sử dụng thuật toán Euclid
    if (B == 0)
        return A;
    return UCLN(B, A % B);
}

void in_ra_man_hinh(phan_so arr[], int n, int pso1, int pso2)
{

    cout << "Phan so co gia tri lon nhat trong mang la: " << tim_max(arr, n).tu_so << "/" << tim_max(arr, n).mau_so << endl;
    cout << "Trong 2 phan so ban vua chon thi phan so " << so_sanh_2_phan_so(arr[pso1 - 1], arr[pso2 - 1]).tu_so << "/" << so_sanh_2_phan_so(arr[pso1 - 1], arr[pso2 - 1]).mau_so << " co gia tri lon hon" << endl;
    cout << "Nghich dao cua phan so dau tien la: " << rut_gon(nghich_dao(arr[pso1 - 1])).tu_so << "/" << rut_gon(nghich_dao(arr[pso1 - 1])).mau_so << endl;
    cout << "Nghich dao cua phan so thu 2 la: " << rut_gon(nghich_dao(arr[pso2 - 1])).tu_so << "/" << rut_gon(nghich_dao(arr[pso2 - 1])).mau_so << endl;
    cout << "Tong 2 phan so ban vua chon la: " << rut_gon(tinh_tong_2_phan_so(arr[pso1 - 1], arr[pso2 - 1])).tu_so << "/" << rut_gon(tinh_tong_2_phan_so(arr[pso1 - 1], arr[pso2 - 1])).mau_so << endl;
    cout << "Hieu 2 phan so ban vua chon la: " << rut_gon(tinh_hieu_2_phan_so(arr[pso1 - 1], arr[pso2 - 1])).tu_so << "/" << rut_gon(tinh_hieu_2_phan_so(arr[pso1 - 1], arr[pso2 - 1])).mau_so << endl;
    cout << "Tich 2 phan so ban vua chon la: " << rut_gon(tinh_tich_2_phan_so(arr[pso1 - 1], arr[pso2 - 1])).tu_so << "/" << rut_gon(tinh_tich_2_phan_so(arr[pso1 - 1], arr[pso2 - 1])).mau_so << endl;
    cout << "Thuong 2 phan so ban vua chon la: " << rut_gon(tinh_thuong_2_phan_so(arr[pso1 - 1], arr[pso2 - 1])).tu_so << "/" << rut_gon(tinh_thuong_2_phan_so(arr[pso1 - 1], arr[pso2 - 1])).mau_so << endl;
}

void nhap_phan_so(phan_so &x)
{
    cout << "Nhap tu so: ";
    fflush(stdin);
    cin >> x.tu_so;
    do
    {
        cout << "Nhap mau so: ";
        fflush(stdin);
        cin >> x.mau_so;
    } while (x.mau_so == 0);
}

void nhap_mang_phan_so(phan_so arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << "Nhap phan so thu " << i + 1 << endl;
        nhap_phan_so(arr[i]);
    }
}

void xuat_phan_so(phan_so x)
{
    cout << " " << x.tu_so << "/" << x.mau_so << " " << endl;
}

void xuat_mang_phan_so(phan_so arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << "Phan so thu " << i + 1 << " la: ";
        xuat_phan_so(arr[i]);
    }
}

phan_so rut_gon(phan_so x)
{
    int ucln = UCLN(x.tu_so, x.mau_so);
    x.tu_so = x.tu_so / ucln;
    x.mau_so = x.mau_so / ucln;
    return x;
}

phan_so tinh_tong_2_phan_so(phan_so x, phan_so y)
{
    phan_so ket_qua = {x.tu_so * y.mau_so + y.tu_so * x.mau_so, x.mau_so * y.mau_so};
    ket_qua = rut_gon(ket_qua);
    return ket_qua;
}

phan_so tinh_hieu_2_phan_so(phan_so x, phan_so y)
{
    phan_so ket_qua = {x.tu_so * y.mau_so - y.tu_so * x.mau_so, x.mau_so * y.mau_so};
    ket_qua = rut_gon(ket_qua);
    return ket_qua;
}

phan_so tinh_tich_2_phan_so(phan_so x, phan_so y)
{
    phan_so ket_qua = {x.tu_so * y.tu_so, x.mau_so * y.mau_so};
    ket_qua = rut_gon(ket_qua);
    return ket_qua;
}

phan_so tinh_thuong_2_phan_so(phan_so x, phan_so y)
{
    phan_so ket_qua = {-1, -1};
    if (y.tu_so == 0)
    {
        return ket_qua;
    }
    swap(y.mau_so, y.tu_so);
    ket_qua.tu_so = x.tu_so * y.tu_so;
    ket_qua.mau_so = x.mau_so * y.mau_so;
    ket_qua = rut_gon(ket_qua);
    return ket_qua;
}

phan_so so_sanh_2_phan_so(phan_so x, phan_so y)
{
    phan_so a = rut_gon(x);
    phan_so b = rut_gon(y);
    float m = (float)a.tu_so / a.mau_so;
    float n = (float)b.tu_so / b.mau_so;
    if (m > n)
    {
        return x;
    }
    else
        return y;
}

phan_so nghich_dao(phan_so x)
{
    swap(x.mau_so, x.tu_so);
    return x;
}

phan_so tim_max(phan_so arr[], int n)
{
    phan_so max = {arr[0].tu_so, arr[0].mau_so};
    for (int i = 1; i < n; i++)
    {
        max = so_sanh_2_phan_so(max, arr[i]);
    }
    return max;
}