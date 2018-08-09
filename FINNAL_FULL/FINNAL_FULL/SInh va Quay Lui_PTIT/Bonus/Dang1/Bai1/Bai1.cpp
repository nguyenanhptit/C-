#include<iostream>
#include<math.h>
using namespace std;
int B[100]; int A[100];
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
	int k;
	long a;
	cout<<"Nhap Co So : "; cin>>k;
	while(!stop)
	{
		a=GiaTri(B,5);
		int n = DoiCoSo(a,k);
		if (NamChuSo()&&SoNgTo(a)&&MangThNghich(B,5)&&MangThNghich(A,n)) XuatKetQua();
		SinhTiep();	
	}	
}
int main()
{
	KhoiDau();
	SinhLienTiep();
}
