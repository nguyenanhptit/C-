#include<conio.h>
#include<stdio.h>
#define TRUE 1
#define FALSE 0
FILE *f1;
int N,A[88][88],stack[88],CE[88],u=1;
void Nhap()
{
	f1=fopen("dothi7.in","r");
	fscanf(f1,"%d",&N);
	for(int i=1;i<=N;i++)
	{
		for(int j=1;j<=N;j++)
			fscanf(f1,"%d",&A[i][j]);
	}
	for(int i=1;i<=N;i++)
	{
		for(int j=1;j<=N;j++)
			printf(" %d ",A[i][j]);
		printf("\n");	
	}
	fclose(f1);
}
int Kiemtra()
{
	int i,j,s,d;
	d=0;
	for(i=1;i<=N;i++)
	{
		s=0;
		for(j=1;j<=N;j++)
			s=A[i][j]+s;
		if(s%2) d++;
	}
	if(d>0) return 0;
	return 1;
}
void TimEuler()
{
	int v,x,top,dCE;
	top=1;
	stack[top]=1;
	dCE=0;
	while(top!=0)
	{
		v=stack[top];x=1;
		while(x<=N && A[v][x]==0)
			x++;
		if(x>N)
		{
			dCE++; CE[dCE]=v;top--;
		}	
		else
		{
			top++; stack[top]=x;
			A[v][x]=A[x][v]=0;
		}
	}
	printf("\n Co chu trinh Euler: \n");
	for(x=dCE;x>0;x--)
		printf("%d ",CE[x]);
}
int main()
{
	Nhap();
	if(Kiemtra())
	{
		TimEuler();
	}
}
