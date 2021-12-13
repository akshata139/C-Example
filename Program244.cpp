//Recursion.
//operation system karte core dumpt.

#include<iostream>
using namespace std;

int SumI(int iNo)
{
	int iSum = 0;		//auto storage class tychi value prt jate ani prt function call kelyavr prt allocate hote
	
	while(iNo != 0)
	{
		iSum = iSum + (iNo % 10);
		iNo = iNo / 10;
	}
	
	return iSum;
	
}

int SumR(int iNo)
{
	static int iSum = 0;
	
	if(iNo != 0)
	{
		iSum = iSum + (iNo % 10);
		iNo = iNo / 10;
		
		SumR(iNo);
	}
	return iSum;
	
}

int main()
{
	int x = 0,iRet = 0;
	
	cout<<"Enter number\n";
	cin>>x;
	
	iRet = SumR(x);
	
	cout<<"Summation of digits : "<<iRet<<"\n";
	
	return 0;
}