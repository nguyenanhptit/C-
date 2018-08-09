#include <conio.h>
#include <stdio.h>
#include <iostream>
#define max 100
using namespace std;
FILE *f;
int a[max][max],n,u,dem=0,dem1=1,cay[max][2],chuaxet[max];
char dske[1000],kituso[10];
void docfile(){
	int i,j;
	f=fopen("dothi2.txt","r");
		fscanf(f,"%3d",&n);
		fscanf(f,"%3d\n",&u);
	while(!feof(f)){
		dske[dem1]=fgetc(f);
		dem1++;
	}
	for(j=1;j<=n;j++)   chuaxet[j]=1;
	fclose(f);
}
typedef struct{
	int in;
	int out;
	int node[max];
}queue;
void init(queue	*q){
	q->in=q->out=-1;
}
int empty(queue *q){
	if(q->in == q->out)   return 1;
	return 0;
}
int full(queue *q){
	if(q->in ==max-1)   return 1;
	return 0;
}
void push(queue *q,int x){
	if(!full(q)) {
		q->in =q->in +1;
		q->node[q->in]=x;}
}
int pop(queue *q){
	if(empty(q))   return 0;
	else {
		q->out = q->out +1;
	int x=q->node[q->out];
	return x;
     }
}
void khoitao(){
	int i,j;
	for(i=1;i<=n;i++)
	for(j=1;j<=n;j++)a[i][j]=0;
	kituso[1]='0';kituso[2]='1';kituso[3]='2';kituso[4]='3';
	kituso[5]='4';kituso[6]='5';kituso[7]='6';kituso[8]='7';
	kituso[9]='8';kituso[10]='9';
}
void chuyendoi(){
	khoitao();
	int i,j,k,ok,sodinh=1,socanh=0;
	for(i=1;i<dem1;i++)
	{
		if(dske[i]=='\n')sodinh++;
		for(j=1;j<=10;j++) 
		if(dske[i]==kituso[j]){
	     		ok=0;
		     for(k=1;k<=10;k++)
		     if(dske[i+1]==kituso[k]){
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
void caykhungBFS(){
	int i,j,h;queue q;
	init(&q);
	docfile();chuyendoi();
	push(&q,u);chuaxet[u]=0;
	while(!empty(&q)){
		h=pop(&q);
		for(i=1;i<=n;i++)
		if(a[h][i]>0&&chuaxet[i]) {
			push(&q,i);chuaxet[i]=0;
			dem++;
			cay[dem][1]=h;cay[dem][2]=i;
		}
	}
	f=fopen("cay2.txt","w");
		fprintf(f,"%3d ",n);
		fprintf(f,"%3d\n",dem);
	for(i=1;i<=dem;i++){
		fprintf(f,"%3d ",cay[i][1]);
		fprintf(f,"%3d\n",cay[i][2]);
	}
	fclose(f);
}
int main(){
	int i;
	caykhungBFS();
}
