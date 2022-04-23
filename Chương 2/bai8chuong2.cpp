#include <iostream>
#include <math.h>
#define MAX 100

using namespace std;

struct dulieu
{
	int giatri;
	int Ox;
	int Oy;
};

void nhap(int &m, int &n);
void taoMang(int arr[][MAX], int m, int n);
void xuLyMang(int arr[][MAX], int m, int n, dulieu ketqua[], int &dem, int Ox[], int Oy[]);
bool check(int arr[][MAX], int hang, int cot, int Ox[], int Oy[]);
void inKetQua(dulieu x);
dulieu timMAX(dulieu arr[], int n);

int main()
{
	int m, n;
	nhap(m, n);
	int arr[MAX][MAX] = {0};
	taoMang(arr, m, n);
	int Ox[] = {-1, 1, 0, 0}, Oy[] = {0, 0, -1, 1};
	int dem(0);
	dulieu ketqua[MAX];
	xuLyMang(arr, m, n, ketqua, dem, Ox, Oy);
	dulieu x = timMAX(ketqua, dem);
	inKetQua(x);
	system("pause");
	return 0;
}

void nhap(int &m, int &n)
{
	cout << "Nhap m, n: " << endl;
	cin >> m >> n;
}

void inKetQua(dulieu x)
{
	cout << "vi tri: " << x.Ox - 1 << " " << x.Oy - 1 << endl;
}

dulieu timMAX(dulieu arr[], int n)
{
	dulieu nhonhat = arr[0];
	for (int i = 1; i < n; i++)
	{
		if (arr[i].giatri < nhonhat.giatri)
		{

			nhonhat = arr[i];
		}
	}
	return nhonhat;
}

bool check(int arr[][MAX], int hang, int cot, int Ox[], int Oy[])
{
	int dem(0);
	for (int i = 0; i < 4; i++)
	{
		if (arr[hang][cot] > arr[hang + Ox[i]][cot + Oy[i]])
		{
			dem += 1;
		}
	}
	if (dem == 4)
		return true;
	else
		return false;
}

void xuLyMang(int arr[][MAX], int m, int n, dulieu ketqua[], int &dem, int Ox[], int Oy[])
{
	for (int hang = 1; hang <= m; hang++)
	{
		for (int cot = 1; cot <= m; cot++)
		{
			if (check(arr, hang, cot, Ox, Oy) == true)
			{
				ketqua[dem].giatri = arr[hang][cot];
				ketqua[dem].Ox = hang;
				ketqua[dem].Oy = cot;
				dem += 1;
			}
		}
	}
}

void taoVien(int arr[][MAX], int m, int n)
{
	for (int i = 0; i <= m + 1; i++)
	{
		arr[0][i] = 0;
		arr[n + 1][i] = 0;
	}
	for (int i = 0; i <= n + 1; i++)
	{
		arr[i][0] = 0;
		arr[i][m + 1] = 0;
	}
}

void taoMang(int arr[][MAX], int m, int n)
{
	cout << "Nhap mang: " << endl;
	for (int hang = 1; hang <= m; hang++)
	{
		for (int cot = 1; cot <= n; cot++)
		{
			cin >> arr[hang][cot];
		}
	}
	taoVien(arr, m, n);
}

/*5 7
4 6 2 3 4 9 5
1 2 6 4 8 6 4
3 1 1 3 5 4 6
5 6 4 8 6 3 1
4 5 6 3 2 4 1*/
