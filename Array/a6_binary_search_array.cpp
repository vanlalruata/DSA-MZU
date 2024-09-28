//C++ program that implements binary search in a sorted integer array

#include <iostream>
using namespace std;

// Function to perform binary search
int binarySearch(int arr[], int size, int key) {
    int left = 0;
    int right = size - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2; // To avoid potential overflow

        if (arr[mid] == key) {
            return mid;  // Element found
        }
        if (arr[mid] < key) {
            left = mid + 1;  // Search in the right half
        } else {
            right = mid - 1;  // Search in the left half
        }
    }

    return -1;  // Element not found
}

int main() {
    int n, key;

    // User input for the size of the array
    cout << "Enter the size of the sorted array: ";
    cin >> n;

    int arr[n];

    // User input for array elements
    cout << "Enter " << n << " sorted elements: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    // User input for the element to search
    cout << "Enter the element to search: ";
    cin >> key;

    // Perform binary search
    int result = binarySearch(arr, n, key);

    // Output the result
    if (result != -1) {
        cout << "Element found at index " << result << endl;
    } else {
        cout << "Element not found in the array." << endl;
    }

    return 0;
}
