//C++ program that implements linear search in an integer array

#include <iostream>
using namespace std;

// Function to perform linear search
int linearSearch(int arr[], int size, int key) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == key) {
            return i;  // Return the index if the element is found
        }
    }
    return -1;  // Return -1 if the element is not found
}

int main() {
    int n, key;

    // User input for the size of the array
    cout << "Enter the size of the array: ";
    cin >> n;

    int arr[n];

    // User input for array elements
    cout << "Enter " << n << " elements: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    // User input for the element to search
    cout << "Enter the element to search: ";
    cin >> key;

    // Perform linear search
    int result = linearSearch(arr, n, key);

    // Output the result
    if (result != -1) {
        cout << "Element found at index " << result << endl;
    } else {
        cout << "Element not found in the array." << endl;
    }

    return 0;
}
