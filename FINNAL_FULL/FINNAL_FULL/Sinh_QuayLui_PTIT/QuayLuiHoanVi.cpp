#include <stdio.h>
#include <conio.h>
int P[100],B[100], n;
void Init(){
	int i;
	printf("\n Nhap n="); scanf("%d", &n);
	for(i=1; i<=n; i++)
		B[i]=1;
}
void Result(){
	int i;
	for (i=1; i<=n; i++)
		printf("%3d",P[i]);
	printf("\n");
}
void Try(int i){
	int j;
	for(j=1; j<=n;j++){
		if(B[j]) {
			P[i]=j;
			B[j]= 0;
			if(i==n) Result();
			else Try(i+1);
			B[j]= 1;
		}
	}
}
 main(){
	Init(); 
	Try(1);
}

