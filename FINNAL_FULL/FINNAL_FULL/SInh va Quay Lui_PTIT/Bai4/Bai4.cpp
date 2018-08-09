#include<iostream>
#include<math.h>
using namespace std;
int B[100];
int NamChuSo()
{
	if (B[1]==0) return 0;
	return 1;
}
int TongChuSo()
{
	int s=0;
	for (int i=1;i<=5;i++) s=s+B[i];
	return s; 
}
long TichChuSo()
{
	long t=1;
	for (int i=1;i<=5;i++) t=t*B[i];
	return t;
}
int ChiaHet(long a, int k)
{
	if (a%k==0) return 1;
	return 0;
}
int KhongChuaR(int r)
{
	for (int i=1;i<=5;i++)
	if (B[i]==r) return 0;
	return 1;
}
void KhoiDau()
{
	for(int i=1;i<=5;i++) B[i]=0;
}
void XuatKetQua()
{
	for (int i=1;i<=5;i++) cout<<B[i]<<"   ";
	cout<<"\n";
}
int stop = 0;
void SinhTiep()
{
	int i=5;
	while(i>0&&B[i]==9)
	{
		B[i]=0;
		i--;	
	}
	if (i==0) stop=1;
	else B[i]++;	
}
void SinhLienTiep()
{
	int p,q,r;
	cout<<"Nhap P Q R = ";
	cin>>p>>q>>r;
	while(!stop)
	{	
		int s=TongChuSo();
		long t=TichChuSo();	
		if (NamChuSo()&&ChiaHet(s,p)&&ChiaHet(t,q)&&KhongChuaR(r)) XuatKetQua();
		SinhTiep();	
	}	
}
int main()
{
	KhoiDau();
	SinhLienTiep();
}
