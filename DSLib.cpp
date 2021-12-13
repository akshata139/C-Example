#include<iostream>
using namespace std;

/////////////////////////////////////////////////////////////////////////////////////////////////
//
// Description : Structure decleration for singly linear, singly circular LL,Stack ,Queue ;
//
//////////////////////////////////////////////////////////////////////////////////////////////////

template <typename T>
struct node1
{
	T data;
	struct node1 *next;
	
};


///////////////////////////////////////////////////////////////////////////////
//
// Description  : Singly linear linked list.
// Author 		: Akshata Kalaskar
// Date 		: 18/11/2021
//
//////////////////////////////////////////////////////////////////////////////

//Decleration of class of SinglyLL

template <typename T>
class SinglyLL
{
	private:
		node1 <T>* first;
		int iSize;
		
	public:
		SinglyLL();
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
SinglyLL <T> :: SinglyLL()
{
	first = NULL;
	iSize = 0;
}

template <typename T>
void SinglyLL <T> :: Display()
{
	node1 <T>* temp =first;
	
	for(int i = 1;i <= iSize;i++)
	{
		cout<<"|"<<temp -> data<<"| -> ";
		temp = temp -> next;
	}
	
	cout<<"\n";
}

template <typename T>
void SinglyLL<T> :: InsertFirst(T iNo)
{
	node1 <T>* newn = new node1 <T>;
	
	newn -> data = iNo;
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
	
	iSize++;
}

template <typename T>
void SinglyLL<T> :: InsertLast(T iNo)
{
	node1 <T>* newn = new node1 <T>;
	
	newn -> data = iNo;
	newn -> next = NULL;
	
	if(first == NULL)
	{
		first = newn;
	}
	else
	{
		node1 <T>* temp = first;
		
		while(temp -> next != NULL)
		{
			temp = temp -> next;
		}
		
		temp -> next = newn;
	}
	
	iSize++;
}

template <typename T>
void SinglyLL<T> :: InsertAtPos(T iNo, int iPos)
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
		node1 <T>* newn = new  node1 <T>;
		node1 <T>* temp = first;
		
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
void SinglyLL<T> :: DeleteFirst()
{
	if(first == NULL)
	{
		return;
	}
	else if(first -> next == NULL)
	{
		delete first;
		first = NULL;
	}
	else
	{
		node1 <T>* temp = first;
		
		first = first -> next;
		delete temp;
	}
	
	iSize--;
}

template <typename T>
void SinglyLL<T> :: DeleteLast()
{
	if(first == NULL)
	{
		return;
	}
	else if(first -> next == NULL)
	{
		delete first;
		first = NULL;
	}
	else
	{
		node1 <T>* temp = first;
		
		while((temp -> next -> next != NULL))
		{
			temp = temp -> next;
		}
		
		delete temp -> next;
		temp -> next = NULL;
	}
	
	iSize--;
}

template <typename T>
void SinglyLL <T> :: DeleteAtPos(int iPos)
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
		node1 <T>* temp = first;
		node1 <T>* targated = NULL;
		
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
int SinglyLL<T> :: Count()
{
	return iSize;
}

/////////////////////////////////////////////////////////////////
//
//End of SinglyLL
//
////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////
//
// Description  : Singly Circular linked list using generic function.
// Author 		: Akshata Kalaskar
// Date 		: 18/11/2021
//
//////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////
//
// Description : Class Decleration for Singly Circular LL;
//
/////////////////////////////////////////////////////////////////////////////

template <typename T>
class SinglyCL
{
	private:
		node1 <T>* first;
		node1 <T>* last;
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
	node1 <T>* temp =first;
	
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
	node1 <T>* newn = new node1 <T>;
	
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
	node1 <T>* newn = new node1 <T>;
	
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
		node1 <T>* newn = new  node1 <T>;
		node1 <T>* temp = first;
		
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
		node1 <T>* temp = first;
		
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
		node1 <T>* temp = first;
		node1 <T>* targated = NULL;
		
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
///////////////////////////////////////////////////////////////
//
//End of Singly Circular LL
//
///////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////
//
// Description  : Doubly linear linked list.
// Author 		: Akshata Kalaskar
// Date 		: 18/11/2021
//
//////////////////////////////////////////////////////////////////////////////


//////////////////////////////////////////////////////////////////////////////
//
// Description : Structure decleration for doubly linear and doubly circular LL
//
//////////////////////////////////////////////////////////////////////////////

template <typename T>
struct node2
{
	T data;
	struct node2 *next;
	struct node2 *prev;
	
};

/////////////////////////////////////////////////////////////////////////////
//
// Description : Class Decleration for Doubly Linear LL;
//
/////////////////////////////////////////////////////////////////////////////

template <typename T>
class DoublyLL
{
	private:
		node2 <T>* first;
		int iSize;
		
