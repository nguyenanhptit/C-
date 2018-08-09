#include <stdio.h>
#include <conio.h>
#define TRUE 1
#define FALSE 0
int n, k, C[100], Stop;
void KhoiTao(){
	int i;
	printf("\n Nhap n= "); scanf("%d", &n);
	printf("\n Nhap k= "); scanf("%d", &k);
	for(i=1; i<=k; i++)
		C[i]=i;
}
void Xuat(){

	for(int i=1; i<=k; i++)
		printf("%2d", C[i]);
	printf("\n");
}
void SinhKeTiep(){
	int i,j;
	i = k;
	while(i>0 && C[i]==n-k+i)
		i--;
	if(i>0) {
		C[i]= C[i]+1;
		for(j=i+1; j<=k; j++)
			C[j]=C[i]+j-i;
	}
	else Stop = TRUE;
}
void Sinh(){
	Stop=FALSE;
	while (!Stop){
		Xuat();
		SinhKeTiep();
	}
}
main(){
	KhoiTao();
	Sinh();
}

