#include <iostream>
using namespace std;
void heapsort(float a[],int N)
 {
	int i,s,f;int x;
	for(i=1;i<N;i++){
		x=a[i];
     	s=i; 
    	while(s>0 && x>a[(s-1)/2]){
			a[s]=a[(s-1)/2]; //Keo nut < x xuong 1 muc
	        s=(s-1)/2;
       }
     	a[s]=x;
	}	
	for(i=N-1;i>0;i--){
		x=a[i];a[i]=a[0];
      	f=0;
      	s=2*f+1; 
        if(s+1<i && a[s]<a[s+1]) s=s+1;
      	while(s<i && x<a[s]){
		    a[f]=a[s];
			f=s;
			s=2*f+1;
			if(s+1<i && a[s]<a[s+1]) s=s+1;
    	}
       	a[f]=x; 
	} 
 }
main (){
	int n;
	float a[100];
	cout << "Nhap n: ";
	cin >> n;
	for (int i=0;i<n; i++){
		cin>>a[i];
	}
	cout << "Mang moi sap xep: ";
	heapsort (a,n);
	for (int i=0; i<n;i++)
		cout << a[i]<< " ";
}
