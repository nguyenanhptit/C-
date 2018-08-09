#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
# define max 20
int V, a[max][max];
void docMTK (){
	FILE *f1;
	f1=fopen ("MTK.txt","r");
	fscanf (f1,"%d",&V);
	for ( int i=1; i<=V; i ++){
		for ( int j=1; j <=V; j++)
			fscanf (f1,"%d",&a[i][j]);
	}
	fclose (f1);
}
void DSC (){
	int socanh=0;
	for (int i=1; i<=V; i++)
		for (int j=i+1; j<=V; j++) 
			if (a[i][j]==1) socanh ++;
	printf ("%d %d",V,socanh);
	for ( int i=1; i<=V; i++){
		for ( int j=i+1; j<=V; j++)
		if (a[i][j]==1) printf ("\n%d %d ", i,j);
	}
}
void DSK (){
	printf ("\nMTK LA:\n");
	printf ("%d\n",V);
	for (int i=1; i<=V; i++){
		for (int j= 1; j<=V; j++)
			if ( a[i][j]==1) printf ("%d ",j);
		printf ("\n");
	}
}
int baccuadinh (){
	printf ("bac cua dinh la: \n");
	for ( int i=1; i<= V; i++){
		printf ("%d ", i);
		int dem =0;
		for ( int j=1; j<= V; j++)
			if ( a[i][j]==1) dem ++;
		printf ("%d\n", dem);
	}
}
main (){
	docMTK ();
	DSC ();
	DSK ();
	baccuadinh ();
}
