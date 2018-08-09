#include <conio.h>
#include <stdio.h>
#include <iostream>
#define max 100
using namespace std;
FILE *f;
int a[max][max],n,m,u,dem=0,cay[max][2],chuaxet[max],dscanh[max][2];
void docfile(){
	int i,j;
	f=fopen("dothi5.txt","r");
		fscanf(f,"%d",&n);fscanf(f,"%d",&m);
		fscanf(f,"%d",&u);
	for(i=1;i<=n;i++)
	for(j=1;j<=n;j++)
	a[i][j]=0;
		for(i=1;i<=m;i++){
			fscanf(f,"%d",&dscanh[i][1]);
			fscanf(f,"%d",&dscanh[i][2]);
	}
	for(i=1;i<=m;i++){
		a[dscanh[i][1]][dscanh[i][2]]++;
		a[dscanh[i][2]][dscanh[i][1]]++;
	}
	for(j=1;j<=n;j++)   chuaxet[j]=1;
	fclose(f);
}
typedef struct{
	int in;
	int x[max];
}stack;
void init(stack *s){
	s->in=-1;
}
int empty(stack *s){
	if(s->in==-1) return 1;
	return 0;
}
int full(stack *s){
	if(s->in==max-1) return 1;
	return 0;
}
void push(stack *s,int a) {
	if(!full(s))s->in =s->in +1;
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
	if(!empty(s))  return(s->x[s->in]);
	return 0;
}*/
void caykhungDFS(){
	stack s;int i,h;
	init(&s);docfile();
	push(&s,u);chuaxet[u]=0;
	while(!empty(&s)){
		h=pop(&s);i=1;
		while(i<=n){
			if(a[h][i]>0&&chuaxet[i]) {
				dem++;
				cay[dem][1]=h;
				cay[dem][2]=i;
				push(&s,h);push(&s,i);
				chuaxet[i]=0;break;
		} i++;
	  }
    }
}
void result(){
	caykhungDFS();
	f=fopen("cay5.txt","w");
		fprintf(f,"%d ",n);
		fprintf(f,"%d\n",dem);
	for(int i=1;i<=dem;i++){
		fprintf(f,"%d ",cay[i][1]);
		fprintf(f,"%d\n",cay[i][2]);
	}
	fclose(f);
}
int main(){
	result();
}
