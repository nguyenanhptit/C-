#include<iostream>
#include<fstream>
#define FREE 1
#define USED 0
using namespace std;
int C[100][100], A[100], B[100], D[100], n, s=0, Max=0;
void InKetQua()
{
	cout<<Max<<"\n";
	for (int i=1;i<=n;i++) cout<<i<<"\t"<<D[i]<<"\t"<<C[i][D[i]]<<"\n";
}
void LayDuLieu()
{
	ifstream file;
	file.open("matran.in");
	file>>n;
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
			if (s>Max) 
			{
				Max=s;
				for (int k=1;k<=n;k++) D[k]=A[k];
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
