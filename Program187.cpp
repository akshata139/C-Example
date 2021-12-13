//calculate the size of file.

#include<iostream>
#include<unistd.h>
#include<string.h>
#include<stdlib.h>
#include<stdio.h>
#include<fcntl.h>

using namespace std;

class MarvellousFs
{
	public:
	
	char Fname[40];
	int fd = 0,iAns = 0;
	
	MarvellousFs(char *cName)
	{
		cout<<"Inside constructor!! \n";
		strcpy(Fname,cName);
		fd = open(cName,O_RDWR);
	}
	
	~MarvellousFs()
	{
		cout<<endl<<"Inside Destructor!!";
		close(fd);
	}
	
	int CountSize()
	{
		iAns = lseek(fd,0,2);
		return iAns;
	}
};

int main()
{
	char Fname[40];
	int iRet = 0;
	
	cout<<"Enter file name : \n";
	cin>>Fname;
	
	MarvellousFs mobj(Fname);
	iRet = mobj.CountSize();
	cout<<endl<<"Size of file is : "<<iRet;
	
	return 0;
}