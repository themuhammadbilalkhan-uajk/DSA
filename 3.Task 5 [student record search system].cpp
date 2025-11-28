#include <iostream>
using namespace std;


int linearSearch(int arr[], int size, int key) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == key) {
            return i; 
        }
    }
    return -1; 
}


int binarySearch(int arr[], int size, int key) {
    int Starting_Point = 0;
    int Ending_Point = size - 1;

    while (Starting_Point <= Ending_Point) {
        int mid = Starting_Point + (Ending_Point - Starting_Point) / 2;

        if (arr[mid] == key) {
            return mid; 
        } else if (arr[mid] < key) {
            Starting_Point = mid + 1;
        } else {
            Ending_Point = mid - 1;
        }
    }
    return -1; 
}


void copyArray(int original[], int copy[], int size) {
    for (int i = 0; i < size; i++) {
        copy[i] = original[i];
    }
}


void bubbleSort(int arr[], int size) {
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

int main() {
    int size;
    
 
    cout << "      Student Record Search System     " << endl;
    cout << " "<<endl;
    cout << "Enter total number of students: ";
    cin >> size;


    if (size <= 0) {
        cout << "Error: Number of students must be positive!" << endl;
        return 1;
    }

   
    int unsortedArray[size];  
    int sortedArray[size];    

 
    cout << "Enter " << size << " roll numbers:" << endl;
    for (int i = 0; i < size; i++) {
        cout << "Roll No. " << (i + 1) << ": ";
        cin >> unsortedArray[i];
    }

   
    copyArray(unsortedArray, sortedArray, size);
    bubbleSort(sortedArray, size);

  
    cout << "\n--- Records Summary ---" << endl;
    cout << "Unsorted Records: ";
    for (int i = 0; i < size; i++) {
        cout << unsortedArray[i] << " ";
    }
    
    cout <<""<< endl;

    cout << "Sorted Records:   ";
    for (int i = 0; i < size; i++) {
        cout << sortedArray[i] << " ";
    }
    cout << endl << endl;


    int choice, key, result;
    cout << "Choose Search Method:" << endl;
    cout << "1. Linear Search" << endl;
    cout << "2. Binary Search" << endl;
    cout << "Enter choice (1 or 2): ";
    cin >> choice;

    cout << "Enter roll number to search: ";
    cin >> key;

 
    if (choice == 1) {
        result = linearSearch(unsortedArray, size, key);
        cout << "\n[Using Linear Search on unsorted list]" << endl;
    } else if (choice == 2) {
        result = binarySearch(sortedArray, size, key);
        cout << "\n[Using Binary Search on sorted list]" << endl;
    } else {
        cout << "Invalid choice!" << endl;
        
    }

    cout<<" "<<endl;
    
    if (result != -1) {
        cout << "SUCCESS: Roll number " << key 
             << " found at position " << (result + 1) << "." << endl;
    } else {
        cout << "NOT FOUND: Roll number " << key 
             << " is not in the records." << endl;
    }

    cout << " "<< endl;
    cout << "Thank you for using the system. Designed By Muhammad Bilal Khan!"<< endl;
    return 0;
}