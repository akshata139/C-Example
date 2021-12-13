#include<iostream>
using namespace std;

typedef struct node
{
	int data;
	struct node *next;
	
}NODE,*PNODE;

class SinglyCL
{
	private:
		PNODE first;
		PNODE last;
		int iSize;
		
	public:
		SinglyCL()
		{
			first = NULL;
			last = NULL;
			iSize = 0;
		}
		
		void Display()
		{
			PNODE temp = first;
			
			do
			{
				cout<<"|"<<temp-> data<<"| -> \t";
				temp = temp -> next;
				
			}while(temp != (last -> next));
				
			cout<<"\n";
		}
		
		int Count()
		{
			return iSize;
		}
		
		void InsertFirst(int iNo)
		{
			PNODE newn = new NODE;
			
			newn -> data = iNo;
			newn -> next = NULL;
			
			if((first == NULL) && (last == NULL))
			{
				first = newn;
				last = newn;
				iSize++;
			}
			else
			{
				newn -> next = first;
				first = newn;
			}
			
			last -> next = first;
			iSize++;
		}
		
		void InsertLast(int iNo)
		{
			PNODE newn = new NODE;
			
			newn -> data = iNo;
			newn -> next = NULL;
			
			if((first == NULL) && (last == NULL))
			{
				first = newn;
				last = newn;
				iSize++;
			}
			else
			{
				last -> next = newn;
				last = newn;
			}
			
			last -> next = first;
			iSize++;
		}
		
		void InsertAtPos(int iNo,int iPos)
		{
			
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
				
				newn -> data = iNo;
				newn -> next = NULL;

				PNODE temp = first;
			
				for(int i = 1;i < (iPos - 1);i++)
				{
					temp = temp -> next;
				}
				
				newn -> next = temp -> next;
				temp -> next = newn;
				
				iSize++;
			}
		}
		
		void DeleteFirst()
		{
			if((first == NULL) && (last == NULL))
			{
				return;
			}
			else if(first == last)
			{
				delete first;
				first = NULL;
				last = NULL;
			}
			else
			{
				first = first -> next;
				delete last -> next;
				last -> next = first;
			}
			
			iSize--;
		}
		
		void DeleteLast()
		{
			if((first == NULL) && (last == NULL))
			{
				return;
			}
			else if(first == last)
			{
				delete first;
				first = NULL;
				last = NULL;
			}
			else
			{
				PNODE temp = first;
			
				while(temp -> next != last)
				{
					temp = temp -> next;
				}
			
				delete last;
				last = temp;
			
				last -> next = first;
			}
			
			iSize--;
		}
		
		void DeleteAtPos(int iPos)
		{
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
				PNODE temp = first;
				PNODE targated = NULL;
				
				for(int i = 1;i < (iPos - 1);i++)
				{
					temp = temp -> next;
				}
				
				targated = temp -> next;
				temp -> next = targated -> next;
				
				delete targated;
				
				iSize--;
			}
		}
		
};

int main()
{
	SinglyCL obj;
	int iChoice = 1,iValue = 0,position = 0,iRet = 0;
	
	while(iChoice != 0)
	{
		cout<<"Enter desired choice you want to perform on linked list : \n";
		cout<<"___________________________________________________________________________\n";
		cout<<"1. Insert node at first position.\n";
		cout<<"2. Insert node at last position.\n";
		cout<<"3. Insert node at the desired position.\n";
		cout<<"4. Delete first node.\n";
		cout<<"5. Delete last node.\n";
		cout<<"6. Delete node from given position.\n";
		cout<<"7.  Display the contents of linked list.\n";
		cout<<"8. Count the number of nodes.\n";
		cout<<"0. terminate the application.\n";
		cout<<"___________________________________________________________________________\n";
		
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
				cout<<"Number of elements are : \t"<<iRet<<"\n";
				break;
				
			case 0:
				cout<<"\nThanks for using linked list !!\n";
				break;
				
			default:
				cout<<"Please enter desired choice!\n";
				break;
				
		}
	}
	
	return 0;
}