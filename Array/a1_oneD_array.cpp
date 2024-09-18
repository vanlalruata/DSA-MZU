#include <iostream>
using namespace std;

int main() {
    // Define a one-dimensional array
    const int size = 5;
    int array[size] = {10, 20, 30, 40, 50};

    // Calculate the sum of the array elements
    int sum = 0;
    for (int i = 0; i < size; ++i) {
        sum += array[i];
    }

    // Print the elements of the array
    cout << "Elements of the one-dimensional array:" << endl;
    for (int i = 0; i < size; ++i) {
        cout << array[i] << " ";
    }
    cout << endl;

    // Print the sum of the elements
    cout << "Sum of the elements: " << sum << endl;

    return 0;
}


// Array Declaration: The program declares a one-dimensional array called array with 5 elements and initializes it with values 10, 20, 30, 40, and 50.

// Sum Calculation: A for loop iterates through the array to calculate the sum of its elements.

// Output: The program prints each element of the array and the total sum of the elements.