#include <iostream>
#include <math.h>
using namespace std;
int B[100], stop=0,x;
int namchuso (){
	if (B[1]==0) return 0;
	return 1;
}
void khoitao (){
	for (int i=1; i<=5; i++) B[i]=0;
}
void xuatkq (){
	for (int i=1; i<=5; i++)
		cout << B[i];
		cout<<"\n";
}
void sinhtiep (){
	int i=5;
	while (i>0 &&B[i]==9) {
		B[i]=0;
		i--;
	}
	if (i==0) stop=1;
	else B[i]++;
}
long gtri (int *B){
	long s=0,t=1;
	for (int i=5; i>=1;i--){
	
	s=s+B[i]*t;
	t=t*10;
}
	return s;
}
int ngto (int k){
	if (k<2) return 0;
	if (k==2) return 1;
	for (int i=2; i<= sqrt (k); i++)
		if (k%i==0) return 0;
	return 1;
	
}
int thuannghich (int *M){
	int r=1,s=5;
	while (r<s){
		if (M[r]!=M[s]) return 0;
		r++;
		s--;
	}
}
int chuyencoso (int x,int n){
	int d[100],du=0;
	for (int i=1; i<=5; i++){
		du=n%x;
		n=n/x;
		d[i]=du;
	}
	if (thuannghich (d)) return 1 ;
	return 0;
	
}

void sinhlientuc (){
	while (!stop){
		long s= gtri (B);
		if (namchuso()&& ngto (s)&& thuannghich(B) && chuyencoso (x,s))
			 xuatkq ();
		sinhtiep ();
	}
}
int main (){
	cout << "nhap co so x: ";
	cin >> x;
	khoitao ();
	sinhlientuc ();
	return 0;
}
