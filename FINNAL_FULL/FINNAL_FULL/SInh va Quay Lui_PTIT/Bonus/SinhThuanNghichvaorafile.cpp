#include<stdio.h>
#include<conio.h>
int B[100],n, Stop, dem=0;
FILE *f2;
void KhoiTao(){
	printf(" nhap n= ");
	scanf("%d",&n);
	for(int i=1; i<=n;i++){
		B[i]=0;
	}
}
int MangThNghich(int *M,int n)
{
	int r=1,s=n;
	while(r<s)
	{
	if (M[r]!=M[s]) return 0;
	r++;s--;
	}
	return 1;
}
void Xuat(){
	fprintf(f2,"\n");
	for(int i=1;i<=n;i++){
	fprintf(f2," %2d ",B[i]);
	}
}
void SinhKeTiep(){
	int i=n;
	while(i>0 && B[i]==1){
		B[i]=0;
		i--;	
	}
	if(i==0){
		Stop=1;
	}
	else B[i]=1;
}
void Sinh(){
	Stop=0;
	f2 =fopen("ketqua.out","w");
	while(!Stop){
		if(MangThNghich(B,n)){
			dem++;
			Xuat();
		}
		SinhKeTiep();
	}
	rewind(f2);
	fprintf(f2,"%d",dem);
	fprintf(f2,"\n");
	fclose(f2);
}
main(){
	KhoiTao();
	Sinh();
}
