#include<iostream>
using namespace std;

class ArrayX
{
	public:
	int SumI(int Arr[],int iSize)
	{
	int iSum = 0, i = 0;
	
	while(i < iSize)
	{
		iSum = iSum + Arr[i];
		i++;
	}
	
	return iSum;
	}

};

int main()
{
	int iLen = 0,i = 0,iRet = 0;
	int *p = NULL;
	
	ArrayX obj;
	
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
	
	iRet = obj.SumI(p,iLen);
	cout<<"\nAddition is : "<<iRet<<"\n";
	
	delete []p;
	
	return 0;
}