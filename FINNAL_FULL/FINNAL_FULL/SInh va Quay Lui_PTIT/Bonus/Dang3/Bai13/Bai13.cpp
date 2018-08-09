#include<iostream>
#include<fstream>
using namespace std;
int C[100], A[100], n, k, D[100][100], dem=0;
void LayDuLieu()
{
	ifstream file;
	file.open("dayso.in");
	file>>n>>k;
	for (int i=1;i<=n;i++) file>>A[i];
	file.close();
}
void KhoiDau()
{
	for (int i=1;i<=k;i++) C[i]=i;
}
void InKetQua()
{
	cout<<dem<<"\n";
	for (int i=1;i<=dem;i++)
		{
		for (int j=1;j<=k;j++) cout<<D[i][j]<<"\t";
		cout<<"\n";
		}
}
int MangTangDan()
{
	for (int i=1;i<=k-1;i++)
		if(A[C[i]]>A[C[i+1]]) return 0;
	return 1;
}
int stop = 0;
void SinhTiep()
{
	int i=k;
	while (i>0&&C[i]==n-k+i) i--;
	if (i>0) 
	{
		C[i]=C[i]+1;
		for (int j=i+1;j<=k;j++) C[j]=C[i]+j-i;
	}
	else stop = 1;
}
void SinhLienTiep()
{
	while(!stop)
	{
		if (MangTangDan())
		{
			dem++;
			for (int j=1;j<=k;j++) D[dem][j]=A[C[j]];
		}
		SinhTiep();
	}
}
int main()
{
	LayDuLieu();
	KhoiDau();
	SinhLienTiep();
	InKetQua();
}
