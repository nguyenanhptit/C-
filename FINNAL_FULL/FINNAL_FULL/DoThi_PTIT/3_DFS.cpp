#include <conio.h>
#include <stdio.h>
#define max 100
using namespace std;
FILE *f;
int a[max][max],n,u,dem=0,dem1=1,cay[max][2],chuaxet[max];
char dske[1000],kituso[10];
void docfile(){
	int i,j;
	f=fopen("dothi3.txt","r");
		fscanf(f,"%3d",&n);
		fscanf(f,"%3d\n",&u);
	while(!feof(f)){
		dske[dem1]=fgetc(f); dem1++;
	}
	for(j=1;j<=n;j++)  chuaxet[j]=1;
	fclose(f);
}
typedef struct{
	int in;
	int x[max];
}stack;
void khoitao(stack *s){
	s->in=-1;
}
int empty(stack *s){
	if(s->in==-1)  return 1;
	return 0;
}
int full(stack *s){
	if(s->in==max-1)   return 1;
	return 0;
}
void push(stack *s,int a){
	if(!full(s))  s->in =s->in +1;
	s->x[s->in] =a;
}
int pop(stack *s){
	if(!empty(s)) {
	int a=s->x[s->in];
		s->in=s->in -1;
	return a;
   }
	else return 0;
}
/*int viewtop(stack *s){
	if(!empty(s))     return(s->x[s->in]);
	return 0;
}*/
void khoitao(){
	int i,j;
	for(i=1;i<=n;i++)
	for(j=1;j<=n;j++)	a[i][j]=0;
	kituso[1]='0';kituso[2]='1';kituso[3]='2';kituso[4]='3';
	kituso[5]='4';kituso[6]='5';kituso[7]='6';kituso[8]='7';
	kituso[9]='8';kituso[10]='9';
}
void chuyendoi(){
	khoitao();
	int i,j,k,ok,sodinh=1,socanh=0;
	for(i=1;i<dem1;i++)
	{
		if(dske[i]=='\n')   sodinh++;
		for(j=1;j<=10;j++)
		if(dske[i]==kituso[j]){
	     		ok=0;
	     	for(k=1;k<=10;k++)
	     	if(dske[i+1]==kituso[k]) {
		     ok=1;
		     a[sodinh][10*(j-1)+k-1]++;
		     a[10*(j-1)+k-1][sodinh]++;
		}
			if(ok==0){
				a[sodinh][j-1]++;
				a[j-1][sodinh]++;
	   	}
      }
   }
}
void caykhungDFS(){
	stack s;int i,h;
	khoitao(&s);docfile();chuyendoi();
	push(&s,u);chuaxet[u]=0;
	while(!empty(&s)){
		h=pop(&s);
		for(i=1;i<=n;i++)
		//while(i<=n){
			if(a[h][i]>0 && chuaxet[i]){
			      //push(&s,h);
				push(&s,i);chuaxet[i]=0;
				dem++;
				cay[dem][1]=h;cay[dem][2]=i;
				//break;
		}	//i++;	
	 }
    }
//}
void result(){
	caykhungDFS();
	f=fopen("cay3.txt","w");
		fprintf(f,"%3d ",n);
		fprintf(f,"%3d\n",dem);
	for(int i=1;i<=dem;i++) {
		fprintf(f,"%3d ",cay[i][1]);
		fprintf(f,"%3d\n ",cay[i][2]);
	}
	fclose(f);
}
int main(){
	result();
}
