#include<stdio.h>
#include<conio.h>
int A[100][100], N, dinh[100];
void Nhap_MTK(){
	FILE *f1=fopen("MTK_IN.txt","r");
	fscanf(f1,"%d",&N);
	for(int i=1; i<=N; i++){
		for(int j=1; j<=N; j++){
			fscanf(f1,"%d",&A[i][j]);
		}
	}
	fclose(f1);
}
int soCanh(){
	int dem=0;
	for(int i=1; i<=N; i++){
		for(int j=i+1; j<=N; j++){
			if(A[i][j]==1) dem++;
		}
	}
	return dem;
}
void soDinh(){
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
//	}
}
void KTEuler(){
	soDinh();
	int le=0;
	for(int i=1; i<=N; i++){
		if(dinh[i] %2 !=0){
			le++;
		}
	}
	if(le==0) printf("\n co do thi euler");
	else if( le<=2) printf(" \nco duong di euler");
	else printf(" \nkhong co do thi euler hay duong di euler");
	
}
void Xuat_DSC(){
	FILE *f2=fopen("DSC_OUT1.txt","w");
	fprintf(f2,"%d   %d",N,soCanh());
	for(int i=1; i<=N;i++){
		for(int j=i+1; j<=N; j++){
			if(A[i][j]==1){
				fprintf(f2,"\n%d   %d",i, j);
			}
		}
	}
	fclose(f2);
	
}
void Xuat_DSK(){
	FILE *f3=fopen("DSK_OUT1.txt","w");
	fprintf(f3,"%d",N);
	fprintf(f3,"\n");
	for(int i=1; i<=N; i++){
		for(int j=1; j<=N;j++){
			if(A[i][j]==1) fprintf(f3,"%d  ",j);
		}
		fprintf(f3,"\n");
	}
	fclose(f3);
}
main(){
	Nhap_MTK();
	KTEuler();
//	soDinh();
//	Xuat_DSC();
//	Xuat_DSK();
}






