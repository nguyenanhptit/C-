#include<stdio.h>
#include<conio.h>
#include<malloc.h>
#include<string.h>
struct CanBo{
	char MaSo[5];
	char HoTen[8];
};
struct Node{
	CanBo Info;
	Node *Left, *Right;
};
typedef Node *Tree;
void init(Tree &T){
	T==NULL;
}
int isempty(Tree T){
	if(T==NULL) return 1;
	else return 0;
}
Node* createnode(CanBo x){
	Node* p=(Node*) malloc (sizeof(Node));
	p->Info=x;
	p->Left= p->Right=NULL;
	return p;
}
CanBo Nhap(CanBo &x){
	printf("Nhap MaSo HoTen: \n");
	scanf("%3s %3s", x.MaSo,x.HoTen);
}
int ChenCay(Tree &T, CanBo x){
	if(T!=NULL){
		if(strcmp(T->Info.MaSo,x.MaSo)==0) return 0;
		if(strcmp(T->Info.MaSo,x.MaSo)>0) return ChenCay(T->Left,x);
		else return ChenCay(T->Right,x);
	}
	else {
		T=(Node*) malloc(sizeof(Node));
		if(T==NULL) return -1;
		T->Info=x;
		T->Left=T->Right=NULL;
		return 1;
	}
}
void TaoCay(Tree &T){
	CanBo x; int n,i;
	printf("nhap so can bo:"); scanf("%d",&n);
	for(i=1;i<=n;i++){
		printf("nhap thong tin cho can bo thu %d; \n",i);
		Nhap(x);
		ChenCay(T,x);
	}
}
void Hienthi(CanBo x){
	printf("(%2s,%2s);", x.MaSo, x.HoTen);
}
void NLR(Tree T){
	if(T!=NULL){
		Hienthi(T->Info);
		NLR(T->Left);
		NLR(T->Right);
	}
}
void LNR(Tree T){
	if(T!=NULL){
		LNR(T->Left);
		Hienthi(T->Info);
		NLR(T->Right);
	}
}
void LRN(Tree T){
	if(T!=NULL){
		LNR(T->Left);
		NLR(T->Right);
		Hienthi(T->Info);
	}
}
Tree timkiem(Tree T, char *x){
	if(T==NULL) return NULL;
	if(strcmp(T->Info.MaSo,x)==0) return T;
	else {
		if(strcmp(T->Info.MaSo,x)==0)
		return timkiem(T->Left,x);
		else
		return timkiem(T->Right,x);
	}
}
int main(){
	int t; char c; CanBo x;
	Tree T;
	T=NULL;
	while(t){
		printf("0. Thoat\n");
		printf("1. NhapDLcay\n");
		printf("2. Duyet cay\n");
		printf("3. Tim theo ma \n");
		fflush(stdin);scanf("%c",&c);
		switch(c){
			case '0': t=0; break;
			case '1': TaoCay(T); printf("\n"); break;
			case '2': 
				NLR(T);printf("\n");
				LNR(T);printf("\n");
				LRN(T);printf("\n");
				break;
			case '3':
				Tree H;
				printf("nhap ma tim kiem");
				scanf("%3s",x.MaSo);
				H=timkiem(T,x.MaSo);
				Hienthi(H->Info);
				printf("\n");
				break;
		}
	}
}
