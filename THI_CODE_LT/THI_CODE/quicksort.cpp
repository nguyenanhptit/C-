#include <iostream>
using namespace std;
void swap (float &x, float &y){
	float t;
	t=x;
	x=y;
	y=t;
}
void partition(float a[],int low,int up,int& pivot)
{
	int pivotval=a[low];//Chon nut dau lam truc
	int i=low;
	int j=up;
	float t;
	while(i<j) //Bat dau quet
	{
		while(a[i]<=pivotval && i<up) i++; //a[i]>pivotval
	    while(a[j]>pivotval)  j--;         //a[j]<=pivotval
	    if(i<j) swap (a[i],a[j]);
	}
	swap(a[low],a[j]);
	pivot=j;
}
void quicksort(float a[],int low,int up)
{
	int pivot;
	if(low>=up) return;
	partition(a,low,up,pivot);
	quicksort(a,low,pivot-1);
	quicksort(a,pivot+1,up);
}
main (){
	int n;
	float a[100];
	cout << "nhap n:";
	cin>> n;
	for (int i=0; i<n; i++){
		cin >> a[i];
	}
	cout << "Mang moi sao xep la: ";
	quicksort (a,0,n-1);
	for (int i=0; i<n; i++)
		cout <<a[i]<<" ";
}
