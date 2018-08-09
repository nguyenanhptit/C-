 //A.2
#include <iostream>
#include <stdio.h>
#include <conio.h>
using namespace std;
struct CanBo { long MaSo; char HoTen[8];};
struct Node { CanBo InFo; Node *Next; };
struct DanhSach { Node *PFirst ;};
void KhoiTao(DanhSach &d)
	{d.PFirst=NULL;}
int KTRong(DanhSach d)
	{ return d.PFirst==NULL;}
void Themdau(DanhSach &d, CanBo x)
{ 	Node *p=new Node;
	p->InFo=x;p->Next=NULL;
	if (KTRong(d))
	{ d.PFirst=p; return;	}
	p->Next=d.PFirst;
	d.PFirst=p;
}	
void ThemCuoi(DanhSach &d, CanBo x)
	{Node *p=new Node;
	p->InFo=x;p->Next=NULL;
	if (KTRong(d))
	{ d.PFirst=p; return;	}
	Node *i = d.PFirst;
   	while (i && i->Next != NULL)
      i = i->Next;
	i->Next=p;
	
	} 
void themsauk(DanhSach &d, CanBo x)
{		
	Node *p=new Node;
	p->InFo=x;p->Next=NULL;
	if (KTRong(d))
	{ d.PFirst=p; return;	};
	int k,m=1;
	cout<<"\n Nhap vi tri k \n";cin>>k;
	Node *q=d.PFirst;
 	while(m<k) {q=q->Next;m++;}
	p->Next = q->Next; 
    q->Next = p;
	
	
	
}	
void themtruock(DanhSach &d, CanBo x)
{		
	Node *p=new Node;
	p->InFo=x;p->Next=NULL;
	if (KTRong(d))
	{ d.PFirst=p; return;	};
	int k,m=1;
	cout<<"\n Nhap vi tri k \n";cin>>k;
	if(k==1) {p->Next=d.PFirst;d.PFirst=p;}
	else
	{Node *q=d.PFirst;
 	while(m<k-1) {q=q->Next;m++;}
	p->Next = q->Next; 
    q->Next = p;
}	
	
	
}	
void XoaDau(DanhSach &d)
{ if(KTRong(d)) return;
   	int m=0;
	   Node *i = d.PFirst;
   	while (i && i->Next != NULL)
      {i = i->Next;m++;}
	if(m==0)		{delete d.PFirst;d.PFirst=NULL;}
	else
	{
		Node *p=d.PFirst;
		d.PFirst=d.PFirst->Next;
		delete p;
	}
}
void XoaCuoi(DanhSach &d)
{ if(KTRong(d)) return;
	int m=0;
	Node *i = d.PFirst;Node *p=d.PFirst;
   	while (i && i->Next != NULL)
      {p=i;i = i->Next;m++;}
     if(m==0)		{delete d.PFirst;d.PFirst=NULL;} 
else
{
 delete i;
 p->Next=NULL;

}}
void xoak(DanhSach &d)
{	int k,m=1;
	cout<<"\n Nhap vi tri k \n";cin>>k;
	if (k==1) 	{
				//if(d.PFirst->Next=NULL)		{delete d.PFirst;d.PFirst=NULL;}
				
				Node *p = d.PFirst;
	 				Node *q =d.PFirst->Next;
	 				d.PFirst=q;
   				delete p;
				}
	else
	{Node *p = d.PFirst;
	 Node *q =d.PFirst->Next;
   while (m<k-1)
   {
      p = p->Next;
      q=q->Next;
      m++;
   }
   p->Next=q->Next;
   delete q;
	}
	}
void Xoacads(DanhSach &d)
{
   Node *p = d.PFirst;
   while (d.PFirst!=NULL)
   {
      p = p->Next;
      delete d.PFirst;
      d.PFirst = p;
   }
   d.PFirst=NULL;
}

void Xem(DanhSach d)
	{ if (KTRong(d)) {cout<<"\n danh sach rong";return;}
	Node *p=d.PFirst;
	cout<<"\n danh sach la \n";
	while (p!=NULL)
	{ cout<<"\n "<<p->InFo.MaSo<<" "<<p->InFo.HoTen;
	p=p->Next;
	}
	}
void NhapCanBo(CanBo &x)
{ cout<<"\n Nhap Ma so, Ho ten=";
	cin>>x.MaSo>>x.HoTen;
}
void timkey(DanhSach d)
{	int y,m=0;
	cout<<"\n Nhap Ma so can bo can tim =\n";
	cin>>y; /*cout<<" y la"<<y;*/
	Node *i=d.PFirst;
	//if(i->InFo.MaSo==y ) cout<<"\n Can bo do la "<<i->InFo.HoTen; 
	
	while (i->Next!=NULL && i->InFo.MaSo!=y){i = i->Next;}
	if(i==NULL) cout<<"\n Khong co ket qua tim kiem";
	else 
	{
	if(i->InFo.MaSo==y ) cout<<"\n Can bo do la "<<i->InFo.HoTen; 
	else cout<<"\n Khong co ket qua tim kiem";

	}
}
int main()
{ DanhSach d; CanBo x;
	KhoiTao(d);
	int g;
	cout<<"nhap tong so can bo  ";cin>>g;
	if(g>=0)
	{
	for(int i=0;i<g;i++){
	NhapCanBo(x);//Themdau(d,x);
	ThemCuoi(d,x);
	}}
	Xem(d);
	xoak(d);Xem(d);
	//NhapCanBo(x);themsauk(d,x);Xem(d);
	//NhapCanBo(x);themtruock(d,x);Xem(d);
	//XoaCuoi(d);Xem(d);
	//cout<<"\n danh sach sau khi xoa \n";Xoacads(d);Xem(d);
	//NhapCanBo(x);Themdau(d,x);Xem(d);
	//XoaDau(d);	Xem(d);
	//timkey(d);
} 
	//Node* timgiatri(List list, int key){ Node *i = list.head;while (i && i->info != key)i = i->next;return i;}
	
	


