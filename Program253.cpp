#include<iostream>
#include<stdio.h>
using namespace std;

template <typename T>
struct node
{
	T data;
	struct node *next;
	
};

template <typename T>
void InsertFirst(node <T>* Head,T no)
{
	node <T>* newn = new node <T>;
	
	newn -> data = no;
	newn -> next = NULL;
	
	if(*Head == NULL)
	{
		*Head = newn;
	}
	else 
	{
		newn -> next = *Head;
		*Head = newn;
	}
}

template <typename T>
void Display(node <T> Head)
{
	while(Head != NULL)
	{
		cout<<"|"<<Head -> data<<"| -> ";
		Head = Head -> next;
	}
	
	cout<<"\n";
}

template <typename T>
int Count(node <T> Head)
{
	int iCnt = 0;
	while(Head != NULL)
	{
		iCnt++;
		//cout<<"|"<<Head -> data<<"| -> ";
		Head = Head -> next;
	}
	
	return iCnt;
}

template <typename T>
void DisplayR(node <T> Head)
{
	if(Head != NULL)
	{
		cout<<"|"<<Head -> data<<"| -> ";
		Head = Head -> next;
		
		DisplayR(Head);
	}
}

template <typename T>
int CountR(node <T> Head)
{
	static int iCnt = 0;
	if(Head != NULL)
	{
		iCnt++;
		//cout<<"|"<<Head -> data<<"| -> ";
		Head = Head -> next;
		
		CountR(Head);
	}
	
	return iCnt;
}

int main()
{
	node <T> first = NULL;
	int iRet = 0;
	
	InsertFirst(&first,101);
	InsertFirst(&first,51);
	InsertFirst(&first,21);
	InsertFirst(&first,11);
	
	DisplayR(first);
	
	iRet = CountR(first);
	
	cout<<"Number of elements are : "<<iRet<<"\n";
	
	return 0;
}