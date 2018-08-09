#include <iostream>
using namespace std;
void sxchon (float a[], int n){
	int i,j,k;
	float min,t;
	for (i=0; i<n-1; i++){
		min =a[i];
		k=i;
		for (j=i+1; j<n;j++)
		if (a[j]<min){
			k=j;
			min =a[j];
		}
		if (k!=i)  {
			t=a[i];
			a[i]=a[k];
			a[k]=t;
			
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
	sxchon (a,n);
	cout << "\nmang tang la:";
	for (int i=0; i<n;i++){
		cout << a[i]<<" ";
	}
	
}
