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
int A[30], n;
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
	n = DoiCoSo(a,10);
	if (MangThNghich(A,n)) return 1;
	return 0;
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
	while(!stop)
	{	
		int s=TongChuSo();
		long t=TichChuSo();	
		if (NamChuSo()&&(SoThNghich(s)&&(n==2))&&(SoThNghich(t)&&(n==3))) XuatKetQua();
		SinhTiep();	
	}	
}
int main()
{
	KhoiDau();
	SinhLienTiep();
}
