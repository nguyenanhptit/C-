#include<iostream>
using namespace std;
int B[100];
void KhoiDau(int n)
{
	for (int i=1;i<=n;i++) B[i]=0;
}
void XuatKetQua(int n)
{
	for (int i=1;i<=n;i++) cout<<B[i]<<"    ";
	cout<<"\n";
}
int stop=0;
void SinhTiep(int n)
{
	int i=n;
	while(i>0&&B[i]==9)
	{
		B[i]=0;
		i--;
	}
	if (i>0) B[i]=B[i]+1;
	else stop=1;
}
int SoTuNhien()
{
	if (B[1]==0) return 0;
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
void SinhLienTiep()
{
	for (int n=5;n<=9;n=n+2)
	{
		KhoiDau(n);
		stop=0;
		while(!stop)
		{
			if (SoTuNhien()&&MangThNghich(B,n)) XuatKetQua(n);
			SinhTiep(n);
		}
	}
}
int main()
{
	SinhLienTiep();
}

