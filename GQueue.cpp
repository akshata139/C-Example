///////////////////////////////////////////////////////////////////////////////
//
// Description  : Queue using generic function.
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
class Queue	
{
	private:
		node <T>* first;
		int size;
	
	public:
		Queue();
		void Enqueue(T);
		int Dequeue();
		void Display();
		int Count();
		int Minimum();
		int Maximum();
		
};

template <typename T>
Queue <T> :: Queue()
{
	first = NULL;
	size = 0;
}
		
template <typename T>
void Queue <T> :: Enqueue(T no)
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
		node <T>* temp = first;
		
		while((temp -> next) != NULL)
		{
			temp = temp -> next;
		}
		
		temp -> next = newn;
	}
			
		size++;
}
		
template <typename T>
int Queue <T> :: Dequeue()
{	
	int outelement = 0;
			
	if(size == 0)
	{
		cout<<"Queue is empty\n";
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
void Queue <T> :: Display()
{
	node <T>* temp = first;
			
	while(temp != NULL)
	{
		cout<<"|"<<temp -> data<<"| -> ";
		temp = temp -> next;
	}
			
	cout<<"\n";
}

template <typename T>
int Queue<T> :: Minimum() 
{
	node <T>* temp = first;
	
	int iMin = temp -> data;
	
	while(temp != NULL)
	{
		if((temp -> data) < iMin)
		{
			iMin = temp -> data;
		}
		
		temp = temp -> next;
	}
	
	return iMin;
}

template <typename T>
int Queue<T> :: Maximum() 
{
	node <T>* temp = first;
	
	int iMax = 0;
	
	while(temp != NULL)
	{
		if((temp -> data) > iMax)
		{
			iMax = temp -> data;
		}
		
		temp = temp -> next;
	}
	
	return iMax;
}

template <typename T>		
int Queue <T> :: Count()
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
	Queue <int>iobj;
	int iValue = 0,iChoice = 1,iRet = 0,iRet1 = 0,iRet2 = 0;
	
	while(iChoice != 0)
	{
		cout<<"\nEntered desired choice you want to perform on Queue : \t";
		cout<<"\n_______________________________________________________________________________\n";
		cout<<"1. Enqueue element in Queue .\n";
		cout<<"2. Dequeue element from Queue.\n";
		cout<<"3. Display the contents of Queue.\n";
		cout<<"4. Count the number of elements.\n";
		cout<<"5. Find the Smallest number from queue.\n";
		cout<<"6. Find the largest number from queue.\n";
		cout<<"0. Terminate the application.\n";
		cout<<"\n_______________________________________________________________________________\n";
		
		cin>>iChoice;
		
		switch(iChoice)
		{
			case 1:
				cout<<"Enter element you want to insert : \n";
				cin>>iValue;
				iobj.Enqueue(iValue);
				break;
				
			case 2:
				iobj.Dequeue();
				break;
				
			case 3:
				cout<<"Elemets are : \n";
				iobj.Display();
				break;
				
			case 4:
				iRet = iobj.Count();
				cout<<"Number of elements are : "<<iRet<<"\n";
				break;
				
			case 5:
				iRet1 = iobj.Minimum();
				cout<<"Smallest number from queue is : "<<iRet1<<"\n";
				break;
				
			case 6:
				iRet2 = iobj.Maximum();
				cout<<"Largest number from queue is : "<<iRet2<<"\n";
				break;
				
			case 0:
				cout<<"Thanks for using Queue!!\n";
				break;
				
			default:
				cout<<"Please entered desired choice.\n";
				break;		
		}	
	}
	return 0;
}