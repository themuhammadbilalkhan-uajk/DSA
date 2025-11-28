#include<iostream>
using namespace std;

int LinearSearch(int arr[],int size,int key)
{
	for(int i=0;i<=size;i++)
	{
		if(arr[i] == key)
		{
			return i;
		}
		
	}
	return -1;
}

int main()
{

int Numbers[20] = {0,1,2,3,4,5,6,7,8,9,12,47,51,20,58,96,45,21,36,50};

int Search;

cout<<"Enter Number For Searching: ";
cin>>Search;

int Result = LinearSearch(Numbers,20,Search);

if(Result > -1)
{
	cout<<"Value Found"<<endl;
}
else
{
	cout<<"Value Not Found!"<<endl;
}

return 0;
}
