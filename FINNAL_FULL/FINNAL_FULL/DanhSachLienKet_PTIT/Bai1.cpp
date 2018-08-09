#include<conio.h>
#include<iostream>
using namespace std;
struct CanBo	{	long MaSo; char HoTen[8];	};
struct Node {	CanBo Info; Node *Next; };
struct DanhSach {	Node *PFirst, *PLast; };
void KhoiTao(DanhSach &d){
	d.PFirst=d.PLast=NULL;
}
int KTRong(DanhSach d){
	return(d.PFirst==NULL);
}
int DemCB(DanhSach d){
	int i=0;
	Node *p=d.PFirst;
	while(p!=NULL){
		p=p->Next;
		i++;
	}
	return i;
}
void ThemDau(DanhSach &d, CanBo x){
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
void ThemCuoi(DanhSach &d, CanBo x){
	Node *p = new Node;
	p->Info=x;
	p->Next= NULL;
	if(KTRong(d)){
		d.PFirst=d.PLast=p;
		return;
	}
	d.PLast->Next=p;
	d.PLast=p;
}
void ThemSauK(DanhSach &d, CanBo x){
	int k;
	cout<<"\n nhap vi tri: ";
	cin>> k;
	if(k<1 || k> DemCB(d)) return;
	Node *q=d.PFirst;
	if(k==DemCB(d)){
		ThemCuoi(d,x);
		return;
	}
	for(int i=1 ; i<k;i++){
		q=q->Next;
	}
	Node *p = new Node;
	p->Info=x;
	p->Next= q->Next;
	q->Next=p;
}
void ThemTruocK(DanhSach &d, CanBo x){
	int k;
	cout<<"\n nhap vi tri: ";
	cin>>k;
	if(k<1 || k> DemCB(d)) return;
	Node *q=d.PFirst;
	if(k==1){
		ThemDau(d,x);
		return;
	}
	for(int i=1; i< k-1; i++){
		q=q->Next;
	}
	Node *p= new Node;
	p->Info=x;
	p->Next= q->Next;
	q->Next=p;
}
void XoaDau(DanhSach &d){
	if(KTRong(d)){
		return;
	}
	Node *p=d.PFirst;
	d.PFirst=p->Next;
	delete(p);
	if(d.PFirst==NULL){
		d.PLast=NULL;
	}
}
void XoaCuoi(DanhSach &d){
	if(KTRong(d)){
		return;
	}
	if(d.PFirst->Next == NULL){
		XoaDau(d);
		return;
	}
	Node *p;
	for(Node *k=d.PFirst; k!=NULL; k=k->Next){
		if(k==d.PLast){
			d.PLast=p;
			d.PLast->Next=NULL;
			delete(k);
			return;
		}
		p=k;
	}	
}
void XoaK(DanhSach &d){
	int k;
	cout<<"\n nhap vi tri K: ";
	cin>>k;
	if( k<1 || k> DemCB(d)) return;
	if(k==1){
		XoaDau(d);
		return;
	}
	if(k==DemCB(d)){
		XoaCuoi(d);
		return;
	}
	Node *p, *q=d.PFirst;
	for(int i=1; i<k; i++){
		p=q;
		q=q->Next;
	}
	p->Next=q->Next;
	delete(q);
}
void XoaDS(DanhSach &d){
	if(KTRong(d)) return;
	Node *p=d.PFirst;
	while(d.PFirst!= NULL){
		p =p->Next;
		delete(d.PFirst);
		d.PFirst=p;
	}
	d.PLast=NULL;
}
void TimMS(DanhSach d){
	long MS;
	cout<<" \nnhap ma so";
	cin>>MS;
	Node *p=d.PFirst;
	while(p!=NULL){
		if(p->Info.MaSo==MS){
			cout<<"\n "<<p->Info.MaSo << "  "<<p->Info.HoTen;
			return;
		}
		p= p->Next;
	}
}
void Xem(DanhSach d){
	Node *p= d.PFirst;
	if(KTRong(d)){
		return;
	}
	while(p!=NULL){
		cout<< "\n "<< p->Info.MaSo <<" "<<p->Info.HoTen;
		p=p->Next;
	}
}
void NhapCB(CanBo &x){
	cout<< " \n nhap ho ten va ma so ";
	cin>> x.MaSo >> x.HoTen;
}
main(){
	DanhSach d; CanBo x; char c;
	KhoiTao(d);
	while(1){
		cout<<" \0 thoat";
		cout<< " \n1. Them Dau";
		cout<< " \n2. Them Cuoi";
		cout<<"\n3. Them sau K";
		cout<< "\n4. Them Truoc K";
		cout<< "\n5. Xoa Dau";
		cout<<"\n6. Xoa Cuoi";
		cout<<"\n7. Xoa vi tri K ";
		cout<<"\n8. Xoa toan bo danh sach ";
		cout<< " \n9. xem";
		cout<< " \nX. Tim can bo theo ma so";
		c= getch();
		if(c== '0') break;
		if(c== '1'){
			NhapCB(x);
			ThemDau(d,x);	
		}
		if(c== '2'){
			NhapCB(x);
			ThemCuoi(d,x);	
		}
		if(c=='3'){
			NhapCB(x);
			ThemSauK(d,x);
		}
		if(c=='4'){
			NhapCB(x);
			ThemTruocK(d,x);
		}
		if(c=='5'){
			XoaDau(d);
		}
		if(c=='6'){
			XoaCuoi(d);
		}
		if(c=='7'){
			XoaK(d);
		}
		if(c=='8'){
			XoaDS(d);
		}
		if(c=='9'){
			Xem(d);
		}
		if(c=='x'){
			TimMS(d);
		}
	}
}












