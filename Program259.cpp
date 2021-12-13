/*
Inorder
preorder
postorder

*/

using namespace std;
#include<iostream>

typedef struct node
{
	int data;
	struct node *lchild;
	struct node *rchild;
	
}NODE,*PNODE,**PPNODE;

void Insert(PPNODE Head,int no)
{
	PNODE newn = new NODE;
	
	newn -> data = no;
	newn -> lchild = NULL;
	newn -> rchild = NULL;
	
	if(*Head == NULL)
	{
		*Head = newn;
	}
	else
	{
		PNODE temp = *Head;
		
		while(1)			//while(true) is same as while(1) Unconditional loop   for( ; ; )
		{
			if(temp -> data == no)
			{
				cout<<"Duplicate node\n";
				
				delete newn;			//node hota aldready direct break kela te memory leak hote tymul delete krn is must
				break;		
			}
			else if(no < (temp -> data))		//data lahan
			{
				if(temp -> lchild == NULL)
				{
					temp -> lchild = newn;
					break;
				}
				temp = temp -> lchild;
			}
			else if(no > (temp -> data))		//data motha
			{
				if(temp -> rchild == NULL)
				{
					temp -> rchild = newn;
					break;
				}
				
				temp = temp -> rchild;
			}
			
		}
	}
}

bool Search(PNODE Head,int no)
{
	if(Head == NULL)		//if tree is empty
	{
		return false;
	}
	else 		//tree contains atleast one node
	{
		while(Head != NULL)
		{
			if(Head -> data == no)  //node found
			{
				
				break;
			}
			else if(no > (Head -> data))
			{
				Head = Head -> rchild;
			}
			else if(no < (Head -> data))
			{
				Head = Head -> lchild;
			}
		}
		
		if(Head == NULL)
		{
			return false;
		}
		else
		{
			return true;
		}
	}
}

int Count(PNODE Head)		//to count all node.
{
	static int iCnt = 0;
	
	if(Head != NULL)
	{
		iCnt++;
		
		Count(Head -> lchild);
		Count(Head -> rchild);
	}
	
	return iCnt;
}

int CountLeaf(PNODE Head)		//to count leaf nodes.
{
	static int iCnt = 0;
	
	if(Head != NULL)
	{
		if((Head -> lchild == NULL) && (Head -> rchild == NULL))
		{
			iCnt++;
		}
		CountLeaf(Head -> lchild);
		CountLeaf(Head -> rchild);
	}
	
	return iCnt;
}

int CountParent(PNODE Head)		//to count leaf nodes.
{
	static int iCnt = 0;
	
	if(Head != NULL)
	{
		if((Head -> lchild != NULL) || (Head -> rchild != NULL))
		{
			iCnt++;
		}
		CountParent(Head -> lchild);
		CountParent(Head -> rchild);
	}
	
	return iCnt;
}

int CountEven(PNODE Head)		//to count leaf nodes.
{
	static int iCnt = 0;
	
	if(Head != NULL)
	{
		if(((Head -> data) % 2) == 0)
		{
			iCnt++;
		}
		CountEven(Head -> lchild);
		CountEven(Head -> rchild);
	}
	
	return iCnt;
}

void Inorder(PNODE Head)		//LDR
{
	if(Head != NULL)
	{
		Inorder(Head -> lchild);	//L
		cout<<Head -> data<<"\n";	//D
		Inorder(Head -> rchild);	//R
	}
}

void Preorder(PNODE Head)		//DLR
{
	if(Head != NULL)
	{
		cout<<Head -> data<<"\n";	//D
		Preorder(Head -> lchild);	//L
		Preorder(Head -> rchild);	//R
		
	}
}

void Postorder(PNODE Head)		//LRD
{
	if(Head != NULL)
	{
		Postorder(Head -> lchild);	//L
		Postorder(Head -> rchild);	//R
		cout<<Head -> data<<"\n";	//D
	}
}

int main()
{
	int no = 0,iRet = 0;
	bool bRet = false;
	
	PNODE first = NULL;
	
	Insert(&first,51);
	Insert(&first,22);
	Insert(&first,101);
	
	cout<<"Inorder\n";
	Inorder(first);
	
	cout<<"Preorder\n";
	Preorder(first);
	
	cout<<"Postorder\n";
	Postorder(first);
	
	cout<<"Enter number to search\n";
	cin>>no;
	
	bRet = Search(first,no);
	if(bRet == true)
	{
		cout<<"Data is there\n";
	}
	else 
	{
		cout<<"Data is not there\n";
	}
	
	iRet = Count(first);
	cout<<"Number of nodes are : "<<iRet<<"\n";
	
	iRet = CountLeaf(first);
	cout<<"Number of leaf nodes are : "<<iRet<<"\n";
	
	iRet = CountParent(first);
	cout<<"Number of Parent nodes are : "<<iRet<<"\n";
	
	iRet = CountEven(first);
	cout<<"Number of Even numbers are : "<<iRet<<"\n";
	
	return 0;
}