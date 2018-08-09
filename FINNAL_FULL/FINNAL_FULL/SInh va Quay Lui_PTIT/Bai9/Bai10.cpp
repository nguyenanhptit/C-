#include<iostream>
#include<fstream>
using namespace std;
int D[100], A[100]; int C[100][100]; int n, b, dem=0;
void LayDuLieu()
{
	ifstream file;
	file.open("Data.in");
	file>>n>>b;
	for (int i=1;i<=n;i++) file>>A[i];
	file.close();
}
void KhoiDau()
{
	for(int i=1;i<=n;i++) D[i]=0;
}
void InKetQua()
{
	cout<<dem<<"\n";
	for (int i=1;i<=dem;i++)
		{
			for(int j=1;j<=n;j++)cout<<C[i][j]<<"\t";
			cout<<"\n";
		}	
}
int TongBangB()
{
	int s=0;
	for (int i=1;i<=n;i++) s=s+A[i]*D[i];
	if (s==b) return 1;
	return 0;
}
int stop = 0;
void SinhTiep()
{
	int i=n;
	while (i>0 && D[i]==1)
	{
		D[i]=0;
		i--;
	}
	if (i==0) stop=1;
	else D[i]=1;
}
void SinhLienTuc()
{
	while (!stop)
	{
		if (TongBangB())
		{
			dem++;
			for (int j=1;j<=n;j++) C[dem][j]=D[j];
		}
		SinhTiep();
	}
}

int main()
{
	LayDuLieu();
	KhoiDau();
	SinhLienTuc();
	InKetQua();
}
