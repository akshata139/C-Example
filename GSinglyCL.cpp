///////////////////////////////////////////////////////////////////////////////
//
// Description  : Singly Circular linked list using generic function.
// Author 		: Akshata Kalaskar
// Date 		: 18/11/2021
//
//////////////////////////////////////////////////////////////////////////////

#include<iostream>
using namespace std;

/////////////////////////////////////////////////////////////////////////////
//
// Description : Structure decleration;
//
/////////////////////////////////////////////////////////////////////////////

template <typename T>
struct node
{
	T data;
	struct node *next;
	
};

/////////////////////////////////////////////////////////////////////////////
//
// Description : Class Decleration;
//
/////////////////////////////////////////////////////////////////////////////

template <typename T>
class SinglyCL
{
	private:
		node <T>* first;
		node <T>* last;
		int iSize;
		
	public:
		SinglyCL();
		void Display();
		int Count();
		void InsertFirst(T);
		void InsertLast(T);
		void InsertAtPos(T,int);
		void DeleteFirst();
		void DeleteLast();
		void DeleteAtPos(int);
		
};

template <typename T>
SinglyCL <T> :: SinglyCL()
{
	first = NULL;
	last = NULL;
	iSize = 0;
}

template <typename T>
void SinglyCL <T> :: Display()
{
	node <T>* temp =first;
	
	for(int i = 1;i <= iSize;i++)
	{
		cout<<"|"<<temp -> data<<"| -> ";
		temp = temp -> next;
	}
	
	cout<<"\n";
}

template <typename T>
void SinglyCL<T> :: InsertFirst(T iNo)
{
	node <T>* newn = new node <T>;
	
	newn -> data = iNo;
	newn -> next = NULL;
	
	if((first == NULL) && (last == NULL))
	{
		first = newn;
		last = newn;
	}
	else
	{
		newn -> next = first;
		first = newn;
	}
	
	last -> next = first;
	iSize++;
}

template <typename T>
void SinglyCL<T> :: InsertLast(T iNo)
{
	node <T>* newn = new node <T>;
	
	newn -> data = iNo;
	newn -> next = NULL;
	
	if((first == NULL) && (last == NULL))
	{
		first = newn;
	}
	else
	{
		last -> next = newn;
		last = newn;
	}
	
	last -> next = first;
	iSize++;
}

template <typename T>
void SinglyCL<T> :: InsertAtPos(T iNo, int iPos)
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
		node <T>* newn = new  node <T>;
		node <T>* temp = first;
		
		newn -> data = iNo;
		newn -> next = NULL;
		
		for(int i = 1;i < (iPos - 1);i++)
		{
			temp = temp -> next;
		}
		
		newn -> next = temp -> next;
		temp -> next = newn;
		iSize++;
	}
}

template <typename T>
void SinglyCL<T> :: DeleteFirst()
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
		
		iSize--;
	}
	else
	{	
		first = first -> next;
		delete last -> next;
		last -> next = first;
		
		iSize--;
	}
}

template <typename T>
void SinglyCL<T> :: DeleteLast()
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
		
		iSize--;
	}
	else
	{
		node <T>* temp = first;
		
		while((temp -> next) != last)
		{
			temp = temp -> next;
		}
		
		delete last;
		last = temp;
		
		last -> next = first;
		iSize--;
	}
	
}

template <typename T>
void SinglyCL <T> :: DeleteAtPos(int iPos)
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
		node <T>* temp = first;
		node <T>* targated = NULL;
		
		for(int i = 1;i < (iPos - 1);i++);
		{
			temp = temp -> next;
		}
		
		targated = temp -> next;
		temp -> next = targated -> next;
		delete targated;
		
		iSize--;
	}

}

template <typename T>
int SinglyCL<T> :: Count()
{
	return iSize;
}

//////////////////////////////////////////////////////////////////////
//
//Description : Starting of main function;
//
//////////////////////////////////////////////////////////////////////

int main()
{
	
	SinglyCL <int>iobj;
	
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
				iobj.InsertFirst(iValue);
				break;
				
			case 2:
				cout<<"Enter element you want to insert : \n";
				cin>>iValue;
				iobj.InsertLast(iValue);
				break;

			case 3:
				cout<<"Enter element you want to insert : \n";
				cin>>iValue;
				cout<<"Enter position : ";
				cin>>position;
				iobj.InsertAtPos(iValue,position);
				break;
				
			case 4:
				iobj.DeleteFirst();
				break;
				
			case 5:
				iobj.DeleteLast();
				break;
				
			case 6:
				cout<<"Enter position : \n";
				cin>>position;
				iobj.DeleteAtPos(position);
				break;
				
			case 7:
				cout<<"Elemets are : \n";
				iobj.Display();
				break;
				
			case 8:
				iRet = iobj.Count();
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