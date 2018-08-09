#include<conio.h>
#include<stdio.h>
#define TRUE 1
#define FALSE 0
FILE *f1;
int stack[88],A[88][88],CE[88],N;
void Nhap()
{
	char c;
	f1=fopen("dothi8.in","r");
	fscanf(f1,"%d",&N);
	for(int i=1;i<=N;i++)
	{
		for(int j=1;j<=N;j++)
		{
			A[i][j]=0;
		}
	}
	int i=0,j;
	while(i<=N)
	{
		fscanf(f1,"%c",&c);
		if(c=='\n')
		{
			i++;
		}
		if(c!=' ')
		{
			j=c-'0';
			A[i][j]=1;
		}
	}
	for(i=1;i<=N;i++)
	{
		printf("\n ");
		for(j=1;j<=N;j++)
		{
			printf(" %d ",A[i][j]);
		}
	}
	fclose(f1);
}
int Ktra()
{
	int i,j,s,d;
	d=0;
	for(i=1;i<=N;i++)
	{
		s=0;
		for(j=1;j<=N;j++)
			s=s+A[i][j];
		if(s%2) d++;
	}
	if(d>0) return 0;
	else return 1;
}
void TimEuler()
{
	int top,v,u,dCE,x;
	dCE=0;
	top=1;
	printf("\n Nhap dinh bat dau: ");
	scanf("%d",&u);
	stack[top]=u;
	while(top!=0)
	{
		v=stack[top];x=1;
		while(x<=N && A[v][x]==0) x++;
		if(x>N)
		{
			dCE++; CE[dCE]=v; top--;
		}
		else
		{
			top++;stack[top]=x;
			A[v][x]=A[x][v]=0;
		}
	}
	printf("\n Chu trinh Euler: \n");
	for(int i=dCE;i>0;i--)
		printf(" %d  ",CE[i]);
}
int main()
{
	Nhap();
	if(Ktra())
		TimEuler();
}
