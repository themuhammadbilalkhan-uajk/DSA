#include <iostream>
#include <string>
using namespace std;

#define MAX 100

class BookStack {
    string books[MAX];
    int top;

public:
    BookStack() {
        top = -1;
    }

    bool isEmpty() {
        return top == -1;
    }

    bool isFull() {
        return top == MAX - 1;
    }

    void pushBook(string book) {
        if (isFull()) {
            cout << "Stack is full. Cannot add more books.\n";
        } else {
            books[++top] = book;
            cout << "Book added successfully.\n";
        }
    }

    void popBook() {
        if (isEmpty()) {
            cout << "Stack is empty. No book to remove.\n";
        } else {
            cout << "Removed Book: " << books[top--] << endl;
        }
    }

    void peekBook() {
        if (isEmpty()) {
            cout << "Stack is empty.\n";
        } else {
            cout << "Top Book: " << books[top] << endl;
        }
    }

    void displayBooks() {
        if (isEmpty()) {
            cout << "No books in the stack.\n";
        } else {
            cout << "Books (Top to Bottom):\n";
            for (int i = top; i >= 0; i--) {
                cout << books[i] << endl;
            }
        }
    }
};

int main() {
    BookStack stack;
    int choice;
    string book;

    do {
        cout << "\nBook Management System\n";
        cout << "1. Add Book\n";
        cout << "2. Remove Book\n";
        cout << "3. View Top Book\n";
        cout << "4. Display All Books\n";
        cout << "5. Check if Stack is Empty\n";
        cout << "6. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;
        cin.ignore();

        switch (choice) {
            case 1:
                cout << "Enter book name: ";
                getline(cin, book);
                stack.pushBook(book);
                break;
            case 2:
                stack.popBook();
                break;
            case 3:
                stack.peekBook();
                break;
            case 4:
                stack.displayBooks();
                break;
            case 5:
                if (stack.isEmpty())
                    cout << "Stack is empty.\n";
                else
                    cout << "Stack is not empty.\n";
                break;
            case 6:
                cout << "Exiting program.\n";
                break;
            default:
                cout << "Invalid choice.\n";
        }
    } while (choice != 6);

    return 0;
}
