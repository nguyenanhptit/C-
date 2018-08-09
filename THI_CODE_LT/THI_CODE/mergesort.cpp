#include <iostream>
using namespace std;
void mergesort(float a[],int N){
	int i,j,k,low1,up1,low2,up2;//Can duoi va tren cua 2 ds con
	int size;
	int *Listtmp=new int[N];
	size=1;//Buoc tron 1: gan size bang 1
	while(size<N){
	low1=0;k=0;
	while(low1+size<N){
		low2=low1+size;
		up1=low2-1;
	//	up2=(low2+size-1<N)? low2+size-1 : N-1;
		if ( (low2+size-1) < N) up2=low2+size-1;
		else up2=N-1;	
	      /*Cho i quet tu low1 den up1, j quet tu low2 den up2. Voi moi i va j
		so sanh va chon phan tu nho hon chuyen sang danh sach tam.*/
	    for(i=low1,j=low2;i<=up1 && j<=up2;k++)
		if(a[i]<=a[j]) Listtmp[k]=a[i++];
		else Listtmp[k]=a[j++];;
	
	      /*Vi so phan tu duoc chon tu 2 ds khong nhu nhau nen co the i hoac
		j se den dich truoc. Trong truong hop nay ta chuyen phan con lai
		cua day chua quet xong sang ds tam*/
	    for(; i <= up1; k++) Listtmp[k] = a[i++];
	    for(; j <= up2; k++) Listtmp[k] = a[j++];
	    low1 = up2+1;
	    } //while(low1+size<N)
	
	     /*Neu so ds con la so le thi khi tron tung cap se con lai ds cuoi
	      cung. Ta phai chuyen danh sach nay sang ds tam*/
	     for(i = low1; k < N; i++) Listtmp[k++] = a[i];
	     for(i = 0; i < N; i++) a[i] = Listtmp[i];
	     size *= 2;//Tang co cua danh sach con len 2 lan.
	}//end of while(size<N)
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
	mergesort (a,n);
	for (int i=0; i<n;i++)
		cout << a[i]<< " ";
}
