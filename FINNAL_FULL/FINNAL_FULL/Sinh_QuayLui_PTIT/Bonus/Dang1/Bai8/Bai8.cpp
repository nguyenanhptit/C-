#include<iostream>
using namespace std;
int B[100]; int n;
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
void KhoiDau()
{
	for(int i=1;i<=n;i++) B[i]=0;
}
void XuatKetQua()
{
	for(int i=1;i<=n;i++) cout<<B[i]<<"    ";
	cout<<"\n";
}
int stop = 0;
void SinhTiep()
{
	int i=n;
	while (i>0 && B[i]==1)
	{
		B[i]=0;
		i--;
	}
	if (i==0) stop=1;
	else B[i]=1;
}
void SinhLienTuc()
{
	while (!stop)
	{
		if (MangThNghich(B,n)) XuatKetQua();
		SinhTiep();
	}
}

int main()
{
	cout<<"Nhap n : ";
	cin>>n;
	KhoiDau();
	SinhLienTuc();
	
}
