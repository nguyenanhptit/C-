/*Sap xep tang dan danh sach ke theo giai thuat
  selection sort, bubblesort, quicksort, insertion sort, 
    heapsort, mergesort*/
//Danh sach cai dat bang mang tinh.
#include <stdio.h>
#include <conio.h> 
#include <iostream>
using namespace std;
#define true  1
#define false 0
//================================================== 
void swap(float &x,float &y)
 {float tmp=x;x=y;y=tmp;
 };
//==================================================
//Nhap danh sach.
void nhap(float a[],int &N)
 {cout<<"\nSo phan tu can nhap N = ";cin>>N;
  for(int i=0;i<N;i++)
	{	cout<<"a["<<i<<"]= "; cin>>a[i];}
 }
//==================================================
//Hien danh sach tren man hinh.
void xem(float a[],int N)
 {int i;
  cout<<"\nCac phan tu danh sach:";
  for(i=0;i<N;i++) cout<<a[i]<<"  ";
  }
//==================================================
/*Sap xep danh sach theo thu tu tang dan bang phuong phap lua chon don gian.
  Simple Selection Sort*/
void selectsort(float a[],int N)
 {int i,j,k;float min;
  for(i=0;i<N-1;i++)
   {min=a[i];k=i;
    for(j=i+1;j<N;j++)
     if(a[j]<min) {k=j;min=a[j];}
    if(k!=i) swap(a[i],a[k]);
    xem(a,N);
   }
 }
//==================================================
/*Sap xep danh sach theo thu tu tang dan bang phuong phap
 BUBBLE Sort co cai tien:
 Duyet danh sach nhieu lan, moi lan duyet so sanh cap nut i va i+1 va doi cho
 2 nut nay neu chua dung thu tu cho den khi danh sach duoc sap xep hoan toan.
 Tuy nhien ta co the thay rang:
 - Sau lan duyet 1 thi 1 nut la nut thu n-1 duoc dat dung cho (n=n-1+1)
 - Sau lan duyet 2 thi 2 nut la cac nut n-1,n duoc dat dung cho
 - ...
 - Sau lan duyet i-1 thi cac nut tu n-i+2 den n duoc dat dung cho, do do tai
   lan duyet thu i ta chi can duyet cac phan tu 1 den n-i+1.
   O lan duyet thu n-1 thi n-1 nut duoc dat dung cho, tuc la khong can duyet tiep
   Vay ta co the cai tien thuat toan tren.Neu co mot lan duyet nao do ma
   khong co lan duyet nao thi day da duoc sap xep*/
void bubblesort(float a[],int N)
 {int i,j,doicho;
  do
   {doicho=false;
    for(j=0;j<N-1;j++)
     if(a[j]>a[j+1]) 
	 {swap(a[j],a[j+1]);
	 doicho=true;}
     xem(a,N);
	 }
  while(doicho);
 }
//==================================================
/*Sap xep danh sach theo thu tu tang dan bang phuong phap
  Simple Insertion Sort*/
void insertsort(float a[],int N, int h=1)
 {int i,j;int x;
  for(i=h;i<N;i++) //Ban dau day chi co 1 phan tu a[0]
   {x=a[i];//chen a[i] vao day da sx a[0],a[1],...,a[i-1]
    j=i;
    while(j>0 && x<a[j-h])
     {a[j]=a[j-h];//Keo nut lon hon x len h vi tri
     j=j-h;
     };
     /*Chen x vao vi tri hop le, j la vi tri dau tien ma x>=a[j-h]
      do do gia tri j dung la vi tri can chen x */
     a[j]=x;
     xem(a,N);
   } //end of for(i=h;i<N;i++)
 };
//==================================================
/*CAI DAT GIAI THUAT QUICKSORT}
 Thu tuc partition se phan hoach danh sach tu low den up thanh 2 phan:
 cac nut co noi dung <= a[pivot] nam ben trai pivot, cac nut co
 noi dung > a[pivot] nam ben phai.
 Chon nuttruc=a[low], quet 2 dau lai, i tu duoi len, j tu tren xuong,
 va doi cho cac cap phan tu sai cho, khi ket thuc quet thi doi cho a[low]
 va a[j], vay nut truc se chuyen den vi tri j*/
