#include<iostream>
#include<conio.h>
using namespace std;
struct CanBo	{	long MaSo; char HoTen[8];	};
struct Node {	CanBo Info; Node *Next; };
struct NganXep {	Node *PHead; };
void KhoiTao(NganXep &d){
	d.PHead=NULL;
}
int KTRong(NganXep d){
	return(d.PHead==NULL);
}
void ThemDuLieu(NganXep &d,CanBo x){
	Node *p= new Node;
	p->Info=x;
	p->Next=NULL;
	if(KTRong(d)){
		d.PHead=p;
		return;
	}
	p->Next=d.PHead;
	d.PHead=p;
}
void LayDuLieu(NganXep &d){
	Node *q=d.PHead;
	if(KTRong(d)){
		return;
	}
	cout<<" \n "<<q->Info.MaSo<<"  "<<q->Info.HoTen;
	d.PHead= q->Next;
	delete(q);
}
void NhapCB(CanBo &x){
	cout<<" \n nhap ma so va ho ten: ";
	cin>>x.MaSo>>x.HoTen;
}
main(){
	NganXep d; CanBo x; char c;
	KhoiTao(d);
	while(1){
		cout<<"\n 0. de thoat ";
		cout<<"\n 1. Them Du Lieu";
		cout<<"\n 2. Lay Du Lieu ";
		c= getch();
		if(c== '0') break;
		if(c== '1'){
			NhapCB(x);
			ThemDuLieu(d,x);
		}
		if(c== '2'){
			LayDuLieu(d);
		}
	}
}
