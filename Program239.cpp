//Generic programming
//encapsulation,abstraction.
//error : typedef cannot be a template!!;

#include<iostream>
using namespace std;

template <typename T>		//template header
struct node
{
	T data;
	struct node *next;
	
};

template <class T>
class SinglyLL
{
	private:
		node<T>* first;
		int size;
		
	public:
		SinglyLL();
		void InsertFirst(T);
		void InsertLast(T);
		void InsertAtPos(T,int);
		void DeleteFirst();
		void DeleteLast();
		void DeleteAtPos(int);
		void Display();
		int Count();
		
};

template <class T>
SinglyLL<T> :: SinglyLL()
{
	first = NULL;
	size = 0;
}
		
template <class T>
void SinglyLL<T> :: InsertFirst(T no)
	{
		node <T> * newn = new node<T>; //newn = (PNODE)malloc(sizeof(NODE))
			
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
		template <class T>
		void SinglyLL<T> :: InsertLast(T no)
		{
			node <T> * newn = new node<T>; //newn = (PNODE)malloc(sizeof(NODE))
			
			newn -> data = no;
			newn -> next = NULL;
			
			if(first == NULL)
			{
				first = newn;
			}
			else
			{
				node <T> * temp = first;
				
				while((temp -> next) != NULL)
				{
					temp = temp -> next;
				}
				temp -> next = newn;
			}
			size++;
		}
		
		template <class T>
		void SinglyLL<T> :: InsertAtPos(T no,int ipos)
		{	
			node <T> * temp = first;
			
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
				node <T> * newn = new node<T>;
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
		
		template <class T>
		void SinglyLL<T> :: DeleteFirst()
		{
			node <T> * temp = first;
			
			if(first != NULL)		//size != 0
			{
				first = first -> next;
				delete temp;
				
				size--;
			}
		}
		
		template <class T>
		void SinglyLL<T> :: DeleteLast()
		{
			node <T> * temp = first;
			
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
		
		template <class T>
		void SinglyLL<T> :: DeleteAtPos(int ipos)
		{
			node <T> * temp = first;
			node <T> * targated = NULL;
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
		
		template <class T>
		void SinglyLL<T> :: Display()
		{
			node <T> * temp = first;
			
			while(temp != NULL)
			{
				cout<<temp -> data<<"\t";
				temp = temp -> next;
			}
			
			cout<<"\n";
		}
		
		template <class T>
		int SinglyLL<T> :: Count()
		{
			return size;
		}

////////////////////////////////////////////////////////////////

int main()
{
	int iRet = 0;
	
	SinglyLL <char>cobj;
	
	cobj.InsertFirst('A');
	cobj.InsertFirst('B');
	cobj.InsertFirst('C');
	
	cobj.InsertLast('D');
	cobj.InsertLast('E');
	
	cobj.InsertAtPos('F',2);
	cobj.InsertAtPos('G',4);
	
	cobj.DeleteFirst();
	
	cobj.DeleteLast();
	
	cobj.DeleteAtPos(3);
	
	cobj.Display();
	
	iRet = cobj.Count();
	cout<<"Number of elements are : "<<iRet<<"\n";
	
	/////////////////////////////////////////////////////////////////////////
	
	SinglyLL <int>iobj;
	
	iobj.InsertFirst(11);
	iobj.InsertFirst(21);
	iobj.InsertFirst(31);
	
	iobj.InsertLast(41);
	iobj.InsertLast(51);
	
	iobj.InsertAtPos(61,2);
	iobj.InsertAtPos(71,4);
	
	iobj.DeleteFirst();
	
	iobj.DeleteLast();
	
	iobj.DeleteAtPos(3);
	
	iobj.Display();
	
	iRet = iobj.Count();
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