#include <iostream>
using namespace std;

// Function to heapify a subtree rooted at index i
void heapify(int arr[], int n, int i) {
    int largest = i;       // Initialize largest as root
    int left = 2 * i + 1; // left = 2*i + 1
    int right = 2 * i + 2; // right = 2*i + 2

    // If left child is larger than root
    if (left < n && arr[left] > arr[largest])
        largest = left;

    // If right child is larger than largest so far
    if (right < n && arr[right] > arr[largest])
        largest = right;

    // If largest is not root
    if (largest != i) {
        swap(arr[i], arr[largest]);

        // Recursively heapify the affected subtree
        heapify(arr, n, largest);
    }
}

// Function to perform Heap Sort
void heapSort(int arr[], int n) {
    // Build heap (rearrange array)
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);

    // One by one extract an element from heap
    for (int i = n - 1; i > 0; i--) {
        // Move current root to end
        swap(arr[0], arr[i]);

        // Call max heapify on the reduced heap
        heapify(arr, i, 0);
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

    // Perform Heap Sort
    heapSort(array, size);

    // Print the sorted array
    cout << "Sorted array:" << endl;
    printArray(array, size);

    return 0;
}


// Heapify Function: The heapify function ensures that the subtree rooted at index i satisfies the heap property. It checks whether the left and right children are larger than the root and swaps them if necessary.

// Heap Sort Function: The heapSort function first builds a max heap from the input array and then repeatedly extracts the maximum element (the root of the heap) and places it at the end of the array, followed by reducing the heap size.

// User Input: The program prompts the user to enter 10 numbers, which are stored in a one-dimensional array.

// Sorting and Output: After sorting the array using Heap Sort, the program prints the sorted array.