#include <iostream>
#include <string>
using namespace std;

#define MAX 100

class TicketQueue {
    string tickets[MAX];
    int front, rear;

public:
    TicketQueue() {
        front = -1;
        rear = -1;
    }

    bool isEmpty() {
        return front == -1 || front > rear;
    }

    bool isFull() {
        return rear == MAX - 1;
    }

    void enqueue(string ticket) {
        if (isFull()) {
            cout << "Queue is full. Cannot add more tickets.\n";
        } else {
            if (front == -1)
                front = 0;
            tickets[++rear] = ticket;
            cout << "Ticket added successfully.\n";
        }
    }

    void dequeue() {
        if (isEmpty()) {
            cout << "Queue is empty. No ticket to process.\n";
        } else {
            cout << "Processed Ticket: " << tickets[front++] << endl;
        }
    }

    void display() {
        if (isEmpty()) {
            cout << "No pending tickets.\n";
        } else {
            cout << "Pending Tickets:\n";
            for (int i = front; i <= rear; i++) {
                cout << tickets[i] << endl;
            }
        }
    }

    void cancelTicket(string ticket) {
        if (isEmpty()) {
            cout << "Queue is empty.\n";
            return;
        }

        int index = -1;
        for (int i = front; i <= rear; i++) {
            if (tickets[i] == ticket) {
                index = i;
                break;
            }
        }

        if (index == -1) {
            cout << "Ticket not found.\n";
        } else {
            for (int i = index; i < rear; i++) {
                tickets[i] = tickets[i + 1];
            }
            rear--;
            cout << "Ticket cancelled successfully.\n";
        }
    }
};

int main() {
    TicketQueue queue;
    int choice;
    string ticket;

    do {
        cout << "\nCustomer Service Ticketing System\n";
        cout << "1. Add Ticket\n";
        cout << "2. Process Ticket\n";
        cout << "3. Display Pending Tickets\n";
        cout << "4. Check if Queue is Empty\n";
        cout << "5. Check if Queue is Full\n";
        cout << "6. Cancel Ticket\n";
        cout << "7. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;
        cin.ignore();

        switch (choice) {
            case 1:
                cout << "Enter ticket description: ";
                getline(cin, ticket);
                queue.enqueue(ticket);
                break;
            case 2:
                queue.dequeue();
                break;
            case 3:
                queue.display();
                break;
            case 4:
                if (queue.isEmpty())
                    cout << "Queue is empty.\n";
                else
                    cout << "Queue is not empty.\n";
                break;
            case 5:
                if (queue.isFull())
                    cout << "Queue is full.\n";
                else
                    cout << "Queue is not full.\n";
                break;
            case 6:
                cout << "Enter ticket description to cancel: ";
                getline(cin, ticket);
                queue.cancelTicket(ticket);
                break;
            case 7:
                cout << "Exiting program.\n";
                break;
            default:
                cout << "Invalid choice.\n";
        }
    } while (choice != 7);

    return 0;
}
