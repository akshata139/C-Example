//encapsulation,abstraction.

#include<iostream>
using namespace std;

typedef struct node
{
	int data;
	struct node *next;
	
}NODE,*PNODE,**PPNODE;

class SinglyLL
{
	private:
		PNODE first;
		int size;
		
	public:
		SinglyLL()
		{
			first = NULL;
			size = 0;
		}
		
		void InsertFirst(int no)
		{
			PNODE newn = new NODE; //newn = (PNODE)malloc(sizeof(NODE))
			
			newn -> data = no;
			newn -> next = NULL;
			
			if(first == NULL)
			{
				first = newn;
			}
			else
			{
				newn -> next = first;
				first = newn;
			}
			size++;
		}
		
		void InsertLast(int no)
		{
			PNODE newn = new NODE; //newn = (PNODE)malloc(sizeof(NODE))
			
			newn -> data = no;
			newn -> next = NULL;
			
			if(first == NULL)
			{
				first = newn;
			}
			else
			{
				PNODE temp = first;
				
				while((temp -> next) != NULL)
				{
					temp = temp -> next;
				}
				temp -> next = newn;
			}
			size++;
		}
		
		void InsertAtPos(int no,int ipos)
		{	
			PNODE temp = first;
			
			if((ipos < 1) || (ipos > (size + 1)))
			{
				cout<<"\nInvalid position!!\n";
				return;
			}
			
			if(ipos == 1)
			{
				InsertFirst(no);
			}
			else if(ipos == (size + 1))
			{
				InsertLast(no);
			}
			else
			{
				PNODE newn = new NODE;
				int i = 0;
				
				newn -> data = no;
				newn -> next = NULL;
				
				for(i = 1;i < (ipos-1);i++)
				{
					temp = temp -> next;
				}
				
				newn -> next = temp -> next;
				temp -> next = newn;
			}
			
			size++;
		}
		
		void DeleteFirst()
		{
			PNODE temp = first;
			
			if(first != NULL)		//size != 0
			{
				first = first -> next;
				delete temp;
				
				size--;
			}
		}
		
		void DeleteLast()
		{
			PNODE temp = first;
			
			if(first == NULL)
			{
				return;
			}
			else if(first -> next == NULL)
			{
				delete first;
				first = NULL;
				size--;
			}
			else
			{
				while((temp -> next -> next) != NULL)
				{
					temp = temp -> next;
				}
				
				delete (temp -> next);
				temp -> next = NULL;
				size--;
				
			}
		}
		
		void DeleteAtPos(int ipos)
		{
			PNODE temp = first;
			PNODE targated = NULL;
			int i = 0;
			
			if((ipos < 1) || (ipos > size))
			{
				cout<<"\nInvalid position!!\n";
				return;
			}
			
			if(ipos == 1)
			{
				DeleteFirst();
			}
			else if(ipos == size)
			{
				DeleteLast();
			}
			else
			{
				for(i = 1; i < (ipos - 1);i++)
				{
					temp = temp -> next;
				}
				
				targated = temp -> next;
				temp -> next = targated -> next;
				
				free(targated);
				
				size--;
			}
		}
		
		void Display()
		{
			PNODE temp = first;
			
			while(temp != NULL)
			{
				cout<<temp -> data<<"\t";
				temp = temp -> next;
			}
			
			cout<<"\n";
		}
		
		int Count()
		{
			return size;
		}
};

int main()
{
	SinglyLL obj;
	int iRet = 0;
	
	obj.InsertFirst(51);
	obj.InsertFirst(21);
	obj.InsertFirst(11);
	
	obj.InsertLast(101);
	obj.InsertLast(111);
	
	obj.InsertAtPos(212,2);
	obj.InsertAtPos(45,4);
	
	obj.DeleteFirst();
	
	obj.DeleteLast();
	
	obj.DeleteAtPos(3);
	
	obj.Display();
	
	iRet = obj.Count();
	cout<<"Number of elements are : "<<iRet<<"\n";
	
	return 0;
}

/*

1:
while(temp != NULL)
{
	temp = temp -> next;
}

---------------------------------------
2:
while(temp -> next != NULL)
{
	temp = temp -> next;
}

---------------------------------------
3:
while(temp -> next -> next)
{
	temp = temp -> next;
}

*/