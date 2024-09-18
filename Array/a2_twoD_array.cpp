#include <iostream>
using namespace std;

int main() {
    // Define a 2D array (3 rows and 4 columns)
    const int rows = 3;
    const int cols = 4;
    int array[rows][cols] = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12}
    };

    // Print the elements of the 2D array
    cout << "Elements of the 2D array:" << endl;
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            cout << array[i][j] << " ";
        }
        cout << endl; // Move to the next line after each row
    }

    return 0;
}

// Array Declaration: The program declares a 2D array called array with 3 rows and 4 columns. It initializes the array with values from 1 to 12.

// Nested Loops: It uses nested for loops to iterate through each element of the 2D array. The outer loop iterates over the rows, and the inner loop iterates over the columns.

// Output: Each element is printed, and after finishing each row, it moves to the next line for better readability.