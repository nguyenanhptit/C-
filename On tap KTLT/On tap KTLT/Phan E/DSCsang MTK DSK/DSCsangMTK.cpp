#include<stdio.h>
#include<conio.h>
int A[100][100],n;
FILE *f1;
FILE *f2;
FILE *f3;
void docfile(){
int i,j,c,d,m;
fscanf(f1,"%d %d",&n,&m);
for(i=0;i<n;i++)
for(j=0;j<n;j++)
A[i][j]=0;
for(i=0;i<m;i++)
{
	fscanf(f1,"%d %d",&c,&d);
	A[c-1][d-1]=A[d-1][c-1]=1; }
}

void ghimatran(){
fprintf(f2,"%d\n",n);
int i,j;
for(i=0;i<n;i++)
{
for(j=0;j<n;j++)
fprintf(f2,"%4d",A[i][j]);
fprintf(f2,"\n");
}
}
void ghiDSK()
{		
	fprintf(f3,"%d\n",n);
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
			if(A[i][j]!=0)
			fprintf(f3,"%d  ",j+1);
			fprintf(f3,"\n");
		
	}	fclose(f3);
}
int main()
{
f1 = fopen("DSCANH.TXT","r");
f2 = fopen("MATRANKE11.TXT","w");
f3 = fopen("DSK11.TXT","w");
docfile();
ghimatran();
ghiDSK();
getch();
fclose(f1);
fclose(f2);
fclose(f3);
return 0;
}
