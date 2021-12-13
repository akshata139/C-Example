#include<iostream>
using namespace std;

//specific function
void Swap(char *p,char *q)
{
	char temp;
	
	temp = *p;
	*p = *q;
	*q = temp;
	
}

//generic function
template <class T>
void SwapX(T *p,T *q)
{
	T temp;
	
	temp = *p;
	*p = *q;
	*q = temp;
	
}

int main()
{
	char x = 'A',y = 'K';
	
	SwapX(&x,&y);
	
	cout<<"Value of X becomes : "<<x<<"\n";
	cout<<"Value of Y becoms : "<<y<<"\n";
	
	int i = 11,j = 21;
	SwapX(&i,&j);
	cout<<"Value of X becomes : "<<i<<"\n";
	cout<<"Value of Y becoms : "<<j<<"\n";
	
	return 0;
}