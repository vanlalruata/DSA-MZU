#include <iostream>
using namespace std;

// Function to perform Insertion Sort
void insertionSort(int arr[], int size) {
    for (int i = 1; i < size; i++) {
        int key = arr[i];
        int j = i - 1;

        // Move elements of arr[0..i-1] that are greater than key
        // to one position ahead of their current position
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key; // Insert the key at its correct position
    }
}

// Function to print the array
void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    const int size = 10; // Maximum size of the array
    int array[size];

    // User input
    cout << "Enter " << size << " numbers:" << endl;
    for (int i = 0; i < size; i++) {
        cin >> array[i];
    }

    // Perform Insertion Sort
    insertionSort(array, size);

    // Print the sorted array
    cout << "Sorted array:" << endl;
    printArray(array, size);

    return 0;
}


// Insertion Sort Function: The insertionSort function implements the Insertion Sort algorithm. It builds the sorted array one element at a time by comparing each new element (the key) to the already sorted elements and placing it in the correct position.

// User Input: The program prompts the user to enter 10 numbers, which are stored in a one-dimensional array.

// Sorting and Output: After sorting the array using Insertion Sort, the program prints the sorted array.