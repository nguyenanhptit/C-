#include<iostream>
#include<conio.h>
using namespace std;
struct CanBo	{	long MaSo; char HoTen[8];	};
struct Node {	CanBo Info; Node *Next; };
struct HangDoi {	Node *PFirst, *PLast; };
void KhoiTao(HangDoi &d){
	d.PFirst=d.PLast=NULL;
}
int KTRong(HangDoi d){
	return(d.PFirst==NULL);
}
void ThemDuLieu(HangDoi &d, CanBo x){
	Node *p = new Node;
	p->Info=x;
	p->Next= NULL;
	if(KTRong(d)){
		d.PFirst=d.PLast=p;
		return;
	}
	p->Next=d.PFirst;
	d.PFirst=p;
}
void LayDuLieu(HangDoi &d){
	if(KTRong(d)){
		return;
	}
	if(d.PFirst->Next == NULL){
		cout<<"\n  "<<d.PFirst->Info.MaSo<<"  "<<d.PLast->Info.HoTen;
		delete(d.PFirst);
		d.PFirst=d.PLast=NULL;
		return;
	}
	Node *p;
	for(Node *k=d.PFirst; k!=NULL; k=k->Next){
		if(k==d.PLast){
			d.PLast=p;
			d.PLast->Next=NULL;
			cout<<"\n  "<<k->Info.MaSo<<"  "<<k->Info.HoTen;
			delete(k);
			return;
		}
		p=k;
	}	
}
void NhapCB(CanBo &x){
	cout<< " \n nhap ho ten va ma so ";
	cin>> x.MaSo >> x.HoTen;
}
main(){
	HangDoi d; CanBo x; char c;
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