	public:
		DoublyLL();
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
DoublyLL <T> :: DoublyLL()
{
	first = NULL;
	iSize = 0;
}

template <typename T>
void DoublyLL <T> :: Display()
{
	node2 <T>* temp =first;
	
	for(int i = 1;i <= iSize;i++)
	{
		cout<<"|"<<temp -> data<<"| -> ";
		temp = temp -> next;
	}
	
	cout<<"\n";
}

template <typename T>
void DoublyLL<T> :: InsertFirst(T iNo)
{
	node2 <T>* newn = new node2 <T>;
	
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

template <typename T>
void DoublyLL<T> :: InsertLast(T iNo)
{
	node2 <T>* newn = new node2 <T>;
	
	newn -> data = iNo;
	newn -> next = NULL;
	newn -> prev = NULL;
	
	if(first == NULL)
	{
		first = newn;
	}
	else
	{
		node2 <T>* temp = first;
		
		while(temp -> next != NULL)
		{
			temp = temp -> next;
		}
		
		temp -> next = newn;
		newn -> prev = temp;
	}
	
	iSize++;
}

template <typename T>
void DoublyLL<T> :: InsertAtPos(T iNo, int iPos)
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
		node2 <T>* newn = new  node2 <T>;
		node2 <T>* temp = first;
		
		newn -> data = iNo;
		newn -> next = NULL;
		newn -> prev = NULL;
		
		for(int i = 1;i < (iPos - 1);i++)
		{
			temp = temp -> next;
		}
		
		newn -> next = temp -> next;
		temp -> next -> prev = newn;
		newn -> prev = temp;
		temp -> next = newn;
		iSize++;
	}
}

template <typename T>
void DoublyLL<T> :: DeleteFirst()
{
	if(first == NULL)
	{
		return;
	}
	else if(first -> next == NULL)
	{
		delete first;
		first = NULL;
	}
	else
	{
		first = first -> next;
		delete first -> prev;
		first -> prev = NULL;
	}
	
	iSize--;
}

template <typename T>
void DoublyLL<T> :: DeleteLast()
{
	if(first == NULL)
	{
		return;
	}
	else if(first -> next == NULL)
	{
		delete first;
		first = NULL;
	}
	else
	{
		node2 <T>* temp = first;
		
		while((temp -> next) != NULL)
		{
			temp = temp -> next;
		}
		
		temp -> prev -> next = NULL;
		delete temp;
	}
	
	iSize--;
}

template <typename T>
void DoublyLL <T> :: DeleteAtPos(int iPos)
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
		node2 <T>* temp = first;
		
		for(int i = 1;i < (iPos - 1);i++);
		{
			temp = temp -> next;
		}
		
		temp -> next = temp -> next -> next;
		delete temp -> next -> prev;
		temp -> next -> prev = temp;
		
		iSize--;
	}

}

template <typename T>
int DoublyLL<T> :: Count()
{
	return iSize;
}

////////////////////////////////////////////////////////////////
//
//End of Doubly Linear LL
//
////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////
//
// Description  : Doubly Circular linked list using generic function.
// Author 		: Akshata Kalaskar
// Date 		: 18/11/2021
//
//////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////
//
// Description : Class Decleration for Doubly Circular LL;
//
/////////////////////////////////////////////////////////////////////////////

template <typename T>
class DoublyCL
{
	private:
		node2 <T>* first;
		node2 <T>* last;
		int iSize;
		
	public:
		DoublyCL();
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
DoublyCL <T> :: DoublyCL()
{
	first = NULL;
	last = NULL;
	iSize = 0;
}

template <typename T>
void DoublyCL <T> :: Display()
{
	node2 <T>* temp =first;
	
	for(int i = 1;i <= iSize;i++)
	{
		cout<<"|"<<temp -> data<<"| -> ";
		temp = temp -> next;
	}
	
	cout<<"\n";
}

template <typename T>
void DoublyCL<T> :: InsertFirst(T iNo)
{
	node2 <T>* newn = new node2 <T>;
	
	newn -> data = iNo;
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
	
	last -> next = first;
	first -> prev = last;
	iSize++;
}

template <typename T>
void DoublyCL<T> :: InsertLast(T iNo)
{
	node2 <T>* newn = new node2 <T>;
	
	newn -> data = iNo;
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
	
	last -> next = first;
	first -> prev = last;
	iSize++;
}

template <typename T>
void DoublyCL<T> :: InsertAtPos(T iNo, int iPos)
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
		node2 <T>* newn = new  node2 <T>;
		node2 <T>* temp = first;
		