void partition(float a[],int low,int up,int& pivot)
 {int pivotval=a[low];//Chon nut dau lam truc
  int i=low;
  int j=up;
  while(i<j) //Bat dau quet
   {while(a[i]<=pivotval && i<up) i++; //a[i]>pivotval
    while(a[j]>pivotval)  j--;         //a[j]<=pivotval
    if(i<j) swap(a[i],a[j]); //Doi cho cap nut sai vi tri
    };
  /*Sau vong lap ta co i>=j, cac phan tu tu low den j deu <=pivotval
    cac phan tu tu j+1 deu > pivota, thi du
    0  1  2  3  4
    3  7  2  1  6  i=1 j=3 (a[1]=7>pivotval,(a[3]=1<=pivotval)
    3  1  2  7  6  i=3 j=2 (a[3]=7>pivotval,(a[2]=2<=pivotval)
    ta chuyen pivotval den vi tri j de bao dam rang pivotval
    o dung vi tri trong day, tuc la cac phan tu ben trai
    deu nho hon hoac bang, cac phan tu ben phai lon hon*/
   swap(a[low],a[j]);pivot=j;
 }
//==================================================
void quicksort(float a[],int low,int up)
 {int pivot;
  if(low>=up) return;
  partition(a,low,up,pivot);
  quicksort(a,low,pivot-1);
  quicksort(a,pivot+1,up);
  }
//==================================================
/*Sap xep bang HEAP: Heap la cay nhi phan gan day duoc cai dat bang
  mang mot chieu voi cac nut tren heap co noi dung nho hon nut goc
  va cac nhanh cay con cung la cac heap*/
void heapsort(float a[],int N)
 {/*Chuyen danh sach thanh HEAP bang cach xem khoi dau heap gom nut
    a[0], sau do lan luot chuyen cac nut a[1],a[2],...,
    a[N-1] vao heap*/
  int i,s,f;int x;
  for(i=1;i<N;i++)
   {x=a[i];//Nut can them vao HEAP, ban dau heap co mot nut a[0].
    /*Insert x vao vi tri thich hop cua HEAP: xuat phat tu i, di dan ve
     goc de tim mot vi tri nut cha thich hop. Vay f se giam dan*/
     s=i;       //s la nut con, hien tai tren heap chua co a[i]
     //f=(s-1)/2 la nut cha
     while(s>0 && x>a[(s-1)/2])
      {a[s]=a[(s-1)/2]; //Keo nut < x xuong 1 muc
       s=(s-1)/2;
      };
     a[s]=x; //Dien nut x vao vi tri phu hop
    }; //end of for(int i=1;i<N;i++)
 //Ket thuc chuyen danh sach thanh heap

 //Lan luot xoa nut a[0] tren HEAP, dua ve vi tri thich hop tren ds
    for(i=N-1;i>0;i--)
     {x=a[i];a[i]=a[0];
     /*O buoc i heap co i+1 nut, la a[0], a[1],...,a[i]
      Muc dich cua chung ta la dua nut a[0] ve vi tri a[i],
      dong thoi, chen a[i] vao heap sao cho cau truc heap van bao
      toan. De lam dieu nay ta bat dau tu
      nut f = 0, theo con duong cha - con trai hoac phai, tim mot vi tri
      de chen nut a[i]. De co duoc nut trong de chen a[i], ta can
      dich cac nut tren duong di len mot muc, bang cong thuc
      nutgoc=max(contrai,conphai,a[i])*/
      f=0; //f la nut cha, s la nut con lon hon
      s=2*f+1; //Gan s la nut con ben trai
      if(s+1<i && a[s]<a[s+1]) s=s+1;/*Neu co nut phai va
					lon hon thi chon nut phai*/
      while(s<i && x<a[s])
       {a[f]=a[s];//Con lon thay the cha
	f=s;//Chuyen den con lon tiep theo
	s=2*f+1;
	if(s+1<i && a[s]<a[s+1]) s=s+1;
       };
       a[f]=x; //Nut a[k] duoc chen dung cho
     }; //end of for(i=N-1;i>0;i--)
 };
