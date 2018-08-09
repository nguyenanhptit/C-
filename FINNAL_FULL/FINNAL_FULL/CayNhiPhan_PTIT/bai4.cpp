#include <stdio.h>
#include <ncurses.h>
//#include <conio.h>
#include <stdlib.h>

FILE *fr= fopen("D-bai4.IN","r");
struct SinhVien	
{	
	long MaSo; 
	char HoTen[8];	
};
struct Node 
{	
	SinhVien Info; 
	Node *Left, *Right; 
};

typedef Node* tree;

void Init(tree &ptree)
{
	ptree = NULL;
}

tree MakeNode(SinhVien sv)
{
	tree ptree;
	ptree = (Node*) malloc (sizeof(Node));
	ptree->Info= sv;
	ptree->Left=NULL;
	ptree->Right= NULL;
	return ptree;
}


void insertNode(tree ptree, SinhVien sv)
{
	tree temp;
	if(ptree->Info.MaSo == sv.MaSo)
	{
		printf("\nSinh vien da ton tai, khong the them vao");
		return;
	}
	else
	{
		if(sv.MaSo < ptree->Info.MaSo)
		{
			if(ptree->Left == NULL)
			{
				temp= MakeNode(sv);
				ptree->Left= temp;
			}
			else
			{
				insertNode(ptree->Left, sv);
			}
			
		}
		else if(sv.MaSo > ptree->Info.MaSo)
		{
			if(ptree->Right == NULL)
			{
				temp= MakeNode(sv);
				ptree->Right= temp;
			}
			else
			{
				insertNode(ptree->Right, sv);
			}
		}
	}
}


int DelNode(tree &ptree, long maSoSV)
{
	if(ptree==NULL)
	{
		return 0;
	}
	if(maSoSV < ptree->Info.MaSo)
	{
		DelNode(ptree->Left, maSoSV);
	}
	else if(maSoSV > ptree->Info.MaSo)
	{
		DelNode(ptree->Right, maSoSV);
	}
	else  //Khi maSoSV == ptree->Info.maSV;
	{
		tree nodeKey= ptree;
		if(ptree->Left == NULL)  // Khi co 1 nhanh con ben phai
		{
			ptree= ptree->Right;
			free(nodeKey);
		}
		else if(ptree->Right == NULL) //Khi co 1 nhanh con ben trai
		{
			ptree = ptree->Left;
			free(nodeKey);
		}
		else  //Khi co 2 nhanh con
		{
			tree nodeCha= ptree;
			tree nodePhaiCung= ptree->Left;
			while(nodePhaiCung-> Right != NULL)
			{
				nodeCha= nodePhaiCung;
				nodePhaiCung= nodePhaiCung->Right;
			}
			ptree->Info= nodePhaiCung->Info;
			if(nodeCha != ptree)  //Neu nut can xoa khong phai la nut goc
			{
				nodeCha->Right= nodePhaiCung->Left;
			}
			else{
				nodeCha->Left= nodePhaiCung->Left;
			}
			free(nodePhaiCung);
			nodePhaiCung= NULL;
		}
		
		return 1;
	}
	return 0;
}

tree SearchNode(tree proot, long maSoSV)
{
	if(proot == NULL)
	{
		return NULL;
	}
	if(proot->Info.MaSo == maSoSV)
	{
		return proot;
	}
	tree p;
	if(maSoSV < proot->Info.MaSo)
	{
		p= SearchNode(proot->Left,maSoSV);
	}
	else
		p= SearchNode(proot->Right,maSoSV);
	return p;
}

void ClearTree(tree &ptree)
{
	if(ptree != NULL)
	{
		ClearTree(ptree->Left);
		ClearTree(ptree->Right);
		free(ptree);
		ptree= NULL;
	}
}
void NLR(tree ptree)
{
	if(ptree != NULL)
	{
		printf("\n%ld---%s",ptree->Info.MaSo, ptree->Info.HoTen);
		NLR(ptree->Left);
		NLR(ptree->Right);
	}
}

void LNR(tree ptree)
{
	if(ptree != NULL)
	{
		LNR(ptree->Left);
		printf("\n%ld---%s",ptree->Info.MaSo, ptree->Info.HoTen);
		LNR(ptree->Right);
	}
}

void LRN(tree ptree)
{
	if(ptree != NULL)
	{
		LRN(ptree->Left);
		LRN(ptree->Right);
		printf("\n%ld---%s",ptree->Info.MaSo, ptree->Info.HoTen);
	}
}
int main()
{
	tree ptree, temp;
	int selected;
	SinhVien SV;
	do {
        //system("clear");
        printf("\n CAY NHI PHAN TIM KIEM");
        printf("\n 1-Khoi tao cay");
        printf("\n 2-Them mot Node ");
        printf("\n 3-Xoa mot Node");
        printf("\n 4-Xoa ca cay");
        printf("\n 5-Tim kiem theo MaSo cua SinhVien");
        printf("\n 6-Duyet theo thu tu truoc-NLR");
        printf("\n 7-Duyet theo thu tu giua-LNR");
        printf("\n 8-Duyet theo thu tu sau-LRN");
        printf("\n 0-Thoat chuong trinh");
        printf("\n An so bat ky de Xoa man hinh");
        printf("\n Lua chon chuc nang:");
        scanf("%d", &selected);
        switch(selected)
        {
			case 1:
				Init(ptree);
				break;
			case 2:
				printf("\nNhap ma so SV: ");
				scanf("%ld",&SV.MaSo);
				getchar();
				printf("\nNhap ho ten: ");
				gets(SV.HoTen);
				if(ptree == NULL)
				{
					ptree = MakeNode(SV);
					printf("\nThem nut goc thanh cong");
				}
				else
				{
					insertNode(ptree, SV);
				}
				break;
			case 3:
				long maSoXoa;
				printf("\nNhap ma so SV can xoa: ");
				scanf("%ld",&maSoXoa);
				if( !DelNode(ptree, maSoXoa))
				{
					printf("\nXoa thanh cong");
				}
				else
					printf("\nMa so khong ton tai");
				break;
			case 4:
				ClearTree(ptree);
				break;
			case 5:
				printf("\nNhap ma so SV can xoa: ");
				scanf("%ld",&maSoXoa);
				temp= SearchNode(ptree, maSoXoa);
				if(temp == NULL)
				{
					printf("\nMa so SV khong ton tai");
				}
				else
				{
					printf("\n%ld---%s",temp->Info.MaSo, temp->Info.HoTen);
				}
				break;
			case 6:
				NLR(ptree);
				break;
			case 7:
				LNR(ptree);
				break;
			case 8:
				LRN(ptree);
				break;
			default:
				system("clear");
				break;
		}
	} while(selected >0);
	return 0;
}

