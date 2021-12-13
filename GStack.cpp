///////////////////////////////////////////////////////////////////////////////
//
// Description  : Stack using generic function.
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

///////////////////////////////////////////////////////////////////////////////
//
// Description : Decleration of class.
//
///////////////////////////////////////////////////////////////////////////////

template <typename T>
class Stack	
{
	private:
		node <T>* first;
		int size;
	
	public:
		Stack();
		void Push(T);
		int Pop();
		void Display();
		int Count();
		
};

template <typename T>
Stack <T> :: Stack()
{
	first = NULL;
	size = 0;
}
		
template <typename T>
void Stack <T> :: Push(T no)
{
	node <T>* newn = new node <T>;
			
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
		
template <typename T>
int Stack <T> :: Pop()
{	
	int outelement = 0;
			
	if(size == 0)
	{
		cout<<"Stack is empty\n";
		return -1;
	}
			
	if(size == 1)
	{
		outelement = first -> data;
		delete first;
		first = NULL;
	}
	else
	{
		node <T>* temp = first;
				
		outelement = first -> data;
		first = first -> next;
		delete temp;
	}
	size--;
	return outelement;
}

template <typename T>
void Stack <T> :: Display()
{
	node <T>* temp = first;
			
	while(temp != NULL)
	{
		cout<<"|"<<temp -> data<<"|\n";
		temp = temp -> next;
	}
			
	cout<<"\n";
}

template <typename T>		
int Stack <T> :: Count()
{
	return size;
}

///////////////////////////////////////////////////////////////////////////////
//
// Description : Starting of main function.
//
//////////////////////////////////////////////////////////////////////////////

int main()
{
	Stack <int>iobj;
	int iValue = 0,iChoice = 1,iRet = 0;
	
	while(iChoice != 0)
	{
		cout<<"\nEntered desired choice you want to perform on Stack : \t";
		cout<<"\n_______________________________________________________________________________\n";
		cout<<"1. Push element in Stack .\n";
		cout<<"2. Pop element from Stack.\n";
		cout<<"3. Display the contents of Stack.\n";
		cout<<"4. Count the number of elements.\n";
		cout<<"0. Terminate the application.\n";
		cout<<"\n_______________________________________________________________________________\n";
		
		cin>>iChoice;
		
		switch(iChoice)
		{
			case 1:
				cout<<"Enter element you want to insert : \n";
				cin>>iValue;
				iobj.Push(iValue);
				break;
				
			case 2:
				iobj.Pop();
				break;
				
			case 3:
				cout<<"Elemets are : \n";
				iobj.Display();
				break;
				
			case 4:
				iRet = iobj.Count();
				cout<<"Number of elements are : "<<iRet<<"\n";
				break;
				
			case 0:
				cout<<"Thanks for using Stack!!\n";
				break;
				
			default:
				cout<<"Please entered desired choice.\n";
				break;		
		}	
	}
	return 0;
}