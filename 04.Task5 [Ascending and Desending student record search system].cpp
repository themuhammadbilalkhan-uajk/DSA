#include <iostream>
using namespace std;


int binarySearchAscending(int arr[], int size, int key) {
    int low = 0;
    int high = size - 1;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (arr[mid] == key) {
            return mid; 
        }
        if (arr[mid] < key) {
            low = mid + 1; 
        } else {
            high = mid - 1; 
        }
    }
    return -1; 
}


int binarySearchDescending(int arr[], int size, int key) {
    int low = 0;
    int high = size - 1;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (arr[mid] == key) {
            return mid; 
        }
        if (arr[mid] > key) {
            low = mid + 1; 
        } else {
            high = mid - 1; 
        }
    }
    return -1; 
}


void sortAscending(int arr[], int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}


void sortDescending(int arr[], int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (arr[j] < arr[j + 1]) { 
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

// Function to copy array
void copyArray(int src[], int dest[], int size) {
    for (int i = 0; i < size; i++) {
        dest[i] = src[i];
    }
}

int main() {
    int size;


    cout << "     Student Roll Number Search System   " << endl;
    cout << " "<<endl;
    cout << "Enter total number of students: ";
    cin >> size;

    if (size <= 0) {
        cout << "Error: Please enter a positive number!" << endl;
        return 1;
    }

    int original[100];     
    int ascArray[100];     
    int descArray[100];    

  
    cout << "Enter " << size << " roll numbers:" << endl;
    for (int i = 0; i < size; i++) {
        cout << "Roll No. " << (i + 1) << ": ";
        cin >> original[i];
    }

 
    copyArray(original, ascArray, size);
    copyArray(original, descArray, size);

    sortAscending(ascArray, size);
    sortDescending(descArray, size);

   
    cout << "\n--- Arrays Ready ---" << endl;
    cout << "Ascending Order : ";
    for (int i = 0; i < size; i++) cout << ascArray[i] << " ";
    cout << endl;

    cout << "Descending Order: ";
    for (int i = 0; i < size; i++) cout << descArray[i] << " ";
    cout << endl << endl;

   
    int key;
    cout << "Enter roll number to search: ";
    cin >> key;

    int result = -1;


    if (key % 2 == 0) {
    
        cout << "[Searching in ASCENDING order (Even Roll No)]" << endl;
        result = binarySearchAscending(ascArray, size, key);
    } else {
    
        cout << "[Searching in DESCENDING order (Odd Roll No)]" << endl;
        result = binarySearchDescending(descArray, size, key);
    }

    if (result != -1) {
        cout << "FOUND: Roll number " << key 
             << " at position " << (result + 1) << "." << endl;
    } else {
        cout << "NOT FOUND: Roll number " << key 
             << " is not in the list." << endl;
    }

    cout<<" "<<endl;
    cout << "\nDesigned By Muhammad Bilal Khan.Thank you for using!" << endl;
    return 0;
}
