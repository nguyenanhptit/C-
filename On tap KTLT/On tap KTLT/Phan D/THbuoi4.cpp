#include <stdio.h>
#include <conio.h>
#include<iostream>
#include<stdlib.h>
using namespace std;
struct node
{
	int data;
	node *left;
	node *right;
};
typedef node*tree;

void init(tree &t)
{
	t==NULL;
}

int isempty(tree t)
{
	if(t==NULL) return 1;
	else return 0;
}

node *createnode(int x)
{
	node *p=(node*) malloc(sizeof(node));
	p->data=x;
	p->left=p->right=NULL;
	return p;
}
node *insertnode(tree &t,int x)
{
	node *p=createnode(x);
	if(isempty(t)) t=p;
	else
	{
		if(t->data>x){insertnode(t->left,x);}
		else
		if(t->data<x){insertnode(t->right,x);}
	}
	return p;
}
void input(tree &t,int a[],int n)
{
	for(int i=0;i<n;i++)
	insertnode(t,a[i]);
}
void output(tree &t)
{
	if(t!=NULL)
	{
		printf("%d ",t->data);
		output(t->left);
		output(t->right);
	}
}
void NLR(tree t)
{
	if(t!=NULL)
	{
		printf("%d ",t->data);
		NLR(t->left);
		NLR(t->right);	
	}
}
void LNR(tree t)
{
	if(t!=NULL)
	{
		LNR(t->left);
		printf("%d ",t->data);
		LNR(t->right);	
	}
}
void LRN(tree t)
{
		if(t!=NULL)
	{
		LRN(t->left);
		LRN(t->right);	
		printf("%d ",t->data);
	}
}
node *searchnode(tree t,int x) //tim node x
{
	if(t!=NULL)
	{
		if(t->data==x){node *p=t;return p;}
		if(t->data>x) return searchnode(t->left,x);
		if(t->data<x) return searchnode(t->right,x);
	}
	return NULL;
}
int delnode(tree &t,int x)
{
	if(t==NULL) return 0;
	else if(t->data>x) return delnode(t->left,x);
	else if(t->data<x) return delnode(t->right,x);
	else //t->data=x
	{
		node *p=t;
		if(t->left==NULL) t=t->right; //node chi co cay con phai
		else if(t->right==NULL) t=t->left;
		else //node co ca hai
		{
			node *S=t,*Q=S->left;
			while(Q->right!=NULL)
			{
				S=Q;
				Q=Q->right;
			}
			p->data=Q->data;
			S->right=Q->left;
			delete Q;
		}
	} return 1;
}
void removeTree(tree &t)
{
	if(t!=NULL)
	{
		removeTree(t->left);
		removeTree(t->right);
		delete t;
		t=NULL;
	}
}

int main()
{
	tree t;
	t=NULL;
	int a[100]/*={5,4,7,8,3}*/;
	//int n=5;
	int n;
	printf("Nhap so phan tu \n");scanf("%d",&n);
	for (int i=0;i<n;i++)
	{
		printf("a[%d]= ",i);scanf("%d",&a[i]);
	}
	input(t,a,n);printf("Danh sach da nhap la \n");
	output(t);
	printf("\n");
	printf("duyet LNR \n");
	LNR(t);
	printf("\n");
	printf("duyet NLR \n");
	NLR(t);
	printf("\n");
	printf("duyet LRN \n");
	LRN(t);
	printf("\n");
	int x;
	printf("Nhap node ban muon tim: \n");scanf("%2d",&x);
	node *p=searchnode(t,x);
	if (p!=NULL) printf("Tim thay node %d\n",p->data);
	else printf("node %d khong co trong cay\n",x);
	printf("Nhap node ban muon xoa: \n");scanf("%2d",&x);
	if(delnode(t,x)) printf("Xoa thanh cong \n");
	else printf("Khong tim thay node %d can xoa\n",x);
	printf("Cay sau khi xoa: \n");
	output(t);printf("\n");
	removeTree(t);
	printf("Cay da huy! \n");
	output(t);
	getch();
}
