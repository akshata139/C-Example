#include<iostream>
using namespace std;

int SumI(int Arr[],int iSize)
{
	int iSum = 0, i = 0;
	
	for(i = 0;i < iSize;i++)
	{
		iSum = iSum + Arr[i];
	}
	
	return iSum;
}

int main()
{
	int iLen = 0,i = 0,iRet = 0;
	int *p = NULL;
	
	cout<<"Enter number of elements : \t";
	cin>>iLen;
	cout<<"\n";
	
	p = new int[iLen];
	
	cout<<"Enter elements : \n";
	for(i = 0;i < iLen;i++)
	{
		cin>>p[i];
	}
	
	cout<<"Enter elements are : \n";
	for(i = 0;i < iLen;i++)
	{
		cout<<p[i]<<"\t";
	}
	
	iRet = SumI(p,iLen);
	cout<<"\nAddition is : "<<iRet<<"\n";
	
	delete []p;
	
	return 0;
}