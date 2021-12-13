/*

Bitwise operation : op1		op2		&		|		^
					1		0		0		1		1
					0		1		0		1		1
					1		1		1		0		0
					0		0		0		0		0
					
accept number from user and toggle bit at that position.
iNo   0000 0000 1110 0100 1111 0100 1011 1010
iPos  6
iRet  0000 0000 1110 0100 1111 0100 1001 1010

*/

#include<iostream>
using namespace std;

typedef unsigned int UINT;

UINT ToggleBit(UINT iNo,int iPos)
{
	int iMask = 0x00000001;
	int iResult = 0;
	
	if((iPos < 1) || (iPos > 32))
	{
		return 0;
	}
	
	iMask = iMask<<(iPos - 1);
	
	iResult = iNo ^ iMask;
	
	return iResult;
}

// input		0  1 1 0 0 1 0 0
// iMask		0  0 0 1 0 0 0 0 
//iMask = iMask<<(Position - 1)
//iMask = iMask<<(5 - 1)
//iMask = iMask<<4
//iMask			0  0 0 1 0 0 0 0

//input			0  1 1 0 0 1 0 0
// iMask		0  0 0 1 0 0 0 0 
//--------------------------------------------
//output		0  1 1 1 0 1 0 0 

int main()
{
	int iValue = 0,i = 0,iRet = 0;
	
	cout<<"Enter number : \n";
	cin>>iValue;
	
	cout<<"Enter Position :: \n";
	cin>>i;
	
	iRet = ToggleBit(iValue,i);
	cout<<"Updated number is : "<<iRet<<"\n";
	
	return 0;
}