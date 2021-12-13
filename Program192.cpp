/*

Bitwise operation : op1		op2		&		|		^
					1		0		0		1		1
					0		1		0		1		1
					1		1		1		0		0
					0		0		0		0		0
					
accept number and two position from user and toggle bit at that position.


*/

#include<iostream>
using namespace std;

typedef unsigned int UINT;

UINT ToggleBit(UINT iNo,int iPos1,int iPos2)
{
	int iMask1 = 0x00000001,iMask2 = 0x00000001,iMask;
	int iResult = 0;
	
	if((iPos1 < 1) || (iPos1 > 32) || (iPos2 < 1) || (iPos2 > 32))
	{
		return 0;
	}
	
	iMask1= iMask1 << (iPos1 - 1);
	iMask2 = iMask2 << (iPos2 - 1);
	
	iMask = iMask1 | iMask2;
	
	iResult = iNo ^ iMask;
	
	return iResult;
}

int main()
{
	int iValue = 0,i = 0,j = 0,iRet = 0;
	
	cout<<"Enter number : \n";
	cin>>iValue;
	
	cout<<"Enter first Position :: \n";
	cin>>i;
	
	cout<<"Enter second Position :: \n";
	cin>>j;
	
	iRet = ToggleBit(iValue,i,j);
	cout<<"Updated number is : "<<iRet<<"\n";
	
	return 0;
}