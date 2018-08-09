#include <iostream>
#include <math.h>
using namespace std;
int B[100],stop=0;
void khoitao (){
	for (int i=1;i<=5;i++) B[i]=0;
}
int namchuso (){
	if (B[1]==0) return 0;
	return 1;
}
void xuatkq (){
	for (int i=1;i<=5; i++) 
		cout<< B[i];
		cout<<"\n";
}
void sinhtiep (){
	int i=5;
	while (i>0 && B[i]==9){
		B[i]=0;
		i--;
	}
	if (i==0) stop=1;
	else B[i]++;
}
int gtri (int *B){
	long s=0,t=1;
	for (int i=5; i>=1; i--){
		s=s+ B[i]*t;
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
int testDao (int k) {
	int p=0,du=0;
	while (k!=0){
		du=k%10; k=k/10;
		p=p*10+du;
	}
	return (ngto (p));
}
int testTong (int k){
	int T=0, du=0;
	while (k!=0){
		du=k%10; k=k/10;
		T=T+du;
	}
	return (ngto (T));
}
int testChuso (int k){
	int du=0;
	while (k!=0){
		du= k%10; k=k/10;
		if (ngto (du)==0) return 0;

	}
	return 1;
}
void sinhlientuc (){
	while (!stop){
		long s = gtri (B);
		if (namchuso () && ngto (s) && testDao (s) && testTong (s) && testChuso (s))
			xuatkq ();
		sinhtiep ();
	}
}
main (){
	khoitao ();
	sinhlientuc ();
	return 0;
}

