#include <stdio.h>
#include <conio.h>
#include<iostream>
#include<stdlib.h>
using namespace std;
#define false 0
#define true 1
struct node
{	int info;node *left,*right; };
node *taonode(int x)
{
	node *p=new node;
	p->info=x;
	p->left=NULL;
	p->right=NULL;return p;
};
void khoitao(node *&proot,int x)
{  proot=taonode(x);}
int ktrong(node *proot)
{	return proot==NULL; }//?
int ktla(node *p)
{	if ((p->left==NULL)&&(p->right==NULL))
	return 1;
	else
	return 0;
}
void xoacay(node *&proot)
{	if(proot!=NULL)
	{	xoacay(proot->left);
		xoacay(proot->right);
		delete proot;
		proot=NULL;
	}
}
void xoanode(node *&proot,int x)
{ if(proot==NULL) return ;
	if(proot->info==x)
	if(ktla(proot))
	{ delete proot;proot=NULL;return;	}
 if(proot->left!=NULL)
 xoanode(proot->left,x);
 if(proot->right!=NULL)
 xoanode(proot->right,x);
 return;
}
node *duyetcay(node *proot,int y)
{ node *p;
	if(proot==NULL)
	return NULL;
	if(proot->info==y)
	return proot;
	p=duyetcay(proot->left,y);
	if(p==NULL)
	p=duyetcay(proot->right,y);
	return p;
}
void themphai(node *&proot,int x,int y)
{	node *p=duyetcay(proot,y);
if(p==NULL) return ;
if(p->right!=NULL) return ;
p->right=taonode(x);
}
void themtrai(node *&proot,int x,int y)
{	node *p=duyetcay(proot,y);
if(p==NULL) return ;
if(p->left!=NULL) return ;
p->left=taonode(x);
}
// Duyet cay theo thu tu truoc NLR
void pretrav(node *proot)
{ if(proot!=NULL)
	{ printf("%5d",proot->info);
		pretrav(proot->left);
		pretrav(proot->right);
	}	
}
// Duyet cay theo thu tu giua LNR
void intrav(node *proot)
{if(proot!=NULL)
	{intrav(proot->left);
	printf("%5d",proot->info);
	intrav (proot->right);
	}
}
// Duyet cay theo thu tu sau LRN
void postrav(node *proot)
{if(proot!=NULL)
	{postrav(proot->left);
	postrav (proot->right);
		printf("%5d",proot->info);
	}
}
int main()
{ int x,y,ch;node *p, *proot,*fp;
while(true)
{ cout<<endl<<endl;
       cout<<" Binary Search Tree Operations "<<endl;
       cout<<" ----------------------------- "<<endl;
       cout<<" 1. khoi tao "<<endl;
       cout<<" 2. xoa cay "<<endl;
       cout<<" 3. them nut co noi dung x vao ben trai y "<<endl;
       cout<<" 4. them nut co noi dung x vao ben phai y "<<endl;
       cout<<" 5. Duyet cay theo thu tu truoc(NLR)"<<endl;
       cout<<" 6. Duyet cay theo thu tu giua(LNR)"<<endl;
       cout<<" 7. Duyet cay theo thu tu sau(LRN)"<<endl;
       cout<<" 8. xoa nut "<<endl;
       cout<<" 0. Exit-thoatchuongtrinh "<<endl;
       cout<<" Enter your choice : ";
		cout<<endl<<endl<<"Hay nhan phim tu 0->8	";
		cin>>ch;
		/*char chon = toupper (getch());
		if (chon=='Z') break;*/
		switch(ch)
		{
			case 0 : system("pause");
                    return 0;
                    break;
			
			case 1 :cout<<endl; 
					cout<<" khoi tao,nhap so : ";
                    cin>>x;
                    khoitao(proot,x);
                    break;
           case 2 : cout<<endl;
                    cout<<" xoa cay "<<endl;
                    cout<<" -------------------"<<endl;
                    xoacay(proot);
                    break;
           case 3 : cout<<endl;
                    cout<<" them nut x vao ben trai y "<<endl;
                    cout<<" -------------------"<<endl;
                    cin>>x>>y;
                    themtrai(proot,x,y);
                    break;
           case 4 : cout<<endl;
                    cout<<" them nut x vao ben phai y "<<endl;
                    cout<<" -------------------"<<endl;
                    cin>>x>>y;
                    themphai(proot,x,y);
                    break;
           case 5 : cout<<endl;
                    cout<<" duyet theo thu tu truoc NLR "<<endl;
                    cout<<" --------------------"<<endl;
                    pretrav(proot);
                    break;
            case 6 : cout<<endl;
                    cout<<" duyet theo thu tu giua LNR "<<endl;
                    cout<<" --------------------"<<endl;
                    intrav(proot);
                    break;
            case 7 : cout<<endl;
                    cout<<" duyet theo thu tu sau LRN "<<endl;
                    cout<<" --------------------"<<endl;
                    postrav(proot);
                    break;
           case 8 : cout<<" nhap nut can xoa : ";
                    cin>>x;
                    xoanode(proot,x);
                    break;
			
		}
}
	
}
