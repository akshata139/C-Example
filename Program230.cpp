#include<iostream>
using namespace std;

void Swap(int *p,int *q)
{
	int temp;
	
	temp = *p;
	*p = *q;
	*q = temp;
	
}

int main()
{
	int x = 0,y = 0;

	cout<<"Enter first number \n";
	cin>>x;
	
	cout<<"Enter second number \n";
	cin>>y;
	
	Swap(&x,&y);
	
	cout<<"Value of X becomes : "<<x<<"\n";
	cout<<"Value of Y becoms : "<<y<<"\n";
	
	return 0;
}