		newn -> data = iNo;
		newn -> next = NULL;
		newn -> prev = NULL;
		
		for(int i = 1;i < (iPos - 1);i++)
		{
			temp = temp -> next;
		}
		
		newn -> next = temp -> next;
		temp -> next -> prev = newn;
		newn -> prev = temp;
		temp -> next = newn;
		iSize++;
	}
}

template <typename T>
void DoublyCL<T> :: DeleteFirst()
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
		delete first -> prev;
		
		first -> prev = last;
		last -> next = first;
		iSize--;
	}
	
}

template <typename T>
void DoublyCL<T> :: DeleteLast()
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
		last = last -> prev;
		delete first -> prev;
		
		first -> prev = last;
		last -> next = first;
		iSize--;
	}

}

template <typename T>
void DoublyCL <T> :: DeleteAtPos(int iPos)
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
		node2 <T>* temp = first;
		
		for(int i = 1;i < (iPos - 1);i++);
		{
			temp = temp -> next;
		}
		
		temp -> next = temp -> next -> next;
		delete temp -> next -> prev;
		temp -> next -> prev = temp;
		
		iSize--;
	}

}

template <typename T>
int DoublyCL<T> :: Count()
{
	return iSize;
}

///////////////////////////////////////////////////////////////
//
//End of Doubly Circular LL
//
///////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////
//
// Description  : Stack using generic function.
// Author 		: Akshata Kalaskar
// Date 		: 18/11/2021
//
//////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////
//
// Description : Decleration of class for Stack.
//
///////////////////////////////////////////////////////////////////////////////

template <typename T>
class Stack	
{
	private:
		node1 <T>* first;
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
	node1 <T>* newn = new node1 <T>;
			
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
		node1 <T>* temp = first;
				
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
	node1 <T>* temp = first;
			
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

//////////////////////////////////////////////////////////////
//
//End of Stack
//
///////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////
//
// Description  : Queue using generic function.
// Author 		: Akshata Kalaskar
// Date 		: 18/11/2021
//
//////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////
//
// Description : Structure decleration of Queue;
//
/////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////
//
// Description : Decleration of class for Queue.
//
///////////////////////////////////////////////////////////////////////////////

template <typename T>
class Queue	
{
	private:
		node1 <T>* first;
		int size;
	
	public:
		Queue();
		void Enqueue(T);
		int Dequeue();
		void Display();
		int Count();
		
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
	node1 <T>* newn = new node1 <T>;
			
	newn -> data = no;
	newn -> next = NULL;
			
	if(first == NULL)
	{
		first = newn;
	}
	else
	{
		node1 <T>* temp = first;
		
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
		node1 <T>* temp = first;
				
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
	node1 <T>* temp = first;
			
	while(temp != NULL)
	{
		cout<<"|"<<temp -> data<<"| -> ";
		temp = temp -> next;
	}
			
	cout<<"\n";
}

template <typename T>		
int Queue <T> :: Count()
{
	return size;
}

/////////////////////////////////////////////////////////////////////////////////////
//
//End of Queue
//
///////////////////////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////////////////////
//
// Description : Binary search tree.
// Author      : Akshata Kalaskar
// Date        : 21/11/2021
//
///////////////////////////////////////////////////////////////////////////////////////


//////////////////////////////////////////////////////////////////////////////////////
//
// Description : Structure of BST.
//
//////////////////////////////////////////////////////////////////////////////////////
template <typename T>
struct node3
{
	T data;
	struct node3 *lchild;
	struct node3 *rchild;
	
};

////////////////////////////////////////////////////////////////////////////////////////
//
// Description : Class Decleration for BST
//
////////////////////////////////////////////////////////////////////////////////////////
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

//////////////////////////////////////////////////////////////////////
//
// End of BST!!
//
/////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////
//
//Description : Starting of main function;
//
//////////////////////////////////////////////////////////////////////

int main()
{
	
	SinglyLL <int>iobj;
	SinglyCL <int>scobj;
	DoublyLL <int>dlobj;
	DoublyCL <int>dcobj;
	Stack <int>sobj;
	Queue <int>qobj;
	
	int iValue = 0,iChoice = 1,position = 0,iRet = 0;
	
	while(iChoice != 0)
	{
		cout<<"\nEntered desired choice you want to perform on linked list : \t";
		cout<<"\n_______________________________________________________________________________\n";
		cout<<"1. Insert node1 at first position.\n";
		cout<<"2. Insert node1 at last position.\n";
		cout<<"3. Insert node1 at desired position.\n";
		cout<<"4. Delete First node1.\n";
		cout<<"5. Delete Last node1.\n";
		cout<<"6. Delete node1 from desired position.\n";
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