/*

swap 1st and last byte.

*/

#include<iostream>
using namespace std;

typedef unsigned int UINT;

UINT SwapByte(UINT iNo)
{
	return (iNo & 0x00FFFF00) |(iNo << 24) | (iNo >> 24);
}

int main()
{
	UINT iValue = 0,iRet = 0;
	
	cout<<"Enter number : \n";
	cin>>iValue;
	
	iRet = SwapByte(iValue);
	cout<<"Data is :"<<iRet<<"\n";
	
	return 0;
}

/*
ABCD

//step 1
000D
//step 2
00B0
000B
//step 3
0C00
000C
//step 4
A000
000A

*/