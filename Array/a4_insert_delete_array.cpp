//C++ program that implements insertion and deletion in an integer array

#include <iostream>
using namespace std;

void insertElement(int arr[], int &size, int element, int position) {
    if (position < 0 || position > size) {
        cout << "Invalid position!" << endl;
        return;
    }

    // Shift elements to the right to make space for the new element
    for (int i = size; i > position; i--) {
        arr[i] = arr[i - 1];
    }

    // Insert the new element at the specified position
    arr[position] = element;
    size++;  // Increase the size of the array
}

void deleteElement(int arr[], int &size, int position) {
    if (position < 0 || position >= size) {
        cout << "Invalid position!" << endl;
        return;
    }

    // Shift elements to the left to fill the gap after deletion
    for (int i = position; i < size - 1; i++) {
        arr[i] = arr[i + 1];
    }

    size--;  // Decrease the size of the array
}

void displayArray(int arr[], int size) {
    if (size == 0) {
        cout << "Array is empty!" << endl;
        return;
    }

    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    int n;
    
    // User input for the size of the array
    cout << "Enter the size of the array: ";
    cin >> n;

    int arr[100];  // Assuming the maximum size of the array is 100

    // User input for array elements
    cout << "Enter " << n << " elements: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int size = n;
    int choice;

    do {
        cout << "\nMenu:\n";
        cout << "1. Insert Element\n";
        cout << "2. Delete Element\n";
        cout << "3. Display Array\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                int element, position;
                cout << "Enter element to insert: ";
                cin >> element;
                cout << "Enter position to insert (0 to " << size << "): ";
                cin >> position;
                insertElement(arr, size, element, position);
                break;
            }
            case 2: {
                int position;
                cout << "Enter position to delete (0 to " << size - 1 << "): ";
                cin >> position;
                deleteElement(arr, size, position);
                break;
            }
            case 3:
                cout << "Current Array: ";
                displayArray(arr, size);
                break;
            case 4:
                cout << "Exiting..." << endl;
                break;
            default:
                cout << "Invalid choice!" << endl;
        }
    } while (choice != 4);

    return 0;
}
