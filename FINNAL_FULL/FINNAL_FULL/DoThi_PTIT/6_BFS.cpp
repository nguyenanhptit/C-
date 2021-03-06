#include <conio.h>
#include <stdio.h>
#include <iostream>
#define max 100
using namespace std;
FILE *f;
int n,a[max][max],k,chuaxet[max],cay[max][2],dem=0;
typedef struct{
	int in;
	int out;
	int node[max];
}queue;
void init(queue *q) {
	q->in=q->out=-1;
}
int empty(queue *q){
	if(q->in == q->out)
		return 1;
	return 0;
}
int full(queue *q){
	if(q->in ==max-1)
		return 1;
	return 0;
}
void push(queue *q,int x) {
	if(!full(q)) {
		q->in =q->in +1;
		q->node[q->in]=x;
	}
}
int pop(queue *q){
	if(empty(q))
		return(0);
	else {
		q->out = q->out +1;
	int x=q->node[q->out];
	return x;
	}
}
void docfile() {
	int i,j;
	f=fopen("dothi6.txt","r");
	fscanf(f,"%d",&n);
	for(i=1;i<=n;i++)
	for(j=1;j<=n;j++){
		fscanf(f,"%d",&a[i][j]);
		chuaxet[j]=1;
	}
	fclose(f);
}
void caykhungBFS(){
	int i,j,h;queue q;
	init(&q);
	docfile();
	cout<<"Nhap dinh bat dau cay khung:";cin>>k;
	push(&q,k);chuaxet[k]=0;
	while(!empty(&q)){
		h=pop(&q);
		for(i=1;i<=n;i++)
			if(a[h][i]>0&&chuaxet[i]) {
		push(&q,i);chuaxet[i]=0;
			dem++;
		cay[dem][1]=h;
		cay[dem][2]=i;}
	}
	f=fopen("cay6.txt","w");
		fprintf(f,"%d ",n);fprintf(f,"%d\n",dem);
	for(i=1;i<=dem;i++){
		fprintf(f,"%d ",cay[i][1]);
		fprintf(f,"%d\n",cay[i][2]);
	}
	fclose(f);
}
int main(){
	int i;
	caykhungBFS();
}
