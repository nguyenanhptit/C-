#include<iostream>
using namespace std;
int A[100];
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
void II(int N)
{
	int i=2;
	while(i<=N)
	if (N%i==0)
		{
		cout<<i<<"  ";
		N=N/i;
		}
	else i++;
	cout<<"\n";
}
void III(int m)
{
	for (int i=m;i>=1;i--) cout<<A[i];
	cout<<"\n";
}
int SoHoanHao(int a)
{
	int s=0;
	for (int i=1;i<=a/2;i++)
	if (a%i==0) s=s+i;
	if (s==a) return 1;
	return 0;
}
int main()
{
	int N,B;
	cout<<"Nhap N B = ";
	cin>>N>>B;
	//-------------------------------
	cout<<"ii,\n";
	II(N);
	//-------------------------------
	int m=DoiCoSo(N,B);
	cout<<"iii,\n";
	III(m);
	//-------------------------------
	cout<<"iv,\n";
	for (int a=1;a<N;a++)
	if (SoHoanHao(a)) cout<<a<<"    ";
	cout<<"\n";
}