//==================================================
/*Sap xep danh sach theo thu tu tang dan bang phuong phap
 Merge Sort.
 Input:  Day a[0],a[1],...,a[N-1]
 Tr.gian:Ltemp la danh sach tam dung khi tron, k la chi so cua danh sach nay
	 size la kich thuoc cua danh sach con, o buoc 1 size = 1,
	 buoc 2 size = 2, buoc 3 size = 4,...
	 low1,up1,low2,up2 la can duoi va can tren cua 2 danh sach dang tron
 Output: Danh sach da duoc sap xep*/
void mergesort(float a[],int N)
 {int i,j,k,low1,up1,low2,up2;//Can duoi va tren cua 2 ds con
  int size;
  int *Listtmp=new int[N];
  size=1;//Buoc tron 1: gan size bang 1
  while(size<N)
   {low1=0;k=0;

    while(low1+size<N)
     {low2=low1+size;
      up1=low2-1;
      up2=(low2+size-1<N)? low2+size-1 : N-1;

      /*Cho i quet tu low1 den up1, j quet tu low2 den up2. Voi moi i va j
	so sanh va chon phan tu nho hon chuyen sang danh sach tam.*/
      for(i=low1,j=low2;i<=up1 && j<=up2;k++)
	if(a[i]<=a[j]) Listtmp[k]=a[i++];
	 else Listtmp[k]=a[j++];;

      /*Vi so phan tu duoc chon tu 2 ds khong nhu nhau nen co the i hoac
	j se den dich truoc. Trong truong hop nay ta chuyen phan con lai
	cua day chua quet xong sang ds tam*/
      for(; i <= up1; k++) Listtmp[k] = a[i++];
      for(; j <= up2; k++) Listtmp[k] = a[j++];
      low1 = up2+1;
     } //while(low1+size<N)

     /*Neu so ds con la so le thi khi tron tung cap se con lai ds cuoi
      cung. Ta phai chuyen danh sach nay sang ds tam*/
     for(i = low1; k < N; i++) Listtmp[k++] = a[i];
     for(i = 0; i < N; i++) a[i] = Listtmp[i];
     size *= 2;//Tang co cua danh sach con len 2 lan.
   }//end of while(size<N)
}
//==================================================
main()
 {int step[3] = {5,3,1};
  float a[50]; int N,i;int x;
   while(true)
    {  //Tao menu
     cout<<"\n 1. Nhap danh sach";
     cout<<"\n 2. Xem danh sach ";
     cout<<"\n 3. Sap xep tang dan bang SELECTION Sort";
     cout<<"\n 4. Sap xep tang dan bang BUBBLE Sort";
     cout<<"\n 5. Sap xep tang dan bang INSERTION Sort";
     cout<<"\n 6. Sap xep tang dan bang QUICK Sort";
     cout<<"\n 7. Sap xep tang dan bang HEAP Sort";
     cout<<"\n 8. Sap xep tang dan bang MERGE Sort";
     cout<<"\n z. Ket thuc";
     cout<<endl<<"\nHay nhan phim tu 1 -> z de chon: ";
     char chon=toupper(getch());
     if(toupper(chon)=='Z') break;
     switch (chon)
      {case '1':nhap(a,N);break;
       case '2':xem(a,N);break;
       case '3':selectsort(a,N);break;
       case '4':bubblesort(a,N);break;
       case '5':insertsort(a,N);break;
       case '6':quicksort(a,0,N-1);break;
       case '7':heapsort(a,N);break;
       case '8':mergesort(a,N);break;
       }
     cout<<"\n\nNhan phim bat ky de tiep tuc";
     getch();
     }
  }
