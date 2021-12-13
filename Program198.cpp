/*

Bitwise operation : op1		op2		&		|		^
					1		0		0		1		1
					0		1		0		1		1
					1		1		1		0		0
					0		0		0		0		0


*/

#include<iostream>
using namespace std;

typedef unsigned int UINT;

UINT ToggleOnRange(UINT iNo,int iStart,int iEnd)
{
	return (iNo ^ ((0xFFFFFFFF << (iStart - 1)) & (0xFFFFFFFF << (32 - iEnd))));
}

//iStart = 5
//iEnd = 16

//	0000 0000 0000 0000 0000 0000 0000 0000

//	0000 0000 0000 0000 1111 1111 1111 0000

//iMask1 = 0xFFFFFFFF;
// 1111 1111 1111 1111 1111 1111 1111 1111
//iMask2 = 0xFFFFFFFF;

//iMask1 = iMask1 << (iStart - 1);
// 1111 1111 1111 1111 1111 1111 1111 0000

//iMask2 = iMask2 >> (32 - iEnd);
// 0000 0000 0000 0000 1111 1111 1111 1111 

//iMask = iMask1 & iMask2;
// 1111 1111 1111 1111 1111 1111 1111 1111
// 0000 0000 0000 0000 1111 1111 1111 1111 
//-------------------------------------------------
// 0000 0000 0000 0000 1111 1111 1111 0000

// iResult = iNo ^ iMask;

int main()
{
	UINT iValue = 0,i = 0,j = 0,iRet = 0;
	
	cout<<"Enter number : \n";
	cin>>iValue;
	
	cout<<"Enter starting position \n";
	cin>>i;
	
	cout<<"Enter Ending position \n";
	cin>>j;
	
	iRet = ToggleOnRange(iValue,i,j);

	cout<<"Updated number is : "<<iRet<<"\n";
	
	return 0;
}