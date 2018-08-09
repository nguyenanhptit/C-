
#include<iostream>
using namespace std;
struct CanBo 
{
	long MaSo; char HoTen[8];
};
struct Node
{
	CanBo Info; Node *Next, *Pre;
};
struct DanhSach
{
	Node *PFirst,*PLast;
};
void KhoiTao(DanhSach &d)
{
	d.PFirst=d.PLast=NULL;
}
int KTRong(DanhSach d)
{
	return (d.PFirst==NULL);
}
void Nhap(CanBo &x)
{
	cout<<"Nhap MaSo HoTen : ";
	cin>>x.MaSo>>x.HoTen;
}
void NhapK(int &k)
{
	cout<<"Nhap k : ";
	cin>>k;
}
Node *MakeNode(CanBo x)
{
	Node *p = new Node;
	p->Info=x;
	return p;
}
void ThemDau(DanhSach &d,CanBo x)
{	
	Node *p = MakeNode(x);
	p->Next=d.PFirst; p->Pre=NULL;
	if (KTRong(d))
	{
		d.PFirst=d.PLast=p;
		return;
	}
	d.PFirst->Pre=p;
	d.PFirst=p;
}
void Xem(DanhSach d)
{
	if (KTRong(d)) return;
	Node *p=d.PFirst;
	while(p!=NULL)
	{
		cout<<p->Info.MaSo<<"\t"<<p->Info.HoTen<<"\n";
		p=p->Next;
	}
}
void ThemCuoi(DanhSach &d,CanBo x)
{
	Node *p = MakeNode(x); p->Pre=d.PLast; p->Next=NULL;
	if (KTRong(d))
	{
		d.PFirst=d.PLast=p;
		return;
	}
	d.PLast->Next=p;
	d.PLast=p;
}
int DemCB(DanhSach d)
{
	int dem=0;
	Node *p=d.PFirst;
	while(p!=NULL)
	{
		p=p->Next;
		dem++;
	}
	return dem;
}
void ThemSauK(DanhSach &d,int k)
{	
	if (k<0||k>DemCB(d)) return;
	CanBo x;
	Nhap(x);
	if (k==0) 
	{
		ThemDau(d,x);
		return;
	}
	Node *q=d.PFirst;
	for (int i=1;i<k;i++) q=q->Next;
	if (q->Next==NULL)
	{
		ThemCuoi(d,x);
		return;
	}
	Node *p=MakeNode(x);
	p->Next=q->Next; p->Pre=q;
	q->Next->Pre=p; q->Next=p;
}
void XoaDau(DanhSach &d)
{
	if(KTRong(d)) return;
	Node *p=d.PFirst;
	if (p->Next==NULL)
	{
		delete p;
		d.PFirst=d.PLast=NULL;
		return;
	}
	p->Next->Pre=NULL;
	d.PFirst=p->Next;
	delete p;	
}
void XoaCuoi(DanhSach &d)
{
	if (KTRong(d)) return;
	Node *p=d.PLast;
	if (p->Pre==NULL)
	{
		delete p;
		d.PFirst=d.PLast=NULL;
		return;
	}
	/*p->Pre->Next=NULL;
	d.PLast=p->Pre;
	delete p;*/
	d.PLast=p->Pre;
	delete p;
	d.PLast->Next=NULL;
}
void XoaK(DanhSach &d,int k)
{
	if (k<=0||k>DemCB(d)) return;
	if(k==1)
	{
		XoaDau(d);
		return;
	}
	Node *p=d.PFirst;
	for (int i=1;i<k;i++) p=p->Next;
	if (p->Next==NULL) 
	{
		XoaCuoi(d);
		return;
	}
	p->Pre->Next=p->Next;
	p->Next->Pre=p->Pre;
	delete p;
}
void XoaDS(DanhSach &d)
{
	if (KTRong(d)) return;
	Node *p=d.PFirst,*q;
	while(p!=NULL) 
	{
		q=p;
		p=p->Next;
		delete q;
	}
	d.PFirst=d.PLast=NULL;
}
void TimTheoMS(DanhSach d)
{
	long MS;
	cout<<"Nhap MaSo : ";
	cin>>MS;
	Node *p=d.PFirst;
	while(p!=NULL)
	{
		if (p->Info.MaSo==MS) cout<<p->Info.MaSo<<"\t"<<p->Info.HoTen<<"\n";
		p=p->Next;
	}
}
int main()
{
	DanhSach d; int t=1; char c; CanBo x; int k;
	while (t)
	{
		cout<<"0. Thoat\n";
		cout<<"1. Khoi Tao\n";
		cout<<"2. Them Dau\n";
		cout<<"3. Xem\n";
		cout<<"4. Them Cuoi\n";
		cout<<"5. Them Sau Vi Tri K\n";
		cout<<"6. Them Truoc Vi Tri K\n";
		cout<<"7. Xoa Dau\n";
		cout<<"8. Xoa Cuoi\n";
		cout<<"9. Xoa Vi Tri K\n";
		cout<<"X. Xoa Danh Sach\n";
		cout<<"S. Tim Can Bo Theo Ma So\n";
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
				ThemDau(d,x);
				break;
			case '3' :
				Xem(d);
				break;
			case '4' :
				Nhap(x);
				ThemCuoi(d,x);
				break;
			case '5' :
				NhapK(k);
				ThemSauK(d,k);
				break;
			case '6' :
				NhapK(k);
				ThemSauK(d,k-1);
				break;
			case '7' :
				XoaDau(d);
				break;
			case '8' :
				XoaCuoi(d);
				break;
			case '9' :
				NhapK(k);
				XoaK(d,k);
				break;
			case 'x' :
				XoaDS(d);
				break;
			case 's' :
				TimTheoMS(d);
				break;
		}		
	}
}

