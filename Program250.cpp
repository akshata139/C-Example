#include<iostream>
#include<stdio.h>
using namespace std;

int StrlenI(char *Str)
{
	int iCnt = 0;
	
	while(*Str != '\0')
	{
		iCnt++;
		Str++;
	}
	
	return iCnt;
}

int StrlenR(char *Str)
{
	static int iCnt = 0;
	
	if(*Str != '\0')
	{
		iCnt++;
		Str++;
		
		StrlenR(Str);
	}
	
	return iCnt;
}

int main()
{
	char Arr[20];
	int iRet = 0;
	
	cout<<"Enter string : \n";
	scanf("%[^'\n']s",Arr);
	
	iRet = StrlenR(Arr);
	
	cout<<"Length of string is : "<<iRet<<"\n";
	
	return 0;
}