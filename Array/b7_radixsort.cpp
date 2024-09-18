#include <iostream>
#include <vector>
using namespace std;

// Function to get the largest number in the array
int getMax(int arr[], int size) {
    int max = arr[0];
    for (int i = 1; i < size; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }
    return max;
}

// Function to perform Counting Sort based on the digit represented by exp
void countingSort(int arr[], int size, int exp) {
    vector<int> output(size); // Output array
    int count[10] = {0}; // Count array

    // Count occurrences of each digit
    for (int i = 0; i < size; i++) {
        count[(arr[i] / exp) % 10]++;
    }

    // Change count[i] so that it now contains the actual position of this digit in output[]
    for (int i = 1; i < 10; i++) {
        count[i] += count[i - 1];
    }

    // Build the output array
    for (int i = size - 1; i >= 0; i--) {
        output[count[(arr[i] / exp) % 10] - 1] = arr[i];
        count[(arr[i] / exp) % 10]--;
    }

    // Copy the output array to arr[], so that arr[] now contains sorted numbers according to the current digit
    for (int i = 0; i < size; i++) {
        arr[i] = output[i];
    }
}

// Function to perform Radix Sort
void radixSort(int arr[], int size) {
    // Get the maximum number to know the number of digits
    int max = getMax(arr, size);

    // Apply counting sort to sort elements based on each digit
    for (int exp = 1; max / exp > 0; exp *= 10) {
        countingSort(arr, size, exp);
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

    // Perform Radix Sort
    radixSort(array, size);

    // Print the sorted array
    cout << "Sorted array:" << endl;
    printArray(array, size);

    return 0;
}


// Get Maximum Function: The getMax function finds the largest number in the array to determine the number of digits for sorting.

// Counting Sort Function: The countingSort function sorts the array based on the digit represented by exp (1 for units, 10 for tens, etc.). It counts the occurrences of each digit and builds the sorted output array.

// Radix Sort Function: The radixSort function applies the counting sort for each digit from the least significant to the most significant.

// User Input: The program prompts the user to enter 10 numbers, which are stored in a one-dimensional array.

// Sorting and Output: After sorting the array using Radix Sort, the program prints the sorted array.