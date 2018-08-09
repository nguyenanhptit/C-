#include<conio.h>
#include<stdio.h>
#define FALSE 0
#define TRUE 1
FILE *f1;
int d,N,stack[50],CE[50],A[50][50],a[50];
void Nhap()
{
	f1=fopen("dothi9.in","r");
	fscanf(f1,"%d",&N);
	for(int i=1;i<=N;i++)
	{
		for(int j=1;j<=N;j++)
			fscanf(f1,"%d",&A[i][j]);
	}
	for(int i=1;i<=N;i++)
	{
		printf(" \n");
		for(int j=1;j<=N;j++)
			printf(" %d ",A[i][j]);
	}
}
int Ktra()
{
	int s;
	d=0;
	for(int i=1;i<=N;i++)
	{
		s=0;
		for(int j=1;j<=N;j++)
		{
			s=s+A[i][j];
		}
		if(s%2!=0)
		{
			d++; a[d]=i;
		}
	}
	if(d!=2) return 0;
	else return 1;
}
void TimEuler(int u)
{
	int i,x,v,top,dCE;;
	printf("\n Dinh bat dau: %d :",u);
	top=1; dCE=0;
	stack[top]=u;
	while(top!=0)
	{
		v=stack[top];x=1;
		while(x<=N && A[v][x]==0) x++;
		if(x>N)
		{
			top--; dCE++; CE[dCE]=v;
		}
		else
		{
			top++; stack[top]=x;
			A[v][x]=A[x][v]=0;
		}
	}
	for(int j=dCE;j>0;j--)
	{
	printf(" %d ",CE[j]);
	}
}
int main()
{
	Nhap();
	if(Ktra())
	{
		printf("\n Duong di Euler: \n");
		TimEuler(a[1]);
	}
	else 
	printf("\n Khong co duong di Euler");
}
