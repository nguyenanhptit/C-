#include<iostream>
#include<math.h>
using namespace std;
int B[100]; int A[100];
int n=5,stop=0;
long GiaTri(int *M,int n)
{	
	long s=0,t=1;
	for (int i=n;i>=1;i--)
	{
		s=s+M[i]*t;
		t=t*10;
	}
	return s;
}
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
	for (int i=1;i<=n;i++) s=s+B[i];
	return s; 
}
long TichChuSo()
{
	long t=1;
	for (int i=1;i<=n;i++) t=t*B[i];
	return t;
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
	for (int i=1;i<=n;i++)
	if (!SoNgTo(B[i])) return 0;
	return 1;
}
int MangThNghich(int *M,int n)
{
	int r=1,s=n;
	while(r<s)
	{
	if (M[r]!=M[s]) return 0;
	r++;s--;
	}
	return 1;
}
int A[30], m;
int DoiCoSo(int a,int k)
{
	int i=1; A[1]=0;
	while (a!=0) 
	{
		A[i]=a%k;
		a=a/k;
		i++;
	}
	return i-1;
}
int SoThNghich(long a)
{
	m = DoiCoSo(a,10);
	if (MangThNghich(A,m)) return 1;
	return 0;
}
void KhoiDau()
{
	for(int i=1;i<=n;i++) B[i]=0;
}
void XuatKetQua()
{
	for (int i=1;i<=n;i++) cout<<B[i]<<"   ";
	cout<<"\n";
}
void SinhTiep()
{
	int i=n;
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
	int k;
	long a;
	cout<<"Nhap Co So : "; cin>>k;
	while(!stop)
	{
		a=GiaTri(B,n);
		int n = DoiCoSo(a,k);
		if (NamChuSo()&&SoNgTo(a)&&MangThNghich(B,n)&&MangThNghich(A,n)) XuatKetQua();
		SinhTiep();	
	}	
}
int main()
{
	KhoiDau();
	SinhLienTiep();
}
