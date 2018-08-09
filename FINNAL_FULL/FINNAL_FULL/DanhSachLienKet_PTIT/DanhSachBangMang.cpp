#include<iostream>
using namespace std;
struct CanBo {long MaSo ; char HoTen[8];
};
struct DanhSach { CanBo DSCB[100]; int TongSoCB;
};
void KhoiTao(DanhSach &d)
{
	{
	cout<<"Nhap So Can Bo : ";
	cin>>d.TongSoCB;
    }
    while (d.TongSoCB>100);
	for (int i=0;i<d.TongSoCB;i++)
	{
		cout<<"Nhap MaSo HoTen : ";
		cin>>d.DSCB[i].MaSo>>d.DSCB[i].HoTen;
	}
}
void Xem(DanhSach d)
{
	for (int i=0;i<d.TongSoCB;i++) cout<<d.DSCB[i].MaSo<<"\t"<<d.DSCB[i].HoTen<<"\n";
}
int KTRong(DanhSach d)
{
	return (d.TongSoCB==0);
}
int KTDay(DanhSach d)
{
	return (d.TongSoCB==100);
}
void ThemDau(DanhSach &d)
{
	CanBo tmp;
	cout<<"Nhap MaSo HoTen : ";
	cin>>tmp.MaSo>>tmp.HoTen;
	d.TongSoCB=d.TongSoCB+1;
	for(int i=d.TongSoCB;i>0;i--) d.DSCB[i]=d.DSCB[i-1];
	d.DSCB[0]=tmp;
}
void ThemCuoi(DanhSach &d)
{
	cout<<"Nhap MaSo HoTen : ";
	int n=d.TongSoCB;
	cin>>d.DSCB[n].MaSo>>d.DSCB[n].HoTen;
	d.TongSoCB++;
}
void ThemTruocK(DanhSach &d,int &k)
{
	cout<<"Nhap k : ";
	cin>>k;
	for (int i=d.TongSoCB;i>k;i--) d.DSCB[i]=d.DSCB[i-1];
	cout<<"Nhap MaSo HoTen : ";
	cin>>d.DSCB[k].MaSo>>d.DSCB[k].HoTen;
	d.TongSoCB++;
}
void ThemSauK (DanhSach &d,int &k)
{
	cout<<"Nhap k : ";
	cin>>k;
	for (int i=d.TongSoCB;i>k+1;i--) d.DSCB[i]=d.DSCB[i-1];
	cout<<"Nhap MaSo HoTen : ";
	cin>>d.DSCB[k+1].MaSo>>d.DSCB[k+1].HoTen;
	d.TongSoCB++;
}
void XoaDau(DanhSach &d)
{
	for (int i=0;i<d.TongSoCB-1;i++) d.DSCB[i]=d.DSCB[i+1];
	d.TongSoCB--;
}
void XoaCuoi(DanhSach &d)
{
	d.TongSoCB--;
}
void XoaK(DanhSach &d,int k)
{
	cout<<"Nhap K : ";
	cin>>k;
	for (int i=k;i<d.TongSoCB-1;i++) d.DSCB[i]=d.DSCB[i+1];
	d.TongSoCB--;
}
void XoaToanBo(DanhSach &d)
{
	d.TongSoCB=0;
}
void TimTheoMS(DanhSach d)
{	
	long MS;
	cout<<"Nhap MaSo : ";
	cin>>MS;
	for (int i=0;i<d.TongSoCB;i++) 
	if (MS==d.DSCB[i].MaSo) cout<<d.DSCB[i].MaSo<<"\t"<<d.DSCB[i].HoTen<<"\n";
}
int main()
{	
	int t=1; DanhSach d; int k; char c;
	while(t)
	{		
	cout<<"0. Thoat\n";
	cout<<"1. Khoi Tao\n";
	cout<<"2. Xem\n";
	cout<<"3. Them Dau\n";
	cout<<"4. Them Cuoi\n";
	cout<<"5. Them Truoc Vi Tri K\n";
	cout<<"6. Them Sau Vi Tri K\n";
	cout<<"7. Xoa Dau\n";
	cout<<"8. Xoa Cuoi\n";
	cout<<"9. Xoa Vi Tri K\n";
	cout<<"X. Xoa Toan Bo Danh Sach\n";
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
	Xem(d);
	break;
	case '3' :
	if (!KTDay(d)) ThemDau(d); else cout<<"Danh Sach Day\n";
	break;
	case '4' :
	if (!KTDay(d)) ThemCuoi(d); else cout<<"Danh Sach Day\n";
	break;
	case '5' :
	if (!KTDay(d)) ThemTruocK(d,k); else cout<<"Danh Sach Day\n";
	break;
	case '6' :
	if (!KTDay(d)) ThemSauK(d,k); else cout<<"Danh Sach Day\n";
	break;
	case '7' :
	if (KTRong(d)) cout<<"Danh Sach Rong\n"; else XoaDau(d);
	break;
	case '8' :
	if (KTRong(d)) cout<<"Danh Sach Rong\n"; else XoaCuoi(d);
	break;
	case '9' :
	if (KTRong(d)) cout<<"Danh Sach Rong\n"; else XoaK(d,k);
	case 'x' :
	if (KTRong(d)) cout<<"Danh Sach Rong\n"; else XoaToanBo(d);
	break;
	case 's' :
	if (KTRong(d)) cout<<"Danh Sach Rong\n"; else TimTheoMS(d);
	break;
	}
	}
}






