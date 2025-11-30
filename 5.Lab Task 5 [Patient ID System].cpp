#include<iostream>
#include<string>

using namespace std;

struct Node
{
  int PatientID;
  string PatientName;
  
  Node* next;
};

Node* head = NULL;

void InsertAtBeg(int id,string Name)
{
	Node* newNode = new Node();
	newNode->PatientID = id;
	newNode->PatientName = Name;
	
	newNode->next = head;
	head = newNode;
	
	cout<<"Insert At Start"<<endl;
}

void InsertAtEnd(int id,string Name)
{
	Node* newNode = new Node();
	newNode->PatientID = id;
	newNode->PatientName = Name;
	
	newNode->next = NULL;
	
	
	if(head == NULL)
	{
		head = newNode;
		cout<<"Insert At End"<<endl;
		
		return;
	}
	
	Node* temp = head;
	
    while(temp->next != NULL)
    {
    	temp = temp->next;
	}
    
   
    temp->next = newNode;
    cout<<"Insert at end"<<endl;
}

void Display()
{
	if(head == NULL)
	{
		cout<<"Nothing For Display"<<endl;
		return;
	}
	
	Node* temp = head;
	
	while(temp->next != NULL)
	{
		cout<<"ID: "<<temp->PatientID<<" Name: "<<temp->PatientName<<endl;
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
    		cout<<"Patient Found ID: "<<id<<endl;
    		return;
		}
		temp = temp->next;
	}
	
	cout<<"Patient Not Found"<<endl;
}

void Removed(int id)
{
	if(head == NULL)
	{
		cout<<"No Patient for Removed"<<endl;
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
	
	while(curr->next != NULL && curr->PatientID != id)
	{
		curr = curr->next;
	}
	
	if(curr->next == NULL)
	{
		cout<<"No Patient For Removed"<<endl;
		return;
	}
	
		Node* temp = curr->next;
		curr->next = curr->next->next;
		
		delete temp;
		cout<<"Patient Removed"<<endl;

	
}

int main()
{

 int choice, id;
 string name;

   
    while (true) {
    	system("cls");
        cout << "\n--- Hospital Patient Management System ---\n";
        cout << "1. Add Patient (End)\n";
        cout << "2. Add Emergency Patient (Beginning)\n";
        cout << "3. Display All Patients\n";
        cout << "4. Search Patient by ID\n";
        cout << "5. Removed Patient by ID\n";
        cout << "6. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter Patient ID: ";
                cin >>id;
                cout << "Enter Patient Name: ";
                cin >>name;
                InsertAtEnd(id,name);
                break;

            case 2:
                 cout << "Enter Patient ID: ";
                cin >>id;
                cout << "Enter Patient Name: ";
                cin >>name;
                InsertAtBeg(id,name);
                break;

            case 3:
            	cout<<"Patient Info:"<<endl;
            	cout<<""<<endl;
                Display();
            	cout<<""<<endl;
                break;

            case 4:
                cout << "Enter Patient ID to search: ";
                cin >> id;
                Search(id);
                break;
                
            case 5:
                cout << "Enter Patient ID to Remove: ";
                cin >> id;
                Removed(id);
                break;
                
            case 6:
                cout << "Exiting program...\n";
                return 0;

            default:
                cout << "Invalid choice. Try again.\n";    
        }
           system("pause");
    }


return 0;
}
