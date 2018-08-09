#include<stdio.h>
#include<conio.h>
#include<math.h>
#define MAX 100
int M[MAX], n, check = true;
void ghikq()
{	
	for(int i=1; i<=n; i++)
	{
		 printf("%5d",M[i]);
	}
	printf("\n");
}
int nguyento(int x)
{
	if(x<2)return 0;
	if(x==2) return 1;
	for (int i=2;i<=sqrt(x);i++)
	if ((x%i)==0) return 0;
	return 1;
}
void demsocs(int x)
{   int m=0,d=0,b=x;
    while(b>0){ d++;
                b=b/10;}
    printf("\n x co %d so ",d);
    }
int thuannghich(int x)
{     int a,b,c=x;
      a=x;
      b=0;
      while(c>0)
          {b=b*10+c%10;
           c=c/10;} 
      if(a==b) return 1;
      return 0;
}
int tongcs(int x)
{ int a=0,b=x;
  while(b>0){ a=a+b%10;
              b=b/10;}
  return a;
}
int dao(int x)
{   int a=0,b=x;
    while(b>0){ a=a*10+b%10;
                b=b/10;}
    return a;
}
int caccsSNT(int x)
{   int a,i,b=x;
    while(b>0){ a=b%10;
                if(!nguyento(a)) { return 0;break;}
                
                b=b/10;
                }
                return 1;
    
}
int KTMNguyento()
{
	if(M[1]==0) return 0;
	int soM=0,cs=1,i;
	for(i=n;i>=1;i--)
	{
		soM=soM+M[i]*cs;
		cs=cs*10;
	}
	
	if(nguyento(soM)&&nguyento(tongcs(soM))&&nguyento(dao(soM))&&caccsSNT(soM)/*&&thuannghich(soM)*/) return 1;
	return 0;
}
void sinhkt()
{
	int i = n;
	while(i>0 && M[i]==9) {
		M[i] = 0;
		i--;
	}
	if(i > 0) M[i]++;
	else check = false;
}
main() {
	M[MAX] = 0;
	printf("Nhap N: ");scanf("%d",&n);
	do { if(KTMNguyento())
		ghikq();
		
		sinhkt();	
	}while(check);
}
