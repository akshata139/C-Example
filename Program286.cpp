#include<iostream>
using namespace std;

class Searching
{
	public:
		
		explicit Searching(int *brr,int ilen)
		{
			brr = NULL;
			ilen = 0;
		}
		
		bool Search(int iNo)
		{
			bool bret = false;
			
			for(int i = 0;i < ilen;i++)
			{
				if(brr[i] == iNo)
				{
					bret = true;
				}
			}
			
			return bret;
		}
};

int main()
{
	int *Arr = NULL;
	int isize = 0, i = 0;
	
	Arr = new int;
	
	cout<<"Enter size of the array : \n";
	cin>>isize;
	
	cout<<"Enter elements : \n";
	
	for(i = 0;i < isize;i++)
	{
		cin>>Arr[i];
	}
	
	cout<<"Entered elements are : \n";
	
	for(i = 0; i < isize; i++)
	{
		cout<<"|"<<Arr[i]<<"|\t";
	}
	
	cout<<"\n";
	
	Searching obj(Arr,isize);
	
	int iValue = 0;
	bool bret = false;
	
	cout<<"Enter number to be search : \n";
	cin>>iValue;
	
	bret = obj.Search(iValue);
	
	if(bret == true)
	{
		cout<<"Number is there!\n";
	}
	else
	{
		cout<<"Number is not there!";
	}
	
	return 0;
}