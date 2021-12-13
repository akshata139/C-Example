#include<iostream>
#include<stdio.h>
using namespace std;

void StrRevX(char *Str)
{
	char *End = Str;
	char temp;
	
	while(*End != '\0')
	{
		End++;
	}
	End--;
	
	while(Str < End)
	{
		temp = *Str;
		*Str = *End;
		*End = temp;
		
		Str++;
		End--;
	}
}

void StrRevXR(char *Str)
{
	static char *End = Str;
    static char temp;
	
	while(*End != '\0')
	{
		End++;
		//StrRevXR();
	}
	End--;
	
	if(Str < End)
	{
		temp = *Str;
		*Str = *End;
		*End = temp;
		
		*Str++;
		*End--;
		
		StrRevXR(Str);
	}
}

int main()
{
	char Arr[20];
	
	cout<<"Enter string : \n";
	scanf("%[^'\n']s",Arr);
	
	StrRevXR(Arr);
	
	cout<<"Reverse string is : "<<Arr<<"\n";
	
	return 0;
}