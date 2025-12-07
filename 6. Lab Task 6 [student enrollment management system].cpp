#include <iostream>
#include <string>
using namespace std;

struct Node {
    int id;
    string name;
    int semester;
    float gpa;

    Node* next;
    Node* prev;
};

Node* head = NULL;


Node* createNode(int id, string name, int sem, float gpa) {
    Node* n = new Node();
    n->id = id;
    n->name = name;
    n->semester = sem;
    n->gpa = gpa;
    n->next = NULL;
    n->prev = NULL;
    return n;
}


void insertAtBeginning(int id, string name, int sem, float gpa) {
    Node* n = createNode(id, name, sem, gpa);

    if (head == NULL) {
        head = n;
    } else {
        n->next = head;
        head->prev = n;
        head = n;
    }
    cout << "Inserted at beginning.\n";
}


void insertAtEnd(int id, string name, int sem, float gpa) {
    Node* n = createNode(id, name, sem, gpa);

    if (head == NULL) {
        head = n;
        cout << "Inserted at end.\n";
        return;
    }

    Node* temp = head;
    while (temp->next != NULL)
        temp = temp->next;

    temp->next = n;
    n->prev = temp;

    cout << "Inserted at end.\n";
}


void insertAtPosition(int pos, int id, string name, int sem, float gpa) {
    if (pos < 0) {
        cout << "Invalid position.\n";
        return;
    }

    if (pos == 0) {
        insertAtBeginning(id, name, sem, gpa);
        return;
    }

    Node* temp = head;
    int index = 0;

    while (temp != NULL && index < pos - 1) {
        temp = temp->next;
        index++;
    }

    if (temp == NULL) {
        cout << "Position out of range.\n";
        return;
    }

    Node* n = createNode(id, name, sem, gpa);
    n->next = temp->next;
    n->prev = temp;

    if (temp->next != NULL)
        temp->next->prev = n;

    temp->next = n;

    cout << "Inserted at position " << pos << ".\n";
}


void deleteAtBeginning() {
    if (head == NULL) {
        cout << "List is empty.\n";
        return;
    }

    Node* temp = head;
    head = head->next;

    if (head != NULL)
        head->prev = NULL;

    delete temp;
    cout << "Deleted from beginning.\n";
}


void deleteAtEnd() {
    if (head == NULL) {
        cout << "List is empty.\n";
        return;
    }

    if (head->next == NULL) {
        delete head;
        head = NULL;
        cout << "Deleted last node.\n";
        return;
    }

    Node* temp = head;
    while (temp->next != NULL)
        temp = temp->next;

    temp->prev->next = NULL;
    delete temp;

    cout << "Deleted from end.\n";
}


void deleteAtPosition(int pos) {
    if (head == NULL) {
        cout << "List is empty.\n";
        return;
    }

    if (pos == 0) {
        deleteAtBeginning();
        return;
    }

    Node* temp = head;
    int index = 0;

    while (temp != NULL && index < pos) {
        temp = temp->next;
        index++;
    }

    if (temp == NULL) {
        cout << "Position out of range.\n";
        return;
    }

    temp->prev->next = temp->next;

    if (temp->next != NULL)
        temp->next->prev = temp->prev;

    delete temp;

    cout << "Deleted from position " << pos << ".\n";
}


void displayForward() {
    if (head == NULL) {
        cout << "List is empty.\n";
        return;
    }

    Node* temp = head;
    cout << "\n--- Student Records (Forward) ---\n";
    while (temp != NULL) {
        cout << "ID: " << temp->id
             << " | Name: " << temp->name
             << " | Semester: " << temp->semester
             << " | GPA: " << temp->gpa << endl;
        temp = temp->next;
    }
}


void displayBackward() {
    if (head == NULL) {
        cout << "List is empty.\n";
        return;
    }

    Node* temp = head;
    while (temp->next != NULL)
        temp = temp->next;

    cout << "\n--- Student Records (Backward) ---\n";
    while (temp != NULL) {
        cout << "ID: " << temp->id
             << " | Name: " << temp->name
             << " | Semester: " << temp->semester
             << " | GPA: " << temp->gpa << endl;
        temp = temp->prev;
    }
}


int main() {
    int choice;

    do {
        cout << "\n===== Student Enrollment Management System =====\n";
        cout << "1. Insert at Beginning\n";
        cout << "2. Insert at End\n";
        cout << "3. Insert at Position\n";
        cout << "4. Delete at Beginning\n";
        cout << "5. Delete at End\n";
        cout << "6. Delete at Position\n";
        cout << "7. Display Forward\n";
        cout << "8. Display Backward\n";
        cout << "9. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        int id, sem, pos;
        float gpa;
        string name;

        switch (choice) {
            case 1:
                cout << "Enter ID: ";
                cin >> id;
                cout << "Enter Name: ";
                cin >> name;
                cout << "Enter Semester: ";
                cin >> sem;
                cout << "Enter GPA: ";
                cin >> gpa;
                insertAtBeginning(id, name, sem, gpa);
                break;

            case 2:
                cout << "Enter ID: ";
                cin >> id;
                cout << "Enter Name: ";
                cin >> name;
                cout << "Enter Semester: ";
                cin >> sem;
                cout << "Enter GPA: ";
                cin >> gpa;
                insertAtEnd(id, name, sem, gpa);
                break;

            case 3:
                cout << "Enter Position: ";
                cin >> pos;
                cout << "Enter ID: ";
                cin >> id;
                cout << "Enter Name: ";
                cin >> name;
                cout << "Enter Semester: ";
                cin >> sem;
                cout << "Enter GPA: ";
                cin >> gpa;
                insertAtPosition(pos, id, name, sem, gpa);
                break;

            case 4:
                deleteAtBeginning();
                break;

            case 5:
                deleteAtEnd();
                break;

            case 6:
                cout << "Enter Position: ";
                cin >> pos;
                deleteAtPosition(pos);
                break;

            case 7:
                displayForward();
                break;

            case 8:
                displayBackward();
                break;

            case 9:
                cout << "Exiting...\n";
                break;

            default:
                cout << "Invalid choice.\n";
        }

    } while (choice != 9);

    return 0;
}
