#include<stdio.h>
#include<conio.h>
int A[100][100], N, soCanh,dinh[100];
void Nhap_DSC(){
	int i,j;
	FILE *f1=fopen("DSC_IN.txt","r");
	fscanf(f1,"%d %d",&N, &soCanh);
	for(int i=1; i<=N;i++){
		for(int j=1; j<=N;j++){
			A[i][j]=0;		}
	}
	for(int k=1; k<=soCanh; k++){
		fscanf(f1,"%d %d", &i, &j);
		A[i][j]= A[j][i]= 1;
	}
	fclose(f1);
}
void Bac(){
	for(int i=1; i<=N;i++){
		int dem=0;
		for(int j=1; j<=N;j++){
			if(A[i][j]==1){
				dem++;
			}
		}
		
	dinh[i]=dem;
	}
	for(int i=1; i<=N; i++){
	printf("\nbac cua dinh %d la: %d",i, dinh[i]);
	}
}
//void soDinh(){
//	int dem,h;
//	FILE *f1=fopen("DSC_IN.txt","r");
//	fscanf(f1,"%d %d",&N, &soCanh);
//	for(int i=1; i<=N; i++){
//		dem=0;
//		for(int j=1; j<=soCanh; j++){
//			for(int k=1; k<=2; k++){
//				fscanf(f1,"%d",&h);
//				if(h==i) dem++;
//			}
//		}
//		dinh[i]=dem;
//		fclose(f1);
//		fscanf(f1,"%d %d",&N, &soCanh);
//		FILE *f1=fopen("DSC_IN.txt","r");
//		fscanf(f1,"%d %d",&N, &soCanh);
//	}
//	for(int i=1; i<=N; i++)
//	printf("\nbac cua dinh %d la: %d",i, dinh[i]);	
//	fclose(f1);
//}
void Xuat_MTK(){
	FILE *f2=fopen("MTK_OUT2.txt","w");
	fprintf(f2,"%d",N);
	fprintf(f2,"\n");
	for(int i=1; i<=N; i++){
		for(int j=1; j<=N; j++){
			fprintf(f2,"%d   ",A[i][j]);
		}
		fprintf(f2,"\n");
	}
	
	fclose(f2);
}
void Xuat_DSK(){
	FILE *f3=fopen("DSK_OUT2.txt","w");
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
	Nhap_DSC();
	 Bac();
	Xuat_MTK();
	Xuat_DSK();
}

