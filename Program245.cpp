//Recursion.
//operation system karte core dumpt.

#include<iostream>
using namespace std;

int FactorialI(int iNo)
{
	int iFact = 1;		//auto storage class tychi value prt jate ani prt function call kelyavr prt allocate hote
	
	while(iNo != 0)
	{
		iFact = iFact * iNo;
		iNo--;
	}
	
	return iFact;
	
}

int FactorialR(int iNo)
{
	static int iFact = 1;		//auto storage class tychi value prt jate ani prt function call kelyavr prt allocate hote
	
	if(iNo != 0)
	{
		iFact = iFact * iNo;
		iNo--;
		
		FactorialR(iNo);
	}
	
	return iFact;
	
}

int main()
{
	int x = 0,iRet = 0;
	
	cout<<"Enter number\n";
	cin>>x;
	
	iRet = FactorialR(x);
	
	cout<<"Factoral is : "<<iRet<<"\n";
	
	return 0;
}