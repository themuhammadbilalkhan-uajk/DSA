#include<iostream>
using namespace std;

int LinearSearch(int arr[],int size,int key)
{
	for(int i=0;i< size;i++)
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
const int Size = 30;

int RollNo[Size];
int PF[Size],OOP[Size],DSA[Size];

cout<<"Enter RollNo and Marks of 30 Students"<<endl;

for(int i=0;i < Size;i++)
{
cout<<" "<<endl;	
cout<<" "<<endl;	
	cout<<"Student No: "<<i+1<<endl;
cout<<"Enter Roll No: ";
cin>>RollNo[i];
cout<<"Enter PF Marks: ";
cin>>PF[i];
cout<<"Enter OOP Marks: ";
cin>>OOP[i];
cout<<"Enter DSA Marks: ";
cin>>DSA[i];
	
cout<<" "<<endl;	
	
} 

int SRollno;
cout<<"Enter RollNo For Search Record: ";
cin>>SRollno;

int Found = LinearSearch(RollNo,Size,SRollno);

if(Found > -1)
{
	cout<<""<<endl;
	cout<<"Record Found.."<<endl;
	cout<<""<<endl;
	cout<<"PF Marks: "<<PF[Found]<<endl;
	cout<<"OOP Marks: "<<OOP[Found]<<endl;
	cout<<"DSA Marks: "<<DSA[Found]<<endl;
	cout<<" "<<endl;
	int total = PF[Found]+OOP[Found]+DSA[Found];
	float percentage = total / 3.0;
	cout<<"Total Marks: "<<total<<endl;
	cout<<"Percentage: "<<percentage<<endl;
}
else
{
	cout<<"RollNo are Record Not Found!"<<endl;
}

return 0;
}
