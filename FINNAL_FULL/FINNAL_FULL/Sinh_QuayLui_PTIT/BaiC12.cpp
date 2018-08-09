#include <stdio.h>
#include <conio.h>
#define TRUE 1
#define FALSE 0
int N, K, C[100],A[100], Stop, dem=0;
FILE *f1, *f2;
void KhoiTao(){
	int i;
	f1=fopen("dayso.in","r");
	fscanf(f1,"%d", &N);
	fscanf(f1,"%d", &K);
	for(i=1; i<=K; i++)
		C[i]=i;
	for(int j=1; j<=N; j++){
		fscanf(f1,"%d",&A[j]);
	}
	fclose(f1);
	
}
int KTTang(){
	for(int i=1 ; i<=K-1; i++){
		if(A[C[i]]>A[C[i+1]]) return 0;
	}
	return 1;
}
void Xuat(){
	fprintf(f2,"\n");
	for(int i=1; i<=K; i++)
		fprintf(f2,"%2d  ", A[C[i]]);
}
void SinhKeTiep(){
	int i,j;
	i = K;
	while(i>0 && C[i]==N-K+i)
		i--;
	if(i>0) {
		C[i]= C[i]+1;
		for(j=i+1; j<=K; j++)
			C[j]=C[i]+j-i;
	}
	else Stop = TRUE;
}
void Sinh(){
	f2=fopen("ketqua1.out","w");
	Stop=FALSE;
	while (!Stop){
		if(KTTang()){
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

