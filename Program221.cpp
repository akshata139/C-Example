#include<iostream>
using namespace std;

typedef struct node
{
	int data;
	struct node *next;
	struct node *prev;
	
}NODE, *PNODE, **PPNODE;

class SinglyCLL
{
	private:
		PNODE first;
		int iSize;
		
	public:
		SinglyCLL()
		{
			first = NULL;
			iSize = 0;
		}
		
		void InsertFirst(int iNo)
		{
			PNODE newn = new NODE;
			
			newn -> data = iNo;
			newn -> next = NULL;
			newn -> prev = NULL;
			
			if(first == NULL)
			{
				first = newn;
			}
			else
			{
				newn -> next = first;
				first -> prev = newn;
				
				first = newn;
			}
			
			iSize++;
		}
		
		void InsertLast(int iNo)
		{	
			
			PNODE newn = new NODE;
			
			newn -> data = iNo;
			newn -> next = NULL;
			newn -> prev = NULL;
			
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
				newn -> prev = temp;
			}
			
			iSize++;
		}
		
		void InsertAtPos(int iNo,int iPos)
		{
			PNODE temp = first;
			
			if((iPos < 1) || (iPos > (iSize + 1)))
			{
				return;
			}
			
			if(iPos == 1)
			{
				InsertFirst(iNo);
			}
			else if(iPos == (iSize + 1))
			{
				InsertLast(iNo);
			}
			else
			{
				PNODE newn = new NODE;
				int i = 0;
				
				newn -> data = iNo;
				newn -> next = NULL;
				newn -> prev = NULL;
				
				for(i = 1;i < (iPos - 1);i++)
				{
					temp = temp -> next;
				}
				
				newn -> next = temp -> next;
				temp -> next -> prev = newn;
				temp -> next = newn;
				newn -> prev = temp;
				
				iSize++;
			}
		}
		
		void DeleteFirst()
		{
			if(first == NULL)
			{
				return;
			}
			else if(first -> next == NULL)
			{
				delete (first);
				first = NULL;
				
			}
			else
			{
				first = first -> next;
				delete (first -> prev);
				first -> prev = NULL;
			
			}
			
			iSize--;
		}
		
		void DeleteLast()
		{
			PNODE temp = first;
			
			if(first == NULL)
			{
				return;
			}
			else if((first -> next) == NULL)
			{
				delete first;
				first = NULL;
				
			}
			else
			{
				while((temp -> next) != NULL)
				{
					temp = temp -> next;
				}
				
				delete temp;
				temp -> prev -> next = NULL;
				
			}
			
			iSize--;
		}
		
		void DeleteAtPos(int iPos)
		{
			PNODE temp = first;
			int i = 0;
			
			if((iPos < 1) || (iPos > iSize))
			{
				return;
			}
			
			if(iPos == 1)
			{
				DeleteFirst();
			}
			else if(iPos == iSize)
			{
				DeleteLast();
			}
			else
			{	
				for(i = 1;i < (iPos - 1);i++)
				{
					temp = temp -> next;
				}
				
				temp -> next = temp -> next -> next;
				delete (temp -> next -> prev);
				temp -> next -> prev = temp;
				iSize--;
			}

		}
		
		void Display()
		{
			while(first != NULL)
			{
				cout<<first -> data <<"  ->\t";
				first = first -> next;
			}
			cout<<"NULL\n";
		}
		
		int Count()
		{
			return iSize;
		}
};

int main()
{
	int iValue = 0,iRet = 0,iChoice = 1,position = 0;
	
	SinglyCLL obj;
	
	while(iChoice != 0)
	{
		cout<<"\nEnter valid choice you want to perform on linked list : \n";
		cout<<"_________________________________________________________________________\n";
		cout<<"1. Insert element at first position. \n";
		cout<<"2. Insert element at last position. \n";
		cout<<"3. Insert element at desired position. \n";
		cout<<"4. Delete first element.\n";
		cout<<"5. Delete last element.\n";
		cout<<"6. Delete element from desired position.\n";
		cout<<"7. Display elements of linked list.\n";
		cout<<"8. Count number of elements of linked list.\n";
		cout<<"0. Terminate the program.\n";
		cout<<"_________________________________________________________________________\n";
		
		cin>>iChoice;
		
		switch(iChoice)
		{
			case 1:
				cout<<"Enter element you want to insert : \n";
				cin>>iValue;
				obj.InsertFirst(iValue);
				break;
				
			case 2:
				cout<<"Enter element you want to insert : \n";
				cin>>iValue;
				obj.InsertLast(iValue);
				break;
				
			case 3:
				cout<<"Enter element you want to insert : \n";
				cin>>iValue;
				cout<<"Enter position : \n";
				cin>>position;
				obj.InsertAtPos(iValue,position);
				break;
				
			case 4:
				obj.DeleteFirst();
				break;
				
			case 5:
				obj.DeleteLast();
				break;
				
			case 6:
				cout<<"Enter position : \n";
				cin>>position;
				obj.DeleteAtPos(position);
				break;
				
			case 7:
				cout<<"Elements are : \n";
				obj.Display();
				break;
				
			case 8:
				iRet = obj.Count();
				cout<<"Total number of elements are : \t"<<iRet;
				break;
				
			case 0:
				cout<<"Thanks for using singly circular linked list!!\n";
				break;
				
			default:
				cout<<"please Enter valid choice .\n";
				break;
		}
	}
	
	return 0;
}