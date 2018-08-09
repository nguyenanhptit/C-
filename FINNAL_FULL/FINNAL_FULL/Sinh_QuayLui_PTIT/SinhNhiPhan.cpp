#include<stdio.h>
#include<conio.h>
int B[100],n, Stop;
void KhoiTao(){
	printf(" nhap n= ");
	scanf("%d",&n);
	for(int i=1; i<=n;i++){
		B[i]=0;
	}
}
void Xuat(){
	for(int i=1;i<=n;i++){
		printf(" %2d ",B[i]);
	}
	printf("\n");
}
void SinhKeTiep(){
	int i=n;
	while(i>0 && B[i]==9){
		B[i]=0;
		i--;	
	}
	if(i==0){
		Stop=1;
	}
	else B[i]++;
}
void Sinh(){
	Stop=0;
	while(!Stop){
		Xuat();
		SinhKeTiep();
	}
}
main(){
	KhoiTao();
	Sinh();
}
