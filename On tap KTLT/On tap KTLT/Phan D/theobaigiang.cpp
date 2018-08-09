#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
//#include <alloc.h>
#include<iostream>
#include <string.h>
#include <dos.h>
#define TRUE 1
#define FALSE 0
#define MAX 100
struct node {
int infor;
struct node *left;
struct node *right;
};
typedef struct node *NODEPTR;
NODEPTR Getnode(void){
NODEPTR p;
p=(NODEPTR)malloc(sizeof(struct node));
return(p);
}
void Freenode(NODEPTR p){
free(p);
}
void Initialize(NODEPTR *ptree){
*ptree=NULL;
}
NODEPTR Makenode(int x){
NODEPTR p;
p=Getnode();
p->infor=x;
p->left=NULL;
p->right=NULL;
return(p);
}
void Setleft(NODEPTR p, int x){
if (p==NULL)
printf("\n Node p khong co thuc");
else {
if (p->left!=NULL)
printf("\n Node con ben trai da ton tai");
else
p->left=Makenode(x);
}
}
void Setright(NODEPTR p, int x){
if (p==NULL)
printf("\n Node p khong co thuc");
else {
if (p->right!=NULL)
printf("\n Node con ben phai da ton tai");
else
p->right=Makenode(x);
}
}
void Pretrav(NODEPTR proot){
if (proot!=NULL){
printf("%5d", proot->infor);
Pretrav(proot->left);
Pretrav(proot->right);
}
}
void Intrav(NODEPTR proot){
if (proot!=NULL){
Intrav(proot->left);
printf("%5d", proot->infor);
Intrav(proot->right);
}
}
void Postrav(NODEPTR proot){
if (proot!=NULL){
Postrav(proot->left);
Postrav(proot->right);
printf("%5d", proot->infor);
}
}
void Insert(NODEPTR proot, int x){
if (x==proot->infor){
printf("\n Noi dung bi trung");
/*delay(2000);*/return;
}
else if(x<proot->infor && proot->left==NULL){
Setleft(proot,x);return;
}
else if (x>proot->infor && proot->right==NULL){
Setright(proot,x);return;
}
else if(x<proot->infor)
Insert(proot->left,x);
else Insert(proot->right,x);
}
NODEPTR Search(NODEPTR proot, int x){
NODEPTR p;p=proot;
if (p!=NULL) {
if (x <proot->infor)
p=Search(proot->left,x);
else if(x>proot->infor)
p=Search(proot->right,x);
}
return(p);
}
NODEPTR Remove(NODEPTR p){
NODEPTR rp,f;
if(p==NULL){
printf("\n Nut p khong co thuc");
/*delay(2000);*/return(p);
}
if(p->right==NULL)
rp=p->left;
else {
if (p->left==NULL)
rp = p->right;
else {
	f=p;
rp=p->right;
while(rp->left!=NULL){
f=rp;
rp=rp->left;
}
if(f!=p){
f->left =rp->right;
rp->right = p->right;
rp->left=p->left;
}
else
rp->left = p->left;
}
}
Freenode(p);
return(rp);
}
void Cleartree(NODEPTR proot){
if(proot!=NULL){
Cleartree(proot->left);
Cleartree(proot->right);
Freenode(proot);
}
}
int main(){
NODEPTR ptree, p;
int noidung, chucnang;
Initialize(&ptree);
do {
//clrscr();
printf("\n CAY NHI PHAN TIM KIEM");
printf("\n 1-Them nut tren cay");
printf("\n 2-Xoa node goc");
printf("\n 3-Xoa node con ben trai");
printf("\n 4-Xoa node con ben phai");
printf("\n 5-Xoa toan bo cay");
printf("\n 6-Duyet cay theo NLR");
printf("\n 7-Duyet cay theo LNR");
printf("\n 8-Duyet cay theo LRN");
printf("\n 9-Tim kiem tren cay");
printf("\n 0-Thoat khoi chuong trinh");
printf("\n Lua chon chuc nang:");
scanf("%d", &chucnang);
switch(chucnang){
case 1:
printf("\n Noi dung nut moi:");
scanf("%d",&noidung);
if(ptree==NULL)
ptree=Makenode(noidung);
else
Insert(ptree,noidung);
break;
case 2:
if (ptree==NULL)
printf("\n Cay bi rong");
else
ptree=Remove(ptree);
break;
case 3:
printf("\n Noi dung node cha:");
scanf("%d", &noidung);
p=Search(ptree,noidung);
if (p!=NULL)
p->left = Remove(p->left);
else
printf("\n Khong co node cha");
break;
case 4:
printf("\n Noi dung node cha:");
scanf("%d", &noidung);
p=Search(ptree,noidung);
if (p!=NULL)
p->right = Remove(p->right);
else
printf("\n Khong co node cha");
break;
case 5:
Cleartree(ptree);
break;
case 6:
printf("\n Duyet cay theo NLR");
if(ptree==NULL)
printf("\n Cay rong");
else
Pretrav(ptree);
break;
case 7:
printf("\n Duyet cay theo LNR");
if(ptree==NULL)
printf("\n Cay rong");
else
Intrav(ptree);
break;
case 8:
printf("\n Duyet cay theo LRN");
if(ptree==NULL)
printf("\n Cay rong");
else
Postrav(ptree);
break;
case 9:
printf("\n Noi dung can tim:");
scanf("%d",&noidung);
if(Search(ptree,noidung))
printf("\n Tim thay");
else
printf("\n Khong tim thay");
break;
}
//delay(1000);
} while(chucnang!=0);
Cleartree(ptree); ptree=NULL;
}
