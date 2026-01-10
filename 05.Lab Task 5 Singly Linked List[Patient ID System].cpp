#include<iostream>
using namespace std;

struct Node
{
int PatientID;

Node* next;
};

Node* head = NULL;

void InsertStart(int id)
{
	Node* newNode = new Node();
	newNode->PatientID = id;
	newNode->next = head;
	
	head = newNode;
	cout<<"Emergency Patient Added"<<endl;
}

void InsertEnd(int id)
{
	Node* newNode = new Node();
	newNode->PatientID = id;
	newNode->next = NULL;
	
	
	if(head == NULL)
	{
		head = newNode;
		cout<<"Patient added at the end"<<endl;
		return;
	}
	
	Node* temp = head;
	
	while(temp->next != NULL)
	{
		temp = temp->next;
	}
	
	temp->next = newNode;
	cout<<"Patient added at the end"<<endl;
}

void Display()
{
	if(head == NULL)
	{
		cout<<"No Patient In the List"<<endl;
		return;
	}
	
	Node* temp = head;
	
	while(temp != NULL)
	{
		cout<<"***********"<<endl;
		cout<<"ID: "<<temp->PatientID<<endl;
		cout<<" "<<endl;
		temp = temp->next;
	}
}

void Search(int id)
{
	Node* temp = head;
	
	while(temp != NULL)
	{
		if(temp->PatientID == id)
		{
			cout<<"Patient Found:"<<endl;
			cout<<"ID: "<<temp->PatientID<<endl;
			return;
		}
		temp = temp->next;
	}
	
	cout<<"Patient Not Found"<<endl;
}

void RemovePatient(int id)
{
	if(head == NULL)
	{
		cout<<"No patient for remove"<<endl;
		return;
	}
	
	
	if(head->PatientID == id)
	{
		Node* temp = head;
		head = head->next;
		delete temp;
		
		cout<<"Patient Removed"<<endl;
		return;
	}
	
	Node* curr = head;
	
	while(curr->next != NULL && curr->next->PatientID != id)
	{
		curr = curr->next;
	}
	
	if(curr->next == NULL)
	{
		cout<<"No Patient for remove"<<endl;
		return;
	}
	
	Node* temp = curr->next;
	curr->next = curr->next->next;
	delete temp;
	cout<<"Patient Removed"<<endl;
}
int main()
{

int choice;

while(true)
{
 cout<<"1. Press [1] to add new patient at the end"<<endl;
 cout<<"2. Press [2] to add emergency patient at the beginning"<<endl;
 cout<<"3. Press [3] for Search a patient by ID"<<endl;
 cout<<"4. Press [4] for Dispaly all patients"<<endl;
 cout<<"5. Press [5] to Remove treated patient"<<endl;
 cout<<"6. Press [6] For Exit"<<endl;
 cout<<">";
 cin>>choice;

 if(choice == 1)
 {
 	int ID;
 	cout<<"Enter Patient ID:";
 	cin>>ID;
 	InsertEnd(ID);
 }
 else if(choice == 2)
 {
 	int ID;
 	cout<<"Enter Patient ID:";
 	cin>>ID;
 	
 	InsertStart(ID);
 }
 else if(choice == 3)
 {
 	int ID;
 	cout<<"Enter Patient ID:";
 	cin>>ID;
 	Search(ID);
 }
 else if(choice == 4)
 {
 	Display();
 }
 else if(choice == 5)
 {
 	int ID;
 	cout<<"Enter Patient ID:";
 	cin>>ID;
 	RemovePatient(ID);
 }
 else if(choice == 6)
 {
 	return 0;
 }
 else
 {
 	cout<<"Invalid Choice"<<endl;
 }
 
 
 }
 
return 0;
}



