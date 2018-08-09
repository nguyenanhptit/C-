#include <iostream>
using namespace std;
void sxnoibot (float a[], int n){
	float t;
	for (int i=0; i<n-1;i++)
		for (int j=n-1; j>i;j--){
			if (a[j]> a[j-1]){
				t=a[j];
				a[j]= a[j-1];
				a[j-1]=t;
			}
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
	sxnoibot (a,n);
	cout << "\nmang tang la:";
	for (int i=0; i<n;i++){
		cout << a[i]<<" ";
	}
	
}
