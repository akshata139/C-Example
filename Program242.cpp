//Recursion.
//operation system karte core dumpt.

#include<iostream>
using namespace std;

void DisplayI()
{
	int iCnt = 1;		//auto storage class tychi value prt jate ani prt function call kelyavr prt allocate hote
	
	while(iCnt <= 4)
	{
		cout<<"Akshata!!\n";
		iCnt++;
	}
	
}

void DisplayR()
{
	static int iCnt = 1;		//permenant value rahate
	
	if(iCnt <= 4)
	{
		cout<<"Marvellous!!\n";
		iCnt++;
		
		DisplayR();
	}
	
}

int main()
{
	DisplayI();
	DisplayR();
	
	return 0;
}