#include <iostream>
#include <math.h>
using namespace std;
int B[100],n,p,stop=0;
int ktra (){
	if (B[1]==0) return 0;
	return 1;
}
void khoitao (){
	for (int i=1; i<=n; i++) B[i]=0;
}
void xuatkq (){
	for (int i=1; i<=n; i++)
		cout << B[i];
		cout <<"\n";
}
void sinhtiep (){
	int i=n; 
	while (i>0 && B[i]==9){
		B[i]=0;
		i--;
	}
	if (i==0) stop =1;
	else B[i]++;
}
int gtri (int *B){
	long s=0,t=1;
	for (int i=5; i>=1; i--){
		s= s+ B[i]*t;
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
int Testchuso (int k){
	int du=0;
	while (k!=0){
	du=k%10; k=k/10;
	if (ngto (du)==0) return 0;
	}
	return 1;

}
int Tongchusochiahet (int *B){
	int s=0;
	for (int i=1; i<=5; i++){
		s=s+B[i];
	}
	if (s%p==0) return 1;       
	return 0;
}

void sinhlientuc (){
	while (!stop){ 
		long s= gtri (B);
		if (ktra ()&& ngto (s)&&Testchuso(s)&& Tongchusochiahet(B))
		 xuatkq ();
		sinhtiep();
	}
}
int kqa ();
void thoatMenu (){
	char c;
	cout <<"1.No"<<endl;
	cout <<"2.yes"<< endl;
	switch (c){
		case 1:
			cout <<"see you again"<<endl<<"================";
			break;
		case 2:
			kqa ();
			break;
	}
}
int kqa (){
	cout << "Moi ban nhap n:";
	cin >>n;
	cout <<"Moi nhap p:";
	cin>> p;
	khoitao ();
	sinhlientuc();
	cout <<" Ban co muon tiep tuc:"<<endl;
	thoatMenu ();
}
main (){
	kqa ();
	return 0;
}

