#include <iostream>
using namespace std;

int main() {
    int salaries[10];
    int n = 10;

    cout << "Enter 10 employee salaries:\n";
    for (int i = 0; i < n; i++) {
        cin >> salaries[i];
    }

    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (salaries[j] > salaries[j + 1]) {
                int temp = salaries[j];
                salaries[j] = salaries[j + 1];
                salaries[j + 1] = temp;
            }
        }
    }

    cout << "\nSalaries in Ascending Order:\n";
    for (int i = 0; i < n; i++) {
        cout << salaries[i] << " ";
    }

    return 0;
}

