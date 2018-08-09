#include<iostream>
using namespace std;
struct CanBo
{
	long MaSo;
	char HoTen[8];
};
struct Node
{
	CanBo Info;
	Node *Next;
};
struct NganXep
{
	Node *PHead;
};
void KhoiTao(NganXep &d)
{
	d.PHead=NULL;
}
int KTRong(NganXep d)
{
	return(d.PHead==NULL);
}
void Nhap(CanBo &x)
{
	cout<<"Nhap MaSo HoTen : ";
	cin>>x.MaSo>>x.HoTen;
}
void Them(NganXep &d, CanBo x)
{
	Node *p= new Node;
	p->Info=x;
	if (KTRong(d)) 
	{
		p->Next=NULL;
		d.PHead=p;
		return;
	}
	p->Next=d.PHead;
	d.PHead=p;
}
void Xem (NganXep d)
{
	if (KTRong(d)) return;
	Node *p=d.PHead;
	while(p!=NULL)
	{
		cout<<p->Info.MaSo<<"\t"<<p->Info.HoTen<<"\n";
		p=p->Next;
	}
}
void LayRa (NganXep &d)
{
	if (KTRong(d)) return;
	Node *p=d.PHead;
	cout<<p->Info.MaSo<<"\t"<<p->Info.HoTen<<"\n";
	d.PHead=p->Next;
	delete p;	
}
int main()
{
	NganXep d; int t=1; char c; CanBo x;
	while(t)
	{
	cout<<"0. Thoat\n";
	cout<<"1. Khoi Tao\n";
	cout<<"2. Them\n";
	cout<<"3. Xem\n";
	cout<<"4. Lay Ra\n";
	cin>>c;
	switch(c)
	{
		case '0' :
			t=0;
			break;
		case '1' :
			KhoiTao(d);
			break;
		case '2' :
			Nhap(x);
			Them(d,x);
			break;
		case '3' :
			Xem(d);
			break;
		case '4' :
			LayRa(d);
			break;
	}
	}
}

