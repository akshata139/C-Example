//Menu driven : doubly circular linked list.

#include<iostream>
using namespace std;

typedef struct node
{
	int data;
	struct node *next;
	struct node *prev;
	
}NODE,*PNODE;

class DoublyCL
{
	private:
		PNODE first;
		PNODE last;
		int size;
		
	public:
		DoublyCL()
		{
			first = NULL;
			last = NULL;
			size = 0;
		}
		
		void Display();
		int Count();
		void InsertFirst(int no);
		void InsertLast(int no);
		void InsertAtPos(int no,int ipos);
		void DeleteFirst();
		void DeleteLast();
		void DeleteAtPos(int ipos);
		
};

void DoublyCL :: Display()
{
	PNODE temp = first;
	
	for(int i = 1;i <= size;i++)
	{
		cout<<"|"<<temp -> data<<"| -> ";
		temp = temp -> next;
	}
	
	cout<<"\n";
} 

int DoublyCL :: Count()
{
	return size;
}

void DoublyCL :: InsertFirst(int no)
{
	PNODE newn = new NODE;
	
	newn -> data = no;
	newn -> next = NULL;
	newn -> prev = NULL;
	
	if((first == NULL) && (last == NULL))
	{
		first = newn;
		last = newn;
	}
	else
	{
		newn -> next = first;
		first -> prev = newn;
		first = newn;
	}
	
	first -> prev = last;
	last -> next = first;
	size++;	
}

void DoublyCL :: InsertLast(int no)
{
	PNODE newn = new NODE;
	
	newn -> data = no;
	newn -> next = NULL;
	newn -> prev = NULL;
	
	if((first == NULL) && (last == NULL))
	{
		first = newn;
		last = newn;
	}
	else
	{
		last -> next = newn;
		newn -> prev = last;
		last = newn;
	}
	
	first -> prev = last;
	last -> next = first;
	size++;	
}

void DoublyCL :: InsertAtPos(int no,int ipos)
{
	if((ipos < 1) || (ipos > (size + 1)))
	{
		return;
	}
	
	if(ipos == 1)
	{
		InsertFirst(no);
	}
	else if(ipos == size)
	{
		InsertLast(no);
	}
	else
	{
	 	PNODE newn = new NODE;
		PNODE temp = first;
		
		newn -> data = no;
		newn -> next = NULL;
		newn -> prev = NULL;
		
		for(int i = 1;i < (ipos - 1);i++)
		{
			temp = temp -> next;
		}
		
		newn -> next = temp -> next;
		temp -> next -> prev = newn;
		newn -> prev = temp;
		temp -> next = newn;
		
		size++;
		
	}
		
}

void DoublyCL :: DeleteFirst()
{
	if((first == NULL) && (last == NULL))
	{
		return;
	}
	else if(first == last)
	{
		delete first;
		first == NULL;
		last = NULL;
	}
	else
	{
		first = first -> next;
		delete first -> prev;
		first -> prev = last;
		last -> next = first;
	}
	
	size--;
}

void DoublyCL :: DeleteLast()
{
	if((first == NULL) && (last == NULL))
	{
		return;
	}
	else if(first == last)
	{
		delete first;
		first == NULL;
		last = NULL;
	}
	else
	{
		last = last -> prev;
		delete last -> next;
		first -> prev = last;
		last -> next = first;
	}
	
	size--;
}

void DoublyCL :: DeleteAtPos(int ipos)
{
	if((ipos < 1) || (ipos > size))
	{
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
		PNODE temp = first;
		
		for(int i = 1;i < (ipos - 1);i++)
		{
			temp = temp -> next;
		}
		
		temp -> next = temp -> next -> next;
		delete temp -> next -> prev;
		temp -> next -> prev = temp;
		size--;
	}
	
}

int main()
{
	DoublyCL obj;
	
	int iValue = 0,iChoice = 1,position = 0,iRet = 0;
	
	while(iChoice != 0)
	{
		cout<<"\nEntered desired choice you want to perform on linked list : \t";
		cout<<"\n_______________________________________________________________________________\n";
		cout<<"1. Insert Node at first position.\n";
		cout<<"2. Insert node at last position.\n";
		cout<<"3. Insert node at desired position.\n";
		cout<<"4. Delete First node.\n";
		cout<<"5. Delete Last node.\n";
		cout<<"6. Delete node from desired position.\n";
		cout<<"7. Display the contents of linked list.\n";
		cout<<"8. Count the number of elements.\n";
		cout<<"0. Terminate the application.\n";
		cout<<"\n_______________________________________________________________________________\n";
		
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
				cout<<"Enter position : ";
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
				cout<<"Elemets are : \n";
				obj.Display();
				break;
				
			case 8:
				iRet = obj.Count();
				cout<<"Number of elements are : "<<iRet<<"\n";
				break;
				
			case 0:
				cout<<"Thank you for using linked list!!\n";
				break;
				
			default:
				cout<<"Please entered desired choice.\n";
				break;
			
		}
		
	}
	
	return 0;
}