#include<iostream>
#include<conio.h>
using namespace std;
void swap(float &x, float &y){
	int temp = x; x=y; y=temp;
}

void Nhap(float a[], int &n){
	cout<<" \n so phan tu can nhap: ";
	cin>> n;
	for(int i=0; i<n; i++){
		cout<<"\n a["<<i<<"]= ";
		cin>>a[i];
	}
}
void Xem(float a[], int n){
	cout<<"\n cac phan tu trong danh sach: ";
	for(int i=0; i<n; i++){
		cout<<"  "<<a[i];
	}
}
void SelectionSort(float a[], int n){
	for(int i=0; i< n-1; i++){
		for(int j=i+1;j<n;j++){
			if(a[i]>a[j]) swap(a[i],a[j]);
		}
	
	Xem(a,n);
	}
}
void InsertionSort(float a[], int n){
	int i,j, temp;	
	for(i=1; i<n;i++){
		temp = a[i];
		for(j=i-1; j>=0 && temp < a[j]; j--){
			a[j+1]=a[j];
		}
		a[j+1]= temp;
		Xem(a,n);
	}
}
void BubbleSort(float a[], int n){
	for(int i=1; i<n; i++){
		for(int j=n-1; j>=i ; j--){
			if(a[j-1]>a[j]) swap(a[j-1],a[j]);
		}
		Xem(a,n);
	}
}
void partition(float a[],int low,int up,int& pivot)
 {int pivotval=a[low];
  int i=low;
  int j=up;
  while(i<j) 
   {while(a[i]<=pivotval && i<up) i++; 
    while(a[j]>pivotval)  j--;         
    if(i<j) swap(a[i],a[j]); 
    swap(a[low],a[j]);pivot=j;
    };
}
void quicksort(float a[],int low,int up)
 {
 	int pivot;
  if(low>=up) return;
  partition(a,low,up,pivot);
  quicksort(a,low,pivot-1);
  quicksort(a,pivot+1,up);
  }
void heapsort(float a[],int N){
  int i,s,f;int x;
  for(i=1;i<N;i++)
   {x=a[i];
     s=i;     
     while(s>0 && x>a[(s-1)/2])
      {a[s]=a[(s-1)/2]; 
       s=(s-1)/2;
      };
     a[s]=x; 
    }; 

    for(i=N-1;i>0;i--)
     {x=a[i];a[i]=a[0];
    
      f=0; 
      s=2*f+1; 
      if(s+1<i && a[s]<a[s+1]) s=s+1;
      while(s<i && x<a[s])
       {a[f]=a[s];
	f=s;
	s=2*f+1;
	if(s+1<i && a[s]<a[s+1]) s=s+1;
       };
       a[f]=x; 
     }; 
 };
 void mergesort(float a[],int N)
 {
 	int i,j,k,low1,up1,low2,up2;
  	int size;
  	int *Listtmp=new int[N];
  	size=1;
  	while(size<N)
	  {low1=0;k=0;

    while(low1+size<N)
     {low2=low1+size;
      up1=low2-1;
      up2=(low2+size-1<N)? low2+size-1 : N-1;
      
      for(i=low1,j=low2;i<=up1 && j<=up2;k++)
	if(a[i]<=a[j]) Listtmp[k]=a[i++];
	 else Listtmp[k]=a[j++];;

      for(; i <= up1; k++) Listtmp[k] = a[i++];
      for(; j <= up2; k++) Listtmp[k] = a[j++];
      low1 = up2+1;
     } 
     for(i = low1; k < N; i++) Listtmp[k++] = a[i];
     for(i = 0; i < N; i++) a[i] = Listtmp[i];
     size *= 2;
   }
}
main(){
	float a[100];
	int n;
	char c;
	while(1){
		
		cout<<"\n 0. Thoat";
		cout<<"\n 1. Nhap";
		cout<<"\n 2. Xem";
		cout<<"\n 3. SelectionSort";
		cout<<"\n 4. InsertionSort";
		cout<<"\n 5. BubbleSort";
		c=getch();

		if(c=='0') break;
		if(c=='1') Nhap(a,n);
		if(c=='2') Xem(a,n);
		if(c=='3') SelectionSort(a,n);
		if(c=='4') InsertionSort(a,n);
		if(c=='5') BubbleSort(a,n);
		
		
		
		
		
	}
}
