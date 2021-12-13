//Stack
//stack using linked list
//dynamic stack

#include<iostream>
using namespace std;

typedef struct node
{
	int data;
	struct node *next;
	
}NODE,*PNODE;

class Stack		//singly linear linked list
{
	private:
		PNODE first;
		int size;
	
	public:
		Stack()
		{
			first = NULL;
			size = 0;
		}
		
		void push(int no)	//InsertFirst()
		{
			PNODE newn = new NODE;
			
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
		
		int pop()	//Deletefirst()
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
				PNODE temp = first;
				
				outelement = first -> data;
				first = first -> next;
				delete temp;
			}
			size--;
			return outelement;
		}
		
		void Display()
		{
			PNODE temp = first;
			
			while(temp != NULL)
			{
				cout<<"|"<<temp -> data<<"|\n";
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
	Stack obj;
	int iret = 0;
	
	obj.push(11);
	obj.push(21);
	obj.push(51);
	obj.push(101);
	
	cout<<"Elements of stack is :\n";
	obj.Display();
	
	iret = obj.pop();		//101
	cout<<"Poped element is : "<<iret<<"\n";
	
	cout<<"Elements of stack is :\n";
	obj.Display();
	
	iret = obj.Count();
	cout<<"\nsize of stack is : \t"<<iret<<"\n";
	
	return 0;
}