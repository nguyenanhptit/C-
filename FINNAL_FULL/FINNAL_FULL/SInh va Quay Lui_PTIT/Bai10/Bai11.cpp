#include<iostream>
#include<fstream>
using namespace std;
int B[100], A[100]; int D[100][100]; int n, k, dem=0;
void LayDuLieu()
{
	ifstream file;
	file.open("Dayso.in");
	file>>n>>k;
	for (int i=1;i<=n;i++) file>>A[i];
	file.close();
}
void KhoiDau()
{
	for(int i=1;i<=n;i++) B[i]=0;
}
void InKetQua()
{
	cout<<dem<<"\n";
	for (int i=1;i<=dem;i++)
		{
			for(int j=1;j<=n;j++)
				if(D[i][j]==1) cout<<A[j]<<"\t";
			cout<<"\n";
		}	
}
int TongBangK()
{
	int s=0;
	for (int i=1;i<=n;i++) s=s+A[i]*B[i];
	if (s==k) return 1;
	return 0;
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
		if (TongBangK())
		{
			dem++;
			for (int j=1;j<=n;j++) D[dem][j]=B[j];
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
