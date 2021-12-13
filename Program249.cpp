#include<iostream>
using namespace std;

class ArrayX
{
	private:
		int *p;
		int iSize;
		
	public:
		ArrayX()
		{
			iSize = 0;
			p = new int[iSize];
		}
		
		void Accept()
		{
			int i = 0;
			
			cout<<"Enter number of elements : \t";
			cin>>iSize;
			cout<<"\n";
			
			cout<<"Enter elements : \n";
			for(i = 0;i < iSize;i++)
			{
				cin>>p[i];
			}
		}
		
		void Display()
		{
			int i = 0;
			cout<<"Elements are : \n";
			for(i = 0;i < iSize;i++)
			{
				cout<<p[i];
			}
			cout<<"\n";
		}
		
		int SumR()
		{
			static int iSum = 0, i = 0;
	
			if(i < iSize)
			{
				iSum = iSum + p[i];
				i++;
		
				SumR();
			}
	
			return iSum;
		}

};

int main()
{
	int iRet = 0;
	
	ArrayX obj;
	
	obj.Accept();
	obj.Display();
	
	iRet = obj.SumR();
	cout<<"\nAddition is : "<<iRet<<"\n";
	
	return 0;
}