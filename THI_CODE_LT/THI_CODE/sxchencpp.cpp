#include <iostream>
using namespace std;
void sxchen (float a[], int n){
	int i,x;
	float t;
	for (i=1; i<n; i++){
		t=a[i];
		x=i-1;
		while (i>=0 && a[x]>t){
			a[x+1]=a[x];
			x--;
		}
		a[x+1]=t;
	}
}
main (){
	int n;
	float a[100];
	cout <<"Nhap n:";
	cin >>n;
	for (int i=0; i<n; i++){
		cin >> a[i];
	}
	sxchen (a,n);
	cout << "\nmang tang la:";
	for (int i=0; i<n;i++){
		cout << a[i]<<" ";
	}
	
}
