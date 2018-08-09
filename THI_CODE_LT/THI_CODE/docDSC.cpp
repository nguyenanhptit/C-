#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#define max 20
int V, socanh,a[max][max],x,y;
void docDSC (){
	FILE *f1;
	f1= fopen ("DSC.txt","r");
	fscanf (f1,"%d",&V);
	fscanf (f1,"%d",&socanh);
//	for (int i=1; i<=V; i++)
//		for ( int j=1; j<=V; j++)
//		a[i][j]=0;
	for ( int i=1; i<=socanh; i++){
		fscanf (f1,"%d%d",&x,&y);
		a[x][y]= a[y][x]=1;
	}
	fclose (f1);
}
void MTK (){
	printf ("Ma tran ke la: \n");
	printf ("%d\n",V);
	for (int i=1; i<=V; i++){
		for ( int j=1; j<= V; j++)
		printf ("%d ",a[i][j]);
	printf ("\n");
	}
}
void DSK (){
	printf ("danh sach ke la: \n");
	printf ("%d\n",V);
	for (int i=1; i<=V; i++){
		for (int j=1; j<=V; j++)
			if (a[i][j]==1) printf ("%d ",j);
	printf ("\n");
   }
}
main (){
	docDSC ();
	MTK ();
	DSK ();
}

