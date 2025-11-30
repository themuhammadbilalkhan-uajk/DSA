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


void InsertAtBeg(int id, string Name)
{
    Node* newNode = new Node();
    newNode->PatientID = id;
    newNode->PatientName = Name;

    newNode->next = head;
    head = newNode;

    cout << "Inserted at Start (Emergency)\n";
}


void InsertAtEnd(int id, string Name)
{
    Node* newNode = new Node();
    newNode->PatientID = id;
    newNode->PatientName = Name;
    newNode->next = NULL;

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

 
    if (head->PatientID == id)
    {
        Node* temp = head;
        head = head->next;
        delete temp;
        cout << "Patient Removed\n";
        return;
    }

    Node* curr = head;

   
    while (curr->next != NULL && curr->next->PatientID != id)
    {
        curr = curr->next;
    }

    if (curr->next == NULL)
    {
        cout << "Patient NOT found\n";
        return;
    }

    Node* temp = curr->next;
    curr->next = curr->next->next;

    delete temp;
    cout << "Patient Removed\n";
}

int main()
{