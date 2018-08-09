#include <stdlib.h>
#include <iostream>
using namespace std;
struct CanBo {
	int Maso;
	char Hoten [8];
};
struct Node {
	CanBo info;
	Node *Next;
};
struct danhsach {
	Node *pfirst, *plast;
};
void khoitao (danhsach &d){
	d.pfirst = NULL;
	d.plast = NULL;
}
int ktrarong (danhsach d){
	return (d.pfirst == NULL);
}
void nhapCanBo (CanBo &x){
	cout << "Ma can bo:";
	cin >> x.Maso;
	fflush (stdin);
	cout <<"\nHo va ten:";
	cin>>x.Hoten;
}
Node *MakeNode (CanBo x){
	Node *p= new Node;
	p->info =x;
	return p;
}
int DemCB (danhsach d){
	Node *p=d.pfirst;
	int dem=0;
	while (p!=NULL){
		p=p->Next;
		dem ++;
	}
	return dem;
}
void xem (danhsach d){
	if (ktrarong (d)) return ;
	Node *p= d.pfirst;
	cout << "=======================";
	cout <<"\nDanh sach can bo vua nhap:";
	while (p!= NULL){
		cout <<"\n"<<p->info.Maso<< " "<<p->info.Hoten<<"\n\n"; 
		p=p->Next;
	}
	cout << "===========================\n";
}
//=======================================
// cac thao tac them 
//=======================================
void Themdau ( danhsach &d, CanBo x){
	nhapCanBo (x);
	if(d.pfirst==NULL){// chua co phan tu duoc them vao dau
		Node *p= MakeNode (x);
		p->Next= NULL;
		d.pfirst=d.plast=p;
	}else{
		Node *p= MakeNode (x);
		p->Next= d.pfirst;
		d.pfirst=p;
	}
}

void Themcuoi (danhsach &d, CanBo x){
	nhapCanBo (x);
	Node *p= MakeNode (x);
	if(d.pfirst==NULL){
		p->Next=NULL;
		d.pfirst=d.plast=p;
	}else{
		p->Next=NULL;
		d.plast->Next=p;
		d.plast=p;
	}
}
void ThemtrcK (danhsach &d, int k){
	CanBo x;
	cout <<" Nhap vi tri K:";
	cin >>k;
	int i=1;
	if (ktrarong (d)) { cout<< "danh sach rong";
						return ;}
	else {
		if (k==1){
			Themdau (d,x);
			return;
		}
		else {
			Node *p=MakeNode (x);
			Node *q= d.pfirst;
			while ((q->Next != NULL)&& (i<k-1)){
				i++;
				q=q->Next;
			}
	p->Next= q->Next;
	q->Next=p;
	}
}
}
void Themsauk (danhsach &d, int k){
	if (k<0|| k>DemCB (d)) return ;
	CanBo x;
	cout<< " nhap k:";
	cin >> k;
	nhapCanBo (x);
	if (k==0){
		Themdau (d,x);
		return ;
	}
	Node *q=d.pfirst;
	for (int i=1; i<k; i++)
		q=q->Next;
	if (q->Next==NULL){
		Themcuoi (d,x);
		return ;
	}
	Node *p= MakeNode (x);
	p->Next=q->Next;
	q->Next=p;
}
//==================================
// Cac thao tac xoa
//============================
void XoaDau (danhsach &d){
	if (ktrarong (d)) return ;
	Node *p=d.pfirst;
	d.pfirst=p->Next;
	delete p;
	if (d.pfirst==NULL) d.plast=NULL;
}
void XoaCuoi (danhsach &d){
	if (ktrarong (d)) return ;
	CanBo x;
 	Node *p=d.pfirst;
 	if (p->Next==NULL){
 		delete p;
 		khoitao (d);
 		return;
	}
	Node *q = new Node;
 	while (p->Next != NULL){
 		q=p;
 		p=p->Next;
	 }
	q->Next= NULL;
	d.plast=q;
	delete p;
}
void XoaPhantuK (danhsach &d,int k){
	cout << " Nhap k";
	if (ktrarong (d)) {
		cout << " k co phan tu de xoa\n";
		return ;
	}
	else {
		cout << " nhap vi tri can xoa:";
		cin >> k;
		if (k<0 || k>DemCB (d)) {
			cout<< " k co ptu de xoa"<<endl;
			return;
		}
		if (k==1) {
			XoaDau (d);
			return;
		}
		if (k== DemCB (d)){
			XoaCuoi (d);
			return;
		}
		else {
			int i=1;
			Node *p = d.pfirst ;
			Node *q;
			while ( (p->Next != NULL) && i<k){
				i++;
				q=p;
				p=p->Next;
			}
			q->Next=p->Next;
			delete p;
		}
	}
}
void XoaALL (danhsach &d){
	Node *p=d.pfirst->Next;
	while (d.pfirst!=NULL){
		p=p->Next;
		delete d.pfirst;
		d.pfirst=p;
	}
}
void TimthemMS (danhsach d){
	if (ktrarong (d)){
		cout <<" Danh sach rong ";
		return;
	}
	int MS, dem=0;
	cout << " Nhap ma so can tim:";
	cin >> MS;
	Node *p=d.pfirst;
	while (p!= NULL){
		if (p->info.Maso ==MS){
			cout <<" Ma so:"<< p->info.Maso;
			cout <<" Ho ten:"<< p->info.Hoten<<endl;
			p=p->Next;
		}
		else dem++;
		if (dem== DemCB (d)){
			cout <<" k co can bo nao";
			return;
		}
	}
}
main (){
	danhsach d;
	char c;
	CanBo x;
	int k;
	khoitao(d);
	while (1){
		cout <<"0. Thoat \n";
		cout <<"1. khoi tao\n";
		cout <<"2. Them dau\n";
		cout <<"3. Them cuoi \n";
		cout <<"4. Them truwoc k \n";
		cout <<"5. Them sau k\n";
	    cout <<"6. xoa dau\n";
	    cout <<"7. Xoa cuoi \n";
	    cout <<"8. xoa phan tu K\n";
	    cout <<"9. Xoa tat ca \n";
	    cout <<"10-a. Tim theo ma so \n";
		cout <<"11-b. xem\n";
		fflush (stdin);
		cin>> c;
		switch (c){
			case '0':   break;
			case '1':   khoitao (d);
						break;
			case '2':   Themdau (d,x);
						break;
			case '3': 	Themcuoi (d,x);
						break;
			case '4': 	ThemtrcK (d,k);
						break;
			case '5':	Themsauk (d,k);
						break;
			case '6': 	XoaDau (d);
						break;
			case '7':	XoaCuoi (d);
						break;
			case '8': 	XoaPhantuK (d,k);
						break;
			case '9':	XoaALL (d);
						break;
			case 'a': 	TimthemMS(d);
						break;
			case 'b':  xem(d);
						break;
			default:{
				cout<<"no";
				break;
			}
		}
	}
}
