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
	char x = '\0',y = '\0';

	cout<<"Enter first element \n";
	cin>>x;
	
	cout<<"Enter second element \n";
	cin>>y;
	
	SwapX(&x,&y);
	
	cout<<"Value of X becomes : "<<x<<"\n";
	cout<<"Value of Y becoms : "<<y<<"\n";
	
	return 0;
}