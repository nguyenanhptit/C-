#include<iostream>
#include<math.h>
using namespace std;
int B[100];
long GiaTriDaoNguoc(int *M,int n)
{	
	long s=0,t=1;
	for (int i=1;i<=n;i++)
	{
		s=s+M[i]*t;
		t=t*10;
	}
	return s;
}
int TongChuSo()
{
	int s=0;
	for (int i=1;i<=5;i++) s=s+B[i];
	return s; 
}
int NamChuSo()
{
	if (B[1]==0) return 0;
	return 1;
}
int SoNgTo(int a)
{
	if (a<2) return 0;
	if (a==2) return 1;
	for(int i=2;i<=sqrt(a);i++)
	if (a%i==0) return 0;
	return 1;
}
int ChuSoNgTo()
{
	for (int i=1;i<=5;i++)
	if (!SoNgTo(B[i])) return 0;
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
	long a;
	int b;
	while(!stop)
	{
		a=GiaTriDaoNguoc(B,5);
		b=TongChuSo();
		if (NamChuSo()&&SoNgTo(a)&&SoNgTo(b)&&ChuSoNgTo()) XuatKetQua();
		SinhTiep();	
	}	
}
int main()
{
	KhoiDau();
	SinhLienTiep();
}
