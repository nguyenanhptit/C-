#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#define MaxV 20
#define max 100
int A[MaxV][MaxV],V=0;
int chuaXet[max];
/*void nhap(int A[][MaxV],int &V)
{
	printf("nhap V    ");
	scanf("%d",&V);
	for(int i=0;i<V;i++)
	{
		for(int j=0;j<V;j++)
		{ printf("A[%d,%d]=",i+1,j+1);
			scanf("%d",&A[i][j]);
		}
	}
}
void ghiMTK(int A[][MaxV],int V)
{	
	FILE *f1;
	f1=fopen("MTK.txt","wt");
	fprintf(f1,"%d\n",V);
	for(int i=0;i<V;i++)
	{
		for(int j=0;j<V;j++)
		
			fprintf(f1,"%3d ",A[i][j]);
			fprintf(f1,"\n");
		
	}	fclose(f1);
}*/
void ghiDSK(int A[][MaxV],int &V)
{
		
	FILE *f2;
	f2=fopen("DSK.txt","wt");
	fprintf(f2,"%d\n",V);
	for(int i=0;i<V;i++)
	{
		for(int j=0;j<V;j++)
			if(A[i][j]!=0)
			fprintf(f2,"%d  ",j+1);
			fprintf(f2,"\n");
		
	}	fclose(f2);
}
void ghiDSC(int A[][MaxV],int &V)
{
	int d=0;	
	FILE *f3;
	f3=fopen("DSC.txt","wt");
	//fprintf(f3,"%d\n",V);
	fprintf(f3,"%d\n\n\n");
	for(int i=0;i<V;i++)
	{
		for(int j=0;j<V;j++)
			if(A[i][j]!=0&&i<=j)
			{fprintf(f3,"%d  %d\n",i+1,j+1);d++;}
			//fprintf(f3,"\n");
		
	}	
	rewind(f3);fprintf(f3,"%d  %d\n",V,d);
	fclose(f3);
}
int DocMTK(int A[][MaxV],int &V)
{
	FILE *f=fopen("MTK.txt","rt");
	if(f==NULL)
	{
		return 0;
	}
	fscanf(f,"%d",&V);
	for(int i=0;i<V;i++)
	{
		for(int j=0;j<V;j++)
		
			fscanf(f,"%d",&A[i][j]);
		
	}	return 1;
	
}
void KhoiTaochuaxet()
{
	for(int i=0;i<max;i++)
	//chuaXet[i]=1;
	chuaXet[i]=0;
}
void DFS(int u)
{
	chuaXet[u]=0;
	printf("%d->",u);
	for(int v=0;v<V;v++)
	if(chuaXet[v]==1&&A[u][v]==1)
	{
		DFS(v);
	}
}
void BFS(int u)
{
	int queue[max],dau=0,cuoi=0;
	for(int i=0;i<max;i++) queue[i]=0;
	queue[cuoi]=u;
	chuaXet[u]=0;
	printf("%d->",u);
	queue[dau++]=u;
	chuaXet[u]=1;
	while(dau>cuoi)
	{ int u=queue[cuoi];
		cuoi++;
		for(int v=0;v<V;v++)
		if (A[u][v]!=0)
		if( chuaXet[v]==0)
		{
			dau++;
			queue[dau]=v;
			chuaXet[v]=1;
			printf("%d->",v);
		}
	}
}
int main()
{	int u=0;
	//nhap(A,V);
	DocMTK(A,V);
	//ghiMTK(A,V);
	ghiDSK(A,V);
	ghiDSC(A,V);
	DocMTK(A,V);
	KhoiTaochuaxet();
	/*printf("DFS\n");
	DFS(u);*/
	printf("\nBFS\n");
	BFS(u);
}
