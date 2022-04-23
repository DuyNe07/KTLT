#include <iostream>
using namespace std;

void Nhap(int a[], int &n){
	cin >> n;
	for(int i = 0; i < n; i++){
		cin >> a[i];
	}
}

void Check(int a[], int n, int x){
	for(int i = 0; i < n; i++){
		if(a[i] == x){
			cout << i <<" ";
		}
	}
}

int main(){
	int a[1000];
	int n;
	Nhap(a,n);
	int x;
	cin >> x;
	Check(a,n,x);
}


