#include<iostream>
#include<stdio.h>
using namespace std;

int CountCapitalL(char *Str)
{
	int iCnt = 0;
	
	while(*Str != '\0')
	{
		if((*Str >= 'A') && (*Str <= 'Z'))
		{
			iCnt++;
		}
	
		Str++;
		
		CountCapitalL(Str);
	}
	
	return iCnt;
}

int CountCapital(char *Str)
{
	static int iCnt = 0;
	
	if(*Str != '\0')
	{
		if((*Str >= 'A') && (*Str <= 'Z'))
		{
			iCnt++;
		}
	
		Str++;
		
		CountCapital(Str);
	}
	
	return iCnt;
}

int main()
{
	char Arr[20];
	int iRet = 0;
	
	cout<<"Enter string : \n";
	scanf("%[^'\n']s",Arr);
	
	iRet = CountCapital(Arr);
	
	cout<<"Capital letters are : "<<iRet<<"\n";
	
	return 0;
}