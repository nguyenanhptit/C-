#include <conio.h>
#include <stdio.h>
int B[100], n, k;
void KhoiTao(void){
	printf("\n Nhap n= "); scanf("%d", &n);
	printf("\n Nhap k= "); scanf("%d", &k);
	B[0]=0;
}
void Xuat(){
	int i;
	printf("\n");
	for(i=1; i<=k; i++){
		printf("%3d", B[i]);
	}
}
void Try(int i){
	int j;
	for(j=B[i-1]+1;j<=(n-k+i); j++){
		B[i]=j;
		if(i==k) Xuat();
		else Try(i+1);
	}
}
main(){
	KhoiTao();
	Try(1);
}

