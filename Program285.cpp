#include<iostream>

using namespace std;

template <typename T>
class ArrayX
{
	public:
	
		T *Arr;
		int size;
		
	public:
		explicit ArrayX();
		~ArrayX();
		void Accept();
		void Display();
		//bool LinearSearch(T);
};

template <typename T>
ArrayX<T> :: explicit ArrayX()
{
	Arr = new T;
	size = 0;
}

template <typename T>
ArrayX <T>:: ~ArrayX()
{
	delete(Arr);
}

template <typename T>
void ArrayX<T> :: Accept()
{	
	cout<<"Enter elements : \n";
	
	for(int i = 0;i < size;i++)
	{
		cin>>Arr[i];
		
		Arr++;
	}
}

template <typename T>
void ArrayX<T> :: Display()
{
	cout<<"Entered elements are : ";
	
	for(int i = 0;i < size;i++)
	{
		cout<<"|"<<Arr[i]<<"|"<<"\t";
		
		Arr++;
	}
	
	cout<<"\n";
}

template <typename T>
class Searching : public ArrayX<T>
{
	public:
	
		Searching() //: ArrayX()
		{
			Arr = new T;
			size = 0;
		}
		
		bool LinearSearch(T);
};

template <typename T>
bool Searching<T> :: LinearSearch(T iNo)
{
	int i = 0;
			
	for(i = 0; i < size; i ++)
	{
		if(Arr[i] == iNo)
		{
			break;
		}
		Arr++;
	}
			
	if(Arr[i] == size)
	{
		return false;
	}
	else
	{
		return true;
	}
}

int main()
{
	
	ArrayX <char>obj;
	
	obj.Accept();
	obj.Display();
	
	bool bret = false;
	int iValue = 0;
	
	cout<<"Enter element to be search : \n";
	cin>>iValue;
	
	bret = obj.LinearSearch(iValue);
	
	if(bret == true)
	{
		cout<<"Number is there!";
	}
	else
	{
		cout<<"Number is not there!";
	}
	
	return 0;
}