#include<iostream>
#include<fstream>
#define FREE 1
#define USED 0
using namespace std;
int C[100][100], A[100], B[100], D[100][100], n, k, s=0, dem=0;
void InKetQua()
{
	cout<<dem<<"\n";
	for (int u=1;u<=dem;u++)
		{		
		for (int v=1;v<=n;v++) cout<<D[u][v]<<"\t";
		cout<<"\n";
		}
}
void LayDuLieu()
{
	ifstream file;
	file.open("matran.in");
	file>>n>>k;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++) file>>C[i][j];
	file.close();
}
void Try(int i)
{
	for (int j=1;j<=n;j++)
	if (B[j]==FREE) 
	{
		s=s+C[i][j];
		A[i]=j;
		B[j]=USED;
		if (i==n)
		{
			if (s==k) 
			{
				dem++;
				for (int v=1;v<=n;v++) D[dem][v]=A[v];
			}
		}
		else Try(i+1);
		s=s-C[i][j];
		B[j]=FREE;
	}
}
void KhoiDau()
{
	for (int j=1;j<=n;j++) B[j]=FREE;
}
int main()
{
	LayDuLieu();
	KhoiDau();
	Try(1);
	InKetQua();
}
