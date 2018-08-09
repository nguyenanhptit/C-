#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#define MaxV 20
#define max 100
int A[MaxV][MaxV],V=0;
int DocMTK(/*int A[][MaxV],int &V*/)
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
		
	}
	printf("\n Tong So dinh la %d",V);
		return 1;
	
}
int KTeuler()
{
	int Bac,d=0;
	for(int i=0;i<V;i++)
	{ Bac=0;
		for(int j=0;j<V;j++)
		if(A[i][j]>0) Bac++;
		if(Bac%2==1) d++;
	} printf("\n So dinh bac chan la %d",V-d);
	if(d==0) {printf("\n Day la do thi euler "); return 1;}
	else  printf("\n Day khong la do thi euler ");
	return 0;
}
int KTnuaeuler()
{
	int Bac,d=0;
	for(int i=0;i<V;i++)
	{ Bac=0;
		for(int j=0;j<V;j++)
		if(A[i][j]>0) Bac++;
		if(Bac%2==1) d++;
	} printf("\n So dinh bac le la %d",d);
	if(d<=2) printf("\n Day la do thi nua euler ");
	else  printf("\n Day khong la do thi nua euler ");
}
int main()
{
	DocMTK();
	if(KTeuler()==0)KTnuaeuler();
	}	
