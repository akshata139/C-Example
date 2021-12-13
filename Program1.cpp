#include<iostream>
#include<stdlib.h>
#include<fcntl.h>
#include<stdio.h>
#include<unistd.h>
#include<string.h>

using namespace std;

class Marvellous
{
	private:
		char Fname[30];
		char Data[10];
		int fd;
		
	public:
		Marvellous(char *Name)
		{
			cout<<"Inside Constructor!!\n";
			strcpy(Fname,Name);
			fd = open(Fname,O_RDWR);
		}
		
		~Marvellous()
		{
			cout<<"Inside Destructor!!\n";
			close(fd);
		}
		
		void Display()
		{
			cout<<"File open Successfully!!\n";
			
			int iRet = 0;
			
			iRet = read(fd,Data,7);
			cout<<"7 bytes gets Successfully read from the file!";
			cout<<"Data from the file is : ";
			write(1,Data,iRet);
		}
};

int main()
{
	char Name[30];
	
	cout<<"Enter file name \n";
	cin>>Name;
	
	Marvellous obj(Name);
	
	obj.Display();
	
	return 0;
}