#include<iostream>
#include<stdio.h>
using namespace std;

template <typename T>
struct node3
{
	T data;
	struct node3 *lchild;
	struct node3 *rchild;
	
};

template <typename T>
class BST
{
	private:
		node3 <T>* root;
		int iSize;
		
	public:
		BST();
		void Insert(T);
		bool Search(int);
		void DisplayIn();
		void DisplayPre();
		void DisplayPost();
		void Inorder(node3<T> *ptr);
		void Preorder(node3<T> *ptr);
		void Postorder(node3<T> *ptr);
		int Count();
		int CntLeaf();
		int CntParent();
		int CountLeaf(node3<T> *ptr);
		int CountParent(node3<T> *ptr);
		
};

template <typename T>
BST<T> :: BST()
{
	root = NULL;
	iSize = 0;
}

template <typename T>
void BST<T> :: Insert(T iNo)
{
	node3 <T>* newn = new node3 <T>;
	
	newn -> data = iNo;
	newn -> lchild = NULL;
	newn -> rchild = NULL;
	
	if(root == NULL)
	{
		root = newn;
	}
	else
	{
		node3 <T>* temp = root;
		
		while(1)
		{
			if(iNo == (temp -> data))
			{
				delete newn;
				break;
			}
			else if(iNo < (temp -> data))
			{
				if((temp -> lchild) == NULL)
				{
					temp -> lchild = newn;
					break;
				}
				
				temp = temp -> lchild;
			}
			else if(iNo > (temp -> data))
			{
				if((temp -> rchild) == NULL)
				{
					temp -> rchild = newn;
					break;
				}
				
				temp = temp -> rchild;
			}
		}
	}
	
	iSize++;
}

template <typename T>
bool BST<T> :: Search(int iNo)
{
	if(root == NULL)
	{
		return false;
	}
	else
	{
		while(root != NULL)
		{
			if(iNo == (root -> data))
			{
				break;
			}
			else if(iNo < (root -> data))
			{
				root = root -> lchild;
			}
			else if(iNo > (root -> data))
			{
				root = root -> rchild;
			}
		}
		
		if(root == NULL)
		{
			return false;
		}
		else 
		{
			return true;
		}
	}

}

template <typename T>
void BST<T> :: DisplayIn()
{
	Inorder(root);
}

template <typename T>
void BST<T> :: Inorder(node3<T> *ptr)
{	
	if(ptr != NULL)
	{
		Inorder((ptr) -> lchild);
		cout<<((ptr) -> data)<<"\n";
		Inorder((ptr) -> rchild);
	}
}

template <typename T>
void BST<T> :: DisplayPre()
{
	Preorder(root);
}

template <typename T>
void BST<T> :: Preorder(node3<T> *ptr)
{	
	if(ptr != NULL)
	{
		cout<<((ptr) -> data)<<"\n";
		Preorder((ptr) -> lchild);
		Preorder((ptr) -> rchild);
	}
}

template <typename T>
void BST<T> :: DisplayPost()
{
	Postorder(root);
}

template <typename T>
void BST<T> :: Postorder(node3<T> *ptr)
{	
	if(ptr != NULL)
	{
		Postorder((ptr) -> lchild);
		Postorder((ptr) -> rchild);
		cout<<((ptr) -> data)<<"\n";
	}
}

template <typename T>
int BST<T> :: Count()
{
	return iSize;
}

template <typename T>
int BST<T> :: CntLeaf()
{
	CountLeaf(root);
}

template <typename T>
int BST<T> :: CountLeaf(node3 <T> *ptr)
{
	static int iCnt = 0;
	
	if(ptr != NULL)
	{
		if((ptr -> lchild == NULL) && (ptr -> rchild == NULL))
		{
			iCnt++;
		}
		CountLeaf(ptr -> lchild);
		CountLeaf(ptr -> rchild);
	}
	return iCnt;
	
}

template <typename T>
int BST<T> :: CntParent()
{
	CountParent(root);
}

template <typename T>
int BST<T> :: CountParent(node3 <T> *ptr)
{
	static int iCnt = 0;
	
	if(ptr != NULL)
	{
		if((ptr -> lchild != NULL) || (ptr -> rchild != NULL))
		{
			iCnt++;
		}
		
		CountParent(ptr -> lchild);
		CountParent(ptr -> rchild);
	}
	return iCnt;
}

int main()
{
	int iRet = 0,iChoice = 1,iValue = 0,iNo = 0;
	bool bRet = false;
	
	BST <int>obj;
	
	while(iChoice != 0)
	{
		printf("Enter desired choice you want to perform on BST : \n");
		printf("_________________________________________________________________\n");
		printf("1. Insert node3 in the BST.\n");
		printf("2. Search node3 in BST.\n");
		printf("3. Display the node3s of linked list(Inordr)\n");
		printf("4. Display the node3s of linked list(Preordr)\n");
		printf("5. Display the node3s of linked list(Postordr)\n");
		printf("6. Count the total number of node3s .\n");
		printf("7. Count the number of leaf node3s. \n");
		printf("8. Count the number of parent node3s.\n");
		printf("0.Terminate the application.\n");
		printf("_________________________________________________________________\n");
		
		scanf("%d",&iChoice);
		
		switch(iChoice)
		{
			case 1:
				printf("Enter element you want to insert : \n");
				scanf("%d",&iValue);
				obj.Insert(iValue);
				break;
				
			case 2:
				printf("Enter element you want to search : \n");
				scanf("%d",&iNo);
				bRet = obj.Search(iNo);
				 
				if(bRet == true)
				{
					printf("Data is there\n");
				}
				else
				{
					printf("Data is not there\n");;
				}
				
				break;
				
			case 3:
				printf("Inorder : \n");
				obj.DisplayIn();
				break;
				
			case 4:
				printf("Preorder : \n");
				obj.DisplayPre();
				break;
				
			case 5:
				printf("Postorder : \n");
				obj.DisplayPost();
				break;
				
			case 6:
				iRet = obj.Count();
				printf("Total number of node3s are : %d\t",iRet);
				printf("\n");
				break;
				
			case 7:
				iRet = obj.CntLeaf();
				printf("Number of leaf node3s are :%d\t",iRet);
				printf("\n");
				break;
				
			case 8:
				iRet = obj.CntParent();
				printf("Number of parent node3s are :%d\t",iRet);
				printf("\n");
				break;
				
			case 0:
				printf("Thanks for using BST!!\n");
				break;
			
			default:
				printf("Please enter desired choice !\n");
				break;		
		}
	}
	
	return 0;
}
