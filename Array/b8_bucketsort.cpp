#include <iostream>
#include <vector>
#include <algorithm> // For std::sort
using namespace std;

// Function to perform Bucket Sort
void bucketSort(int arr[], int size) {
    // Create buckets
    vector<int> buckets[size];

    // Find the maximum element to determine the range of values
    int maxValue = arr[0];
    for (int i = 1; i < size; i++) {
        if (arr[i] > maxValue) {
            maxValue = arr[i];
        }
    }

    // Place elements in their respective buckets
    for (int i = 0; i < size; i++) {
        int bucketIndex = (arr[i] * size) / (maxValue + 1);
        buckets[bucketIndex].push_back(arr[i]);
    }

    // Sort individual buckets and concatenate
    int index = 0;
    for (int i = 0; i < size; i++) {
        if (!buckets[i].empty()) {
            sort(buckets[i].begin(), buckets[i].end());
            for (size_t j = 0; j < buckets[i].size(); j++) {
                arr[index++] = buckets[i][j];
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

    // Perform Bucket Sort
    bucketSort(array, size);

    // Print the sorted array
    cout << "Sorted array:" << endl;
    printArray(array, size);

    return 0;
}


// Bucket Sort Function: The bucketSort function creates a number of buckets (vectors) based on the range of values. It then distributes the elements of the array into these buckets.

// Finding Maximum Value: The program finds the maximum value in the array to determine the range of values for bucket distribution.

// Sorting Buckets: Each bucket is sorted individually using the standard sort function, and then the sorted elements are concatenated back into the original array.

// User Input: The program prompts the user to enter 10 numbers, which are stored in a one-dimensional array.

// Sorting and Output: After sorting the array using Bucket Sort, the program prints the sorted array.