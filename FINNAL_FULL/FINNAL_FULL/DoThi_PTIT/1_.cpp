#include <conio.h>
#include <stdio.h>
#include <iostream>
using namespace std;
FILE *f1,*f2;
int ok,n,m,mtke[100][100],dscanh[100][2];
char dske[1000],kituso[10];
int dem=1,sodinh=1,socanh=0;
void docfile(){
	f1=fopen("dske.txt","r");
		fscanf(f1,"%3d\n",&n); 
	while(!feof(f1))	{
		dske[dem]=fgetc(f1);  dem++;
	}
	for(int i=1;i<=dem;i++)
	fclose(f1);
}
void KhoiTao(){
	for(int i=1;i<=n;i++)
	for(int j=1;j<=n;j++)
        mtke[i][j]=0;
	kituso[1]='0';kituso[2]='1';kituso[3]='2';kituso[4]='3';
	kituso[5]='4';kituso[6]='5';kituso[7]='6';kituso[8]='7';
	kituso[9]='8';kituso[10]='9';
}
void chuyendoi(){
	KhoiTao();
	for(int i=1;i<dem;i++)
	{
		if(dske[i]=='\n')	sodinh++;
		for(int j=2;j<=10;j++)
            if(dske[i]==kituso[j])
            {
	           ok=0;
               for(int k=2;k<=10;k++)
                   if(dske[i+1]==kituso[k])
                   {
				ok=1;
                     mtke[sodinh][10*(j-1)+k-1]++;
			   mtke[10*(j-1)+k-1][sodinh]++;
				if(sodinh <10*(j-1)+k-1){
                       		++socanh;
                       dscanh[socanh][1]=sodinh;
                       dscanh[socanh][2]=10*(j-1)+k-1;
                      }
			 }
			        if(ok==0)
                    {
                       mtke[sodinh][j-1]++;
                       mtke[j-1][sodinh]++;
				  if(sodinh<j-1) {
                         	++socanh;
                         dscanh[socanh][1]=sodinh;
                         dscanh[socanh][2]=j-1;
                        }
			  }
	      }
    	}
}
void Ketqua(){
	chuyendoi();
	f1=fopen("mtke.txt","w");
	f2=fopen("dscanh.txt","w");
		fprintf(f1,"%3d\n",n); fprintf(f2,"%3d ",n);
		fprintf(f2,"%3d\n",socanh);
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			fprintf(f1,"%3d ",mtke[i][j]/2);
		}
		fprintf(f1,"\n");
	}
	for(int i=1;i<=socanh;i++){
		for(int j=1;j<=2;j++){
			fprintf(f2,"%3d ",dscanh[i][j]);
		}
		fprintf(f2,"\n");
	}
	fclose(f1);fclose(f2);
}
int main(){
	docfile();
	Ketqua();
}
