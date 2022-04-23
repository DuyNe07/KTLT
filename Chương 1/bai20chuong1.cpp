#include <fstream>
#include <string>
#include <iostream>
#include <cstdlib>
using namespace std;

int Random(int min, int max)
{
	return min + (int)(rand() * (max - min + 1.0) / (1.0 + RAND_MAX));
}

void xuLiFile(string dir_file, int A[]);
void taoFile(string dir_file, int A[]);

int main()
{
	int A[51];
	string dir_file = "D:/code/KyThuatLapTrinh/IOPUT/SOCHAN.txt";
	taoFile(dir_file, A);
	xuLiFile(dir_file, A);
	return 0;
}

void taoFile(string dir_file, int A[])
{
	ofstream filein(dir_file);
	if (filein.fail())
	{
		cout << "Khong mo duoc file !" << endl;
		return;
	}
	else
	{
		for (int i = 0; i < 50; i++)
		{
			while (true)
			{
				int a = Random(0, 100);
				if (a % 2 == 0)
				{
					filein << a << " ";
					break;
				}
			}
		}
	}
}

void xuLiFile(string dir_file, int A[])
{
	ifstream fileout(dir_file);
	if (fileout.fail())
	{
		cout << "Khong the mo file !" << endl;
		return;
	}
	else
	{
		for (int i = 0; i < 50; i++)
		{
			int a;
			fileout >> a;
			cout << a << " ";
			if (i == 29)
			{
				cout << endl;
			}
		}
	}
}