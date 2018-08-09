//A.1
#include <iostream>
#include <stdio.h>
#include <conio.h>
using namespace std;
struct CanBo { long MaSo; char HoTen[8];};
struct Node { CanBo InFo; Node *Next; };
struct DanhSach { Node *PFirst, *PLast ;};
void KhoiTao(DanhSach &d)
	{d.PFirst=d.PLast=NULL;}
int KTRong(DanhSach d)
	{ return d.PFirst==NULL;}
void Themdau(DanhSach &d, CanBo x)
{ 	Node *p=new Node;
	p->InFo=x;p->Next=NULL;
	if (KTRong(d))
	{ d.PFirst=d.PLast=p; return;	}
	p->Next=d.PFirst;
	d.PFirst=p;
}	
void ThemCuoi(DanhSach &d, CanBo x)
	{Node *p=new Node;
	p->InFo=x;p->Next=NULL;
	if (KTRong(d))
	{ d.PFirst=d.PLast=p; return;	}
	d.PLast->Next=p;
	d.PLast=p;
	}
void themsauk(DanhSach &d, CanBo x)
{		
	Node *p=new Node;
	p->InFo=x;p->Next=NULL;
	if (KTRong(d))
	{ d.PFirst=d.PLast=p; return;	};
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
	{ d.PFirst=d.PLast=p; return;	};
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
	if(d.PFirst==d.PLast)		{delete d.PFirst;d.PFirst=d.PLast=NULL;}
	else
{Node *p=d.PFirst;
d.PFirst=d.PFirst->Next;
delete p;
if (d.PFirst==NULL) d.PLast=NULL;}
}
void XoaCuoi(DanhSach &d)
{ if(KTRong(d)) return;
if(d.PFirst==d.PLast)		{delete d.PFirst;d.PFirst=d.PLast=NULL;}
else
{Node *p=d.PFirst;
 while(p->Next!=d.PLast) p=p->Next;
delete d.PLast;
d.PLast=p;d.PLast->Next=NULL;
}}
void xoak(DanhSach &d)
{	int k,m=1;
	cout<<"\n Nhap vi tri k \n";cin>>k;
	if (k==1) 	{
				if(d.PFirst==d.PLast)		{delete d.PFirst;d.PFirst=d.PLast=NULL;}
				else
				{Node *p = d.PFirst;
	 				Node *q =d.PFirst->Next;
	 				d.PFirst=q;
   				delete p;
				}}
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
   d.PFirst=d.PLast = NULL;
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
int main()
{ DanhSach d; CanBo x;
	KhoiTao(d);
	int g;
	cout<<"nhap tong so can bo  ";cin>>g;
	if(g>=0)
	{
	for(int i=0;i<g;i++){
	NhapCanBo(x);ThemCuoi(d,x);
	}}
	Xem(d);
	xoak(d);Xem(d);
	//NhapCanBo(x);themsauk(d,x);Xem(d);
	//NhapCanBo(x);themtruock(d,x);Xem(d);
	//XoaCuoi(d);Xem(d);
	//cout<<"\n danh sach sau khi xoa \n";Xoacads(d);Xem(d);
	//NhapCanBo(x);Themdau(d,x);Xem(d);
	//XoaDau(d);	Xem(d);
	
}
	//Node* timgiatri(List list, int key){ Node *i = list.head;while (i && i->info != key)i = i->next;return i;}
	
	


