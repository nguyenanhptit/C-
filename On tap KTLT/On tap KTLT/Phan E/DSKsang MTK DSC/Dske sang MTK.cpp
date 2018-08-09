#include<stdio.h>
#include<conio.h>
int A[100][100],n;
FILE *f1;
FILE *f2;
FILE *f3;
void docfile(){
int i=0,j;
char c;
fscanf(f1,"%d",&n);
while(i<=n){
fscanf(f1,"%c",&c);
if(c=='\n')
i++;
else
if(c!=' '){
j=c-'0';
A[i][j]=1;
}
}
}
void ghimatran(){
fprintf(f2,"%d\n",n);
int i,j;
for(i=1;i<=n;i++){
for(j=1;j<=n;j++)
fprintf(f2,"%4d",A[i][j]);
fprintf(f2,"\n");
}
}
void ghidscanh(){
int i,j,m=0;
fprintf(f3,"\n\n");
for(i=1;i<=n;i++)
for(j=i+1;j<=n;j++)
if(A[i][j]==1){
fprintf(f3,"\n%d %d",i,j);
m++;
}
rewind(f3);
fprintf(f3,"%d %d",n,m);
}
int main(){
f1 = fopen("DSK.TXT","r");
f2 = fopen("MATRANKE.TXT","w");
f3 = fopen("DSCANH.TXT","w");
docfile();
ghimatran();
ghidscanh();
getch();
fclose(f1);
fclose(f2);
fclose(f3);
return 0;
}

