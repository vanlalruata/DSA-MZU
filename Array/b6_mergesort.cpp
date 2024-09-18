#include <iostream>
using namespace std;

// Function to merge two subarrays
void merge(int arr[], int left, int mid, int right) {
    int n1 = mid - left + 1; // Size of the left subarray
    int n2 = right - mid;    // Size of the right subarray

    int* L = new int[n1]; // Temporary array for left subarray
    int* R = new int[n2]; // Temporary array for right subarray

    // Copy data to temporary arrays L[] and R[]
    for (int i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];

    // Merge the temporary arrays back into arr[left..right]
    int i = 0; // Initial index of first subarray
    int j = 0; // Initial index of second subarray
    int k = left; // Initial index of merged subarray

    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    // Copy the remaining elements of L[], if any
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    // Copy the remaining elements of R[], if any
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }

    delete[] L; // Free the temporary arrays
    delete[] R;
}

// Function to perform Merge Sort
void mergeSort(int arr[], int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;

        // Sort first and second halves
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);
        
        // Merge the sorted halves
        merge(arr, left, mid, right);
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

    // Perform Merge Sort
    mergeSort(array, 0, size - 1);

    // Print the sorted array
    cout << "Sorted array:" << endl;
    printArray(array, size);

    return 0;
}


// Merge Function: The merge function combines two sorted subarrays into a single sorted array.

// Merge Sort Function: The mergeSort function recursively divides the array into halves until each subarray contains a single element, then merges the sorted halves.

// User Input: The program prompts the user to enter 10 numbers, which are stored in a one-dimensional array.

// Sorting and Output: After sorting the array using Merge Sort, the program prints the sorted array.