#include <iostream>
using namespace std;

// Function to perform Bubble Sort
void bubbleSort(int arr[], int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                // Swap arr[j] and arr[j+1]
                swap(arr[j], arr[j + 1]);
            }
        }
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

    // Perform Bubble Sort
    bubbleSort(array, size);

    // Print the sorted array
    cout << "Sorted array:" << endl;
    printArray(array, size);

    return 0;
}

// Bubble Sort Function: The bubbleSort function implements the Bubble Sort algorithm. It repeatedly steps through the array, compares adjacent elements, and swaps them if they are in the wrong order. This process continues until the array is sorted.

// User Input: The program prompts the user to enter 10 numbers, which are stored in a one-dimensional array.

// Sorting and Output: After sorting the array using Bubble Sort, the program prints the sorted array.