#include<iostream>
#include<string>

using namespace std;

struct Node
{
    int PatientID;
    string PatientName;

    Node* next;
    Node* prev;          
};

Node* head = NULL;


void InsertAtBeg(int id, string Name)
{
    Node* newNode = new Node();
    newNode->PatientID = id;
    newNode->PatientName = Name;

    newNode->next = head;
    newNode->prev = NULL;

    if (head != NULL)
        head->prev = newNode;

    head = newNode;

    cout << "Inserted at Start (Emergency)\n";
}


void InsertAtEnd(int id, string Name)
{
    Node* newNode = new Node();
    newNode->PatientID = id;
    newNode->PatientName = Name;
    newNode->next = NULL;
    newNode->prev = NULL;

    if (head == NULL)
    {
        head = newNode;
        cout << "Inserted at End\n";
        return;
    }

    Node* temp = head;
    while (temp->next != NULL)
        temp = temp->next;

    temp->next = newNode;
    newNode->prev = temp;

    cout << "Inserted at End\n";
}


void Display()
{
    if(head == NULL)
    {
        cout << "No patients to display\n";
        return;
    }

    Node* temp = head;

    while (temp != NULL)
    {
        cout << "ID: " << temp->PatientID
             << "  Name: " << temp->PatientName << endl;

        temp = temp->next;
    }
}


void Search(int id)
{
    Node* temp = head;

    while (temp != NULL)
    {
        if (temp->PatientID == id)
        {
            cout << "Patient Found - ID: " << id << endl;
            return;
        }
        temp = temp->next;
    }

    cout << "Patient NOT Found\n";
}


void Removed(int id)
{
    if (head == NULL)
    {
        cout << "No patients to remove\n";
        return;
    }

    Node* temp = head;

  
    while (temp != NULL && temp->PatientID != id)
        temp = temp->next;

    if (temp == NULL)
    {
        cout << "Patient NOT found\n";
        return;
    }

  
    if (temp == head)
        head = temp->next;


    if (temp->next != NULL)
        temp->next->prev = temp->prev;


    if (temp->prev != NULL)
        temp->prev->next = temp->next;

    delete temp;
    cout << "Patient Removed\n";
}

int main()
{
    int choice, id;
    string name;

    while (true)
    {
        system("cls");
        cout << "\n--- Hospital Patient Management System (DLL) ---\n";
        cout << "1. Add Patient (End)\n";
        cout << "2. Add Emergency Patient (Beginning)\n";
        cout << "3. Display All Patients\n";
        cout << "4. Search Patient by ID\n";
        cout << "5. Remove Patient by ID\n";
        cout << "6. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Enter Patient ID: ";
            cin >> id;
            cout << "Enter Patient Name: ";
            cin >> name;
            InsertAtEnd(id, name);
            break;

        case 2:
            cout << "Enter Patient ID: ";
            cin >> id;
            cout << "Enter Patient Name: ";
            cin >> name;
            InsertAtBeg(id, name);
            break;

        case 3:
            cout << "\nPatient Info:\n";
            Display();
            break;

        case 4:
            cout << "Enter Patient ID to Search: ";
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
            cout << "Invalid choice!\n";
        }

        system("pause");
    }

    return 0;
}
