#include<iostream>
#include<conio.h>
using namespace std;
struct CanBo	{	long MaSo; char HoTen[8];	};
struct Node {	CanBo Info; Node *Next; };
struct DanhSach {	Node *PFirst; };

void KhoiTao(DanhSach &d){
	d.PFirst=NULL;
}
int KTRong(DanhSach d){
	return(d.PFirst==NULL);
}
int DemCB(DanhSach d){
	int i=0;
	Node *q=d.PFirst;
	while(q!=NULL){
		q=q->Next;
		i++;
	}
	return i;
}
void ThemDau(DanhSach &d,CanBo x){
	Node *p= new Node;
	p->Info=x;
	p->Next=NULL;
	if(KTRong(d)){
		d.PFirst=p;
		return;
	}
	p->Next=d.PFirst;
	d.PFirst=p;
}
void ThemCuoi(DanhSach &d, CanBo x){
	Node *p= new Node;
	Node *Plast=d.PFirst;
	p->Info=x;
	p->Next=NULL;
	if(KTRong(d)){
		d.PFirst=p;
		return;
	}
	while(Plast->Next != NULL){
		Plast=Plast->Next;
	}
	Plast->Next=p;	
}
void ThemSauK(DanhSach &d, CanBo x){
	int k;
	cout<<"\n nhap vi tri them : ";
	cin>>k;
	if(k<1 || k> DemCB(d)) return;
	if(k==DemCB(d)){
		ThemCuoi(d,x);
		return;
	}
	Node *q=d.PFirst;
	for(int i=1; i<k;i++){
		q= q->Next;
	}
	Node *p= new Node;
	p->Info=x;
	p->Next=q->Next;
	q->Next=p;
}
void ThemTruocK(DanhSach &d, CanBo x){
	int k;
	cout<<"\n nhap vi tri them : ";
	cin>>k;
	if(k<1 || k> DemCB(d)) return;
	if(k==1){
		ThemDau(d,x);
		return;
	}
	Node *q=d.PFirst;
	for(int i=1; i<k-1;i++){
		q=q->Next;
	}
	Node *p= new Node;
	p->Info=x;
	p->Next=q->Next;
	q->Next=p;
}
void XoaDau(DanhSach &d){
	Node *q=d.PFirst;
	if(KTRong(d)){
		return;
	}
	d.PFirst= q->Next;
	delete(q);
}
void XoaCuoi(DanhSach &d){
	Node *Plast=d.PFirst, *q;
	if(KTRong(d)){
		return;
	}
	if(d.PFirst->Next == NULL){
		XoaDau(d);
		return;
	}
	while(Plast->Next != NULL){
		q=Plast;
		Plast=Plast->Next;
	}
	q->Next=NULL;
	delete(Plast);
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
	Node *q=d.PFirst;
	if(KTRong(d)){
		return;
	}
	while(d.PFirst != NULL){
		q=d.PFirst->Next;
		delete(d.PFirst);
		d.PFirst=q;
	}
}
void NhapCB(CanBo &x){
	cout<<" \n nhap ma so va ho ten: ";
	cin>>x.MaSo>>x.HoTen;
}
void Xem(DanhSach d){
	Node *q=d.PFirst;
	while(q!=NULL){
		cout<<"\n  "<< q->Info.MaSo << "  "<<q->Info.HoTen;
		q=q->Next;
	}
}
void TimMS(DanhSach d){
	long MS;
	cout<<" nhap Ma So ";
	cin>> MS;
	Node *q=d.PFirst;
	while(q != NULL){
		if(q->Info.MaSo == MS){
			cout<<" \n "<<q->Info.MaSo <<"  "<<q->Info.HoTen;
			return;
		}
		q=q->Next;
	}
}
main(){
	DanhSach d; CanBo x; char c;
	KhoiTao(d);
	while(1){
		cout<<"\n 0. de thoat ";
		cout<<"\n 1. Them Dau ";
		cout<<"\n 2. Them Cuoi ";
		cout<<"\n 3. Them sau K";
		cout<<"\n 4. Them Truoc K";
		cout<<"\n 5. Xoa Dau ";
		cout<<"\n 6. Xoa Cuoi ";
		cout<<"\n7. Xoa vi tri K ";
		cout<<"\n 8. Xoa Tat Ca Danh Sach";
		cout<<"\n x. Tim Can Bo";
		cout<<"\n 9. Xem ";
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
		if(c== '9'){
			Xem(d);
		}
		if(c== '5'){
			XoaDau(d);
		}
		if(c== '6'){
			XoaCuoi(d);
		}
		if(c=='7'){
			XoaK(d);
		}
		if(c== '8'){
			XoaDS(d);
		}
		if(c== 'x'){
			TimMS(d);
		}
	}
}













