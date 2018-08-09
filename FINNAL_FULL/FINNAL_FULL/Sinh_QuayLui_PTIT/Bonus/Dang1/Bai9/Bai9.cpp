#include<iostream>
using namespace std;
int B[100]; int m, n; int D[100][100]; int dem=0;
void KhoiDau()
{
	for(int i=1;i<=m+n;i++) B[i]=0;
}
void InKetQua()
{
	cout<<dem<<"\n";
	for (int i=1;i<=dem;i++)
	{
		for (int j=1;j<=m+n;j++) cout<<D[i][j]<<"\t";
		cout<<"\n";
	}
}
int stop = 0;
int KiemTra()
{
	int s=0;
	for (int j=1;j<=m+n;j++) s=s+B[j];
	if (s==n) return 1;
	return 0;
}
void SinhTiep()
{
	int i=m+n;
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
		if (KiemTra())
		{
			dem++;
			for (int j=1;j<=m+n;j++) D[dem][j]=B[j];
		}
		SinhTiep();
	}
}

int main()
{
	cout<<"Nhap m, n : ";
	cin>>m>>n;
	KhoiDau();
	SinhLienTuc();
	InKetQua();
	
}
