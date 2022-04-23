#include <fstream>
#include <string>
#include <iostream>
#include <cstdlib>
using namespace std;

void taoFile(string dir_file_in, int A[], int n);
void xuLiFile(string dir_file_out, string dir_file_chan_in, string dir_file_le_in, int n);

int main()
{
	int n;
	cout << "Nhap so phan tu: ";
	cin >> n;
	int A[100];
	string dir_file_out = "D:/code/KyThuatLapTrinh/IOPUT/SONGUYEN.txt";
	string dir_file_chan_in = "D:/code/KyThuatLapTrinh/IOPUT/SOCHAN.txt";
	string dir_file_le_in = "D:/code/KyThuatLapTrinh/IOPUT/SOLE.txt";
	taoFile(dir_file_out, A, n);
	xuLiFile(dir_file_out, dir_file_chan_in, dir_file_le_in, n);
	return 0;
}

void taoFile(string dir_file_in, int A[], int n)
{
	ofstream fileout(dir_file_in);
	if (fileout.fail())
	{
		cout << "Khong mo duoc file !" << endl;
		return;
	}
	else
	{
		for (int i = 0; i < n; i++)
		{
			fileout << rand() << endl;
		}
	}
}

void xuLiFile(string dir_file_out, string dir_file_chan_in, string dir_file_le_in, int n)
{
	ifstream fileout(dir_file_out);
	ofstream chanin(dir_file_chan_in);
	ofstream lein(dir_file_le_in);
	if (fileout.fail() || chanin.fail() || lein.fail())
	{
		cout << "Mo file khong duoc !" << endl;
		return;
	}
	else
	{
		for (int i = 0; i < n; i++)
		{
			int a;
			fileout >> a;
			if (a % 2 == 0)
			{
				chanin << a << endl;
			}
			else
			{
				lein << a << endl;
			}
		}
	}
}