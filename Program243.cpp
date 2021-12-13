//Recursion.
//operation system karte core dumpt.

#include<iostream>
using namespace std;

void DisplayI(int iNo)
{
	int iCnt = 1;		//auto storage class tychi value prt jate ani prt function call kelyavr prt allocate hote
	
	while(iCnt <= iNo)
	{
		cout<<"Akshata!!\n";
		iCnt++;
	}
	
}

void DisplayR(int iNo)
{
	static int iCnt = 1;		//permenant value rahate
	
	if(iCnt <= iNo)
	{
		cout<<"Marvellous!!\n";
		iCnt++;
		
		DisplayR(iNo);
	}
	
}

int main()
{
	int i = 5;
	
	DisplayI(i);
	DisplayR(i);
	
	return 0;
}