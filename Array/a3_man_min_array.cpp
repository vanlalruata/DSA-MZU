//C++ program to find the maximum and minimum values in an integer array

#include <iostream>
using namespace std;

void findMaxMin(int arr[], int size, int &maxValue, int &minValue) {
    maxValue = arr[0]; // Initialize with the first element
    minValue = arr[0]; // Initialize with the first element

    for (int i = 1; i < size; i++) {
        if (arr[i] > maxValue) {
            maxValue = arr[i];  // Update maxValue
        }
        if (arr[i] < minValue) {
            minValue = arr[i];  // Update minValue
        }
    }
}

int main() {
    int n;

    // User input for the size of the array
    cout << "Enter the size of the array: ";
    cin >> n;

    int arr[n];

    // User input for array elements
    cout << "Enter " << n << " elements: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int maxValue, minValue;

    // Call function to find the maximum and minimum
    findMaxMin(arr, n, maxValue, minValue);

    // Display the results
    cout << "Maximum value: " << maxValue << endl;
    cout << "Minimum value: " << minValue << endl;

    return 0;
}
