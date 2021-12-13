/*

Bitwise operation : op1		op2		&		|		^
					1		0		0		1		1
					0		1		0		1		1
					1		1		1		0		0
					0		0		0		0		0
					
accept number from user and toggle last four and first four nibble of that number.


*/

#include<iostream>
using namespace std;

typedef unsigned int UINT;

UINT ToggleNibble(UINT iNo)
{
	UINT iMask = 0xF000000F;
	UINT iResult = 0;
	
	iResult = iNo ^ iMask;
	
	return iResult;
}

int main()
{
	UINT iValue = 0,iRet = 0;
	
	cout<<"Enter number : \n";
	cin>>iValue;
	
	iRet = ToggleNibble(iValue);
	printf("%u",iRet);
	//cout<<"Updated number is : "<<iRet<<"\n";
	
	return 0;
}