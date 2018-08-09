#include"conio.h"
#include"io.h"
#include"stdio.h"
#define MAX 100
#define  TRUE 1
#define FALSE 0
char c;
int CK[MAX][2],V,A[MAX][MAX],chuaxet[MAX],socanh,QUEUE[MAX];
int DocDSK(int A[MAX][MAX],int &V)
{
	int i=0,j;
	FILE *f=fopen("DSK_IN.txt","r");
	if(f==NULL)
	{
		printf("Doc file loi!!!");
		return 0;
	}
	fscanf(f,"\n%d",&V);
	printf("\nSo dinh do thi:%d\n",V);
	while(i<=V)
	{
		fscanf(f,"%c",&c);
		if(c=='\n')
		i++;
		else
		if(c!=' ')
		{
			j=c-'0';
			A[i][j]=1;
		}
	}
	printf("\nMa tran ke:");
	printf("\n");
	for(int i=1;i<=V;i++)
	{
		for(int j=0;j<=V;j++)
		{
			fscanf(f,"%d",&A[i][j]);
			printf("%2d",A[i][j]);
		}
		printf("\n");
	}
	fclose(f);
}
void KhoiTao_ChuaXet()
{
	for(int i=0;i<MAX;i++)
	chuaxet[i]=1;
}
void STREE_DFS(int i)
{
	int j;
	if(socanh==V-1) return;
	for(j=1;j<=V;j++)
	{
		if(chuaxet[j]&&A[i][j])
		{
			chuaxet[j]=FALSE;
			socanh++;
			CK[socanh][1]=i;
			CK[socanh][2]=j;
			if(socanh==V-1) return ;
			STREE_DFS(j);
		}
	}
}
void kq()
{
	int i,j;
	for(i=1;i<=socanh;i++)
	{
		for(j=1;j<=2;j++)
		{
			printf("%2d",CK[i][j]);
		}
		printf("\n");
	}
}
void STREE_BFS(int u)
{
	int dauQ,cuoiQ,v,p;
	dauQ=1;cuoiQ=1;
	QUEUE[dauQ]=u;
	chuaxet[u]=FALSE;
	while(dauQ<=cuoiQ)
	{
		v=QUEUE[dauQ];dauQ=dauQ+1;
		for(p=1;p<=V;p++)
		{
			if(chuaxet[p]&&A[v][p])
			{
				chuaxet[p]=FALSE;
				socanh++;
				CK[socanh][1]=v;
				CK[socanh][2]=p;
				cuoiQ=cuoiQ+1;
				QUEUE[cuoiQ]=p;if(socanh==V-1) return;
				
			}
		}
	}
}

int main()
{
	int i=1;
	DocDSK(A,V);
	printf("\n");
	KhoiTao_ChuaXet();
	socanh=0;
	chuaxet[i]=FALSE;
	STREE_DFS(i);
	kq();
	getch();
}
