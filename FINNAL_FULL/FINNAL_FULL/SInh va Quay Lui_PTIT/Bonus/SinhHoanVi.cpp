#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
int P[100], n, count, Stop;

 void KhoiTao(){
	int i;count =0;
	printf("\n Nhap n= ");scanf("%d", &n);
	for(i=1; i<=n; i++)
		P[i]=i;
}
void Xuat(){
	int i;count++;
	for(i=1; i<=n;i++)
		printf("%3d",P[i]);
	printf("\n");
}
void SinhKeTiep(){
	int j, k, r, s, temp;
	j = n-1;
	while(j>0 && P[j]>P[j+1])
		j--;
	if(j==0)
		Stop=1;
	else {
		k=n;
		while(P[j]>P[k]) k--;
		temp = P[j]; P[j]=P[k]; P[k]=temp;
		r=j+1; s=n;
		while(r<s){
			temp=P[r];P[r]=P[s]; P[s]=temp;
			r++; s--;
		}
	}
}
void SinhHoanVi(){
	Stop = 0;
	while (!Stop){
		Xuat();
		SinhKeTiep();
	}
}
main(){
		KhoiTao();
		SinhHoanVi();
}
