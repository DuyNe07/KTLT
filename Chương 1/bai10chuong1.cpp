#include <iostream>
#include <math.h>
using namespace std;

struct PHANSO
{
	int ts;
	int ms;
};

int UCLN(int a, int b)
{
	if (b == 0)
	{
		return a;
	}
	return UCLN(b, a % b);
}

void NHAP1PS(PHANSO &a)
{
	cin >> a.ts;
	cin >> a.ms;
}

void XUAT1PS(PHANSO x)
{
	if (x.ms == 1)
		cout << x.ts << endl;
	else if (x.ms == x.ts)
		cout << 1 << endl;
	else
		cout << x.ts << "/" << x.ms << endl;
}

PHANSO RUTGON(PHANSO &a)
{
	PHANSO c;
	int tmp = UCLN(abs(a.ts), abs(a.ms));
	c.ts = a.ts / tmp;
	c.ms = a.ms / tmp;
	if (c.ts < 0 && c.ms < 0)
	{
		c.ts = c.ts * (-1);
		c.ms = c.ms * (-1);
	}
	return c;
}
PHANSO HIEU(PHANSO &a, PHANSO &b)
{
	PHANSO c;
	c.ts = a.ts * b.ms - b.ts * a.ms;
	c.ms = a.ms * b.ms;
	return RUTGON(c);
}
PHANSO TONG(PHANSO &a, PHANSO &b)
{
	PHANSO c;
	c.ts = a.ts * b.ms + b.ts * a.ms;
	c.ms = a.ms * b.ms;
	return RUTGON(c);
}

PHANSO MIN(PHANSO &a, PHANSO &b)
{
	PHANSO tmp = HIEU(a, b);
	if ((float)tmp.ts / (float)tmp.ms <= 0)
		return a;
	else
		return b;
}

PHANSO MAX(PHANSO &a, PHANSO &b)
{
	PHANSO tmp = HIEU(a, b);
	if ((float)tmp.ts / (float)tmp.ms >= 0)
		return a;
	else
		return b;
}

void NHAPMANG(PHANSO a[], int n)
{
	for (int i = 0; i < n; i++)
	{
		NHAP1PS(a[i]);
	}
}

void XUATMANG(PHANSO a[], int n)
{
	for (int i = 0; i < n; i++)
	{
		XUAT1PS(a[i]);
	}
}

PHANSO TONGMANG(PHANSO a[], int n)
{
	PHANSO s;
	s.ts = a[0].ts;
	s.ms = a[0].ms;
	for (int i = 1; i < n; i++)
	{
		s = TONG(s, a[i]);
	}
	return RUTGON(s);
}

PHANSO MAXMANG(PHANSO a[], int n)
{
	PHANSO c;
	c.ts = a[0].ts;
	c.ms = a[0].ms;
	for (int i = 1; i < n; i++)
	{
		c = MAX(c, a[i]);
	}
	return c;
}
void sapxep(PHANSO a[], int n)
{
	PHANSO c;
	for (int i = 1; i < n; i++)
	{
		for (int j = 0; j < n - 1; j++)
		{
			c = MAX(a[i], a[j]);
			if (c.ts == a[j].ts && c.ms == a[j].ms)
			{
				swap(a[i], a[j]);
			}
		}
	}
	cout << "sap xep tang dan:" << endl;
	XUATMANG(a, n);
}

PHANSO MINMANG(PHANSO a[], int n)
{
	PHANSO c;
	c.ts = a[0].ts;
	c.ms = a[0].ms;
	for (int i = 1; i < n; i++)
	{
		c = MIN(c, a[i]);
	}
	return c;
}

int main()
{
	PHANSO a[51], max, min;
	PHANSO c, d, e, f;
	int n;
	cin >> n;
	NHAPMANG(a, n);
	c = TONGMANG(a, n);
	XUAT1PS(c);
	max = MAXMANG(a, n);
	cout << "Max cua mang la:";
	XUAT1PS(max);
	min = MINMANG(a, n);
	cout << "Min cua mang la:";
	XUAT1PS(min);
	sapxep(a, n);
	return 0;
}
