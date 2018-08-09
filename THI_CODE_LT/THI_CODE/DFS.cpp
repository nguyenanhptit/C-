#include<stdio.h>
#include<conio.h>
#define max 20
int V,a[max][max],CK[max][max],chuaxet[max],socanh;
void Khoitao_Chuaxet(){
	for(int i=0;i<max;i++)
	chuaxet[i]=1;
}
void STREE_DFS(int i){
	int j;
	if(socanh==V-1) return;
	for(j=1;j<=V;j++){
		if(chuaxet[j]&&a[i][j]){
			chuaxet[j]=0;
			socanh++;
			CK[socanh][1]=i;
			CK[socanh][2]=j;
			if(socanh==V-1) return;
			STREE_DFS(j);
		}
	}
}
void kq(){
	int i,j;
	for(i=1;i<=socanh;i++){
		for(j=1;j<=2;j++){
			printf("%3d",CK[i][j]);
		}
		printf("\n");
	}
}
void docDSC(){
	int u,v;
	FILE*f1=fopen("C:\\Users\\duyha\\Desktop\\\HOCTAP\\DSC.txt","r");
	fscanf(f1,"%d",&V);
	fscanf(f1,"%d",&socanh);
	for(int i=1;i<=V;i++)
		for(int j=1;j<=V;j++)
			a[i][j]=0;
	for(int i=1;i<=socanh;i++){
		fscanf(f1,"%d%d",&u,&v);
		a[u][v]=a[v][u]=1;
	}		
	fclose(f1);
}
void MTK(){
	printf("%d\n",V);
	for(int i=1;i<=V;i++){
		for(int j=1;j<=V;j++){
			printf("%3d ",a[i][j]);
		}
		printf("\n");
	}
}
void DSK(){
	printf("%d\n",V);
	for(int i=1;i<=V;i++){
		for(int j=1;j<=V;j++)
			if(a[i][j]==1){
				printf("%3d",j);
			}
			printf("\n");	
	}
}
int main(){
	docDSC();
	printf("\n");
	printf("Danh sach ke la:\n");
	MTK();
	printf("\n");
	printf("Danh sach canh la:\n");
	DSK();
	printf("\n");
	Khoitao_Chuaxet();
	socanh=0; int i=1;
	chuaxet[i]=0;
	STREE_DFS(i);
	kq();
}
