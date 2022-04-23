#include <iostream>
#include <cmath>
using namespace std;

struct Time
{
	int gio, phut, giay;
};

void NhapTime(Time *t)
{
	cout << "Nhap gio :";
	cin >> t->gio;
	cout << "Nhap phut :";
	cin >> t->phut;
	cout << "Nhap giay :";
	cin >> t->giay;
}
void XuatTime(Time *t)
{
	cout << t->gio << " : " << t->phut << " : " << t->giay << endl;
}
Time *KhoangCach(Time *t1, Time *t2)
{
	Time *kq = new Time;
	int d1, d2, d;
	d1 = t1->gio * 3600 + t1->phut * 60 + t1->giay;
	d2 = t2->gio * 3600 + t2->phut * 60 + t2->giay;
	d = abs(d1 - d2);
	kq->gio = d / 3600;
	int temp = d % 3600;
	kq->phut = temp / 60;
	kq->giay = temp % 60;
	return kq;
	delete kq;
}
void main()
{
	Time *t1 = new Time;
	Time *t2 = new Time;
	NhapTime(t1);
	NhapTime(t2);
	XuatTime(t1);
	XuatTime(t2);
	XuatTime(KhoangCach(t1, t2));
	delete t1, t2;
}