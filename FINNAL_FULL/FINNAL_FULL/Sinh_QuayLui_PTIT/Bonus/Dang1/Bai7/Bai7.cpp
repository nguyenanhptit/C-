#include<iostream>
#include<fstream>
using namespace std;
int B[100];
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
int TongChuSo()
{
	int s=0;
	for (int i=1;i<=6;i++) s=s+B[i];
	return s; 
}
int KhongChuaR(int r)
{
	for (int i=1;i<=6;i++)
	if (B[i]==r) return 0;
	return 1;
}
int LoaiI()
{
	if (MangThNghich(B,6)) return 1;
	return 0;
}
int LoaiII()
{
	if (LoaiI()&&TongChuSo()%10==0) return 1;
	return 0;	
}
int LoaiIII()
{
	if (LoaiII()&&KhongChuaR(0)) return 1;
	return 0;
}
void KhoiDau()
{
	for(int i=1;i<=6;i++) B[i]=0;
}
ofstream file1, file2, file3;
void GhiFile1()
{
	for (int k=2;k<=8;k++)
	{	
		file1<<"091"<<k;
		for(int i=1;i<=6;i++) file1<<B[i];
		file1<<"\t";
	}
	file1<<"\n";
}
void GhiFile2()
{
	for (int k=2;k<=8;k++)
	{	
		file2<<"091"<<k;
		for(int i=1;i<=6;i++) file2<<B[i];
		file2<<"\t";
	}
	file2<<"\n";
}
void GhiFile3()
{
	for (int k=2;k<=8;k++)
	{	
		file3<<"091"<<k;
		for(int i=1;i<=6;i++) file3<<B[i];
		file3<<"\t";
	}
	file3<<"\n";
}
void XuatKetQua()
{
	if (LoaiI()&&!LoaiII())GhiFile1();
	if (LoaiII()&&!LoaiIII()) GhiFile2();
	if (LoaiIII()) GhiFile3();
}
int stop = 0;
void SinhTiep()
{
	int i=6;
	while (i>0 && B[i]==9)
	{
		B[i]=0;
		i--;
	}
	if (i==0) stop=1;
	else B[i]=B[i]+1;
}
void SinhLienTuc()
{
	while (!stop)
	{
		XuatKetQua();
		SinhTiep();
	}
}

int main()
{
	file1.open("Loai1.out");
	file2.open("Loai2.out");
	file3.open("Loai3.out");
	
	KhoiDau();
	SinhLienTuc();
	
	file1.close();
	file2.close();
	file3.close();
}
