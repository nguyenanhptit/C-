#include<stdio.h>
#include<conio.h>
#include<math.h>
int n,B[100];
void KhoiTao(){
	printf("\n n= ");
	scanf("%d",&n);
}
void Xuat(){
	for(int i=1; i<=n;i++){
		printf(" %2d ",B[i]);
	}
	printf("\n");
}
void Try(int i){
	for(int j= 0; j<=1;j++){
		B[i]=j;
		if(i==n){

			Xuat();
		}
		else Try(i+1);
	}
}
main(){
	KhoiTao();
	Try(1);
}
