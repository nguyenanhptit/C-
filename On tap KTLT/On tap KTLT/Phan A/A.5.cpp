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
struct HangDoi
{
	Node *PFirst,*PLast;
};
void KhoiTao(HangDoi &d)
{
	d.PFirst=d.PLast=NULL;
}
int KTRong(HangDoi d)
{
	return(d.PFirst==NULL);
}
void Nhap(CanBo &x)
{
	cout<<"Nhap MaSo HoTen : ";
	cin>>x.MaSo>>x.HoTen;
}
void Them(HangDoi &d,CanBo x)
{
	Node *p = new Node;
	p->Info=x;p->Next=d.PFirst;
	if (KTRong(d))
	{
		d.PFirst=d.PLast=p;
		return;
	}
	d.PFirst=p;
}
void Xem(HangDoi d)
{
	if (KTRong(d)) return;
	Node *p=d.PFirst;
	while(p!=NULL)
	{
		cout<<p->Info.MaSo<<"\t"<<p->Info.HoTen<<"\n";
		p=p->Next;
	}
}
void LayRa(HangDoi &d)
{
	if (KTRong(d)) return;
	Node *p=d.PFirst,*q;
	if(p->Next==NULL)
	{	
		cout<<p->Info.MaSo<<"\t"<<p->Info.HoTen<<"\n";
		delete p;
		d.PFirst=d.PLast=NULL;
		return;
	}
	while (p->Next!=NULL)
	{
		q=p;
		p=p->Next;
	}
	q->Next=NULL;
	d.PLast=q;
	cout<<p->Info.MaSo<<"\t"<<p->Info.HoTen<<"\n";
	delete p;
}
int main()
{
	HangDoi d; int t=1; char c; CanBo x;
	while (t)
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

