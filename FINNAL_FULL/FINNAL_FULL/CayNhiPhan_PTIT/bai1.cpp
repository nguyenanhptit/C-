#include <stdio.h>
//#include <ncurses.h>
#include <stdlib.h>
#include <malloc.h>

struct Node {	
	int Info; 
	struct Node *Left, *Right; 
};
typedef Node* tree;

//int Empty(tree &t){
	//if(t == NULL)
	//{
		//return 1;
	//}
	//return 0;
//}

tree MakeNode(int noiDung)
{
	tree p;
	p= (tree) malloc(sizeof(Node));
	p->Info= noiDung;
	p->Left= NULL;
	p->Right= NULL;
	return p;
}

void SetLeft(tree p, int noiDung)
{
	if(p->Left!= NULL)
	{
		printf("\nNut cha da co nhanh ben trai");
	}
	else
	{
		p->Left= MakeNode(noiDung);
		printf("\nThem trai thanh cong");
	}
		
}

void SetRight(tree p, int noiDung)
{
	if(p->Right!= NULL)
	{
		printf("\nNut cha da co nhanh ben phai");
	}
	else
	{
		p->Right= MakeNode(noiDung);
		printf("\nThem phai thanh cong");
	}
		
}

void DelLeft(tree p)
{
	if(p == NULL)
	{
		printf("\nNut p khong ton tai");
		return;
	}
	if(p->Left == NULL)
	{
		printf("\nNut %d khong co nut trai", p->Info);
		return;
	}
	tree nodeTrai= p->Left;
	if(nodeTrai ->Left != NULL || nodeTrai->Right !=NULL)
	{
		printf("%d khong phai la nut la", nodeTrai->Info);
		return;
	}
	p->Left=NULL;
	free(nodeTrai);
	printf("\nXoa thanh cong");
}

void ClearTree(tree proot)
{
	if(proot != NULL)
	{
		ClearTree(proot->Left);
		ClearTree(proot->Right);
		free(proot);
	}
}

void NLR(tree ptree)
{
	if(ptree != NULL)
	{
		printf("%d\t", ptree->Info);
		NLR(ptree->Left);
		NLR(ptree->Right);
	}
}

void LNR(tree ptree)
{
	if(ptree != NULL)
	{
		LNR(ptree -> Left);
		printf("%d\t",ptree->Info);
		LNR(ptree->Right);
	}
	return;
}

void LRN(tree ptree)
{
	if(ptree != NULL)
	{
		LRN(ptree->Left);
		LRN(ptree->Right);
		printf("%d\t",ptree->Info);
	}
}

tree Search(tree proot, int noiDung)
{
	if(proot == NULL)
	{
		return (NULL);
	}
	
	if(proot->Info == noiDung)  //Diem neo
	{
		return (proot);
	}

	tree p = Search(proot->Left, noiDung);
	if(p == NULL)
	{
		p= Search(proot->Right, noiDung);
	}
	return (p);
}


int main()
{
	tree ptree= NULL;
	tree nodeCha;
	int noiDung, noiDungCha, selected;
	do {
        system("clear");
        printf("\n CAY NHI PHAN");
        printf("\n 1-Khoi tao cay");
        printf("\n 2-Them mot Node la ben trai mot Node");
        printf("\n 3-Them mot Node la ben phai mot Node");
        printf("\n 4-Xoa mot Node la ben trai");
        printf("\n 5-Xoa ca cay");
        printf("\n 6-Duyet theo thu tu truoc-NLR");
        printf("\n 7-Duyet theo thu tu giua-LNR");
        printf("\n 8-Duyet theo thu tu sau-LRN");
        printf("\n 0-Thoat chuong trinh");
        printf("\n Lua chon chuc nang:");
        scanf("%d", &selected);
        switch (selected) {
            case 1:
                if(ptree != NULL){
					printf("Cay da co nut goc");
				}
				else{
					printf("\n Noi dung nut goc:");
					scanf("%d", &noiDung);
					ptree= MakeNode(noiDung);
				}
                break;
            case 2:
				if(ptree == NULL)
				{
					printf("Cay chua co goc");
				}
				else
				{
					printf("\nNhap noi dung nut la can them: ");
					scanf("%d", &noiDung);
					if( Search(ptree, noiDung) != 0)
					{
						printf("\nNoi dung bi trung");
					}
					else
					{
						printf("Noi dung node cha: ");
						scanf("%d",&noiDungCha);
						tree nodeCha= Search(ptree, noiDungCha);
						if(nodeCha == NULL)
						{
							printf("\nKhong thay node cha");
						}
						else
							SetLeft(nodeCha, noiDung);
					}
				}
                break;
            case 3:
				if(ptree == NULL)
				{
					printf("\nCay chua co goc");
				}
				else
				{
					printf("\nNhap noi dung nut la can them: ");
					scanf("%d", &noiDung);
					if( Search(ptree, noiDung) != 0)
					{
						printf("\nNoi dung bi trung");
					}
					else
					{
						printf("Noi dung node cha: ");
						scanf("%d",&noiDungCha);
						nodeCha= Search(ptree, noiDungCha);
						if(nodeCha == NULL)
						{
							printf("\nKhong thay node cha");
						}
						else
							SetRight(nodeCha, noiDung);
					}
				}
                break;
            case 4:
				printf("\nNhap noi dung nut cha: ");
				scanf("%d",&noiDungCha);
				nodeCha= Search(ptree, noiDungCha);
				if(nodeCha == NULL)
				{
					printf("\nKhong tim thay node cha");
				}
				else
					DelLeft(nodeCha);
                break;
            case 5:
				if(ptree == NULL)
				{
					printf("\nCay chua co goc");
				}
				else
				{
					ClearTree(ptree);
					printf("Da xoa ca cay");
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
        }
	} while(selected != 0);
	return 0;
}

