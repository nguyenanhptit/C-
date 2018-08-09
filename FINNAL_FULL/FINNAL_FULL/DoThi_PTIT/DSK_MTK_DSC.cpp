#include<stdio.h>
#include<conio.h>
int A[100][100], N, dinh[100];
char c;
void Nhap_DSK(){
	int i=0;
	FILE *f1=fopen("DSK_IN.txt","r");
	if(f1==NULL){
		printf("doc file loi");
		return;
	}
	fscanf(f1,"%d",&N);
	for(int l=1; l<=N;l++){
		for(int m=1; m<=N;m++){
			A[l][m]=0;
		}
	}
	while(i<=N){
		fscanf(f1,"%c",&c);
		if(c=='\n') i++;
		else if(c!= ' '){
			int j= c-'0';
			A[i][j]=1;
		}
	}	
	fclose(f1);
}
void BacCuaDinh(){
	for(int i=1; i<=N;i++){
		int dem=0;
		for(int j=1; j<=N;j++){
			if(A[i][j]==1){
				dem++;
			}
		}
		
	dinh[i]=dem;
	}
//	for(int i=1; i<=N; i++){
//	printf("\nbac cua dinh %d la: %d",i, dinh[i]);
	
}
//void soDinh(){
//	int i=0,dem =0;
//	FILE *f1=fopen("DSK_IN.txt","r");
//	if(f1==NULL){
//		printf("doc file loi");
//		return;
//	}
//	fscanf(f1,"%d",&N);
//	while(i<=N){
//		fscanf(f1,"%c",&c);
//		if(c=='\n'){
//			dem=0;
//			i++;
//		}
//		else if(c!= ' '){
//			int j= c-'0';
//			A[i][j]=1;
//			dem++;
//		}
//		dinh[i]=dem;
//	}
//	for(int i=1; i<=N; i++)
//	printf("\nbac cua dinh %d la: %d",i, dinh[i]);	
//	fclose(f1);
//}
void DoThiEuler(){
	BacCuaDinh();
	int kt=1;
	for(int i=1; i<=N;i++){
		if(dinh[i] %2 != 0) kt=0;
	}
	if(kt==0) printf("\n khong phai do thi euler");
	else printf(" day la do thi euler");
}
int soCanh(){
	int dem=0;
	for(int i=1; i<=N; i++){
		for(int j=i+1; j<=N;j++){
			if(A[i][j]==1){
				dem++;
			}
		}
	}
	return dem;
}
void Xuat_MTK(){
	FILE *f2=fopen("MTK_OUT3.txt","w");
	fprintf(f2,"%d\n",N);
	for(int i=1; i<=N;i++){
		for(int j=1; j<=N;j++){
			fprintf(f2,"%d  ",A[i][j]);
		}
		fprintf(f2,"%d\n");
	}
	fclose(f2);
}
void Xuat_DSC(){
	FILE *f3=fopen("DSC_OUT3.txt","w");
	fprintf(f3,"%d   %d",N,soCanh());
	for(int i=1; i<=N;i++){
		for(int j=i+1; j<=N; j++){
			if(A[i][j]==1){
				fprintf(f3,"\n%d   %d",i ,j);
			}
		}
	}
	fclose(f3);
}
main(){
	Nhap_DSK();
	DoThiEuler();
//	Xuat_MTK();
//	Xuat_DSC();
}











