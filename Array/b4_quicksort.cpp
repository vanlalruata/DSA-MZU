#include <iostream>
using namespace std;

// Function to perform Quick Sort
void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pivot = arr[high];  // Choose the last element as the pivot
        int i = (low - 1);      // Index of the smaller element

        // Partitioning
        for (int j = low; j < high; j++) {
            if (arr[j] <= pivot) {
                i++;
                swap(arr[i], arr[j]);
            }
        }
        swap(arr[i + 1], arr[high]); // Place the pivot in the correct position
        int pi = i + 1;

        // Recursively sort elements before and after partition
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
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

    // Perform Quick Sort
    quickSort(array, 0, size - 1);

    // Print the sorted array
    cout << "Sorted array:" << endl;
    printArray(array, size);

    return 0;
}


// Explanation:

//     Quick Sort Function: The quickSort function implements the Quick Sort algorithm. It uses a pivot element to partition the array and then recursively sorts the subarrays.

//     User Input: The program prompts the user to enter 10 numbers, which are stored in a one-dimensional array.

//     Sorting and Output: After sorting the array using Quick Sort, the program prints the sorted array.