//C++ program that implements a stack using arrays

#include <iostream>
using namespace std;

class Stack {
private:
    int* arr;         // Array to store stack elements
    int top;          // Index of the top element
    int capacity;     // Maximum number of elements stack can hold

public:
    // Constructor to initialize the stack
    Stack(int size) {
        capacity = size;
        arr = new int[capacity];
        top = -1; // Indicates that the stack is empty
    }

    // Destructor to free memory
    ~Stack() {
        delete[] arr;
    }

    // Function to add an item to the stack
    void push(int x) {
        if (top == capacity - 1) {
            cout << "Stack Overflow! Cannot push " << x << endl;
            return;
        }
        arr[++top] = x; // Increment top and add element
        cout << x << " pushed to stack." << endl;
    }

    // Function to remove an item from the stack
    int pop() {
        if (top == -1) {
            cout << "Stack Underflow! Cannot pop from empty stack." << endl;
            return -1; // Indicates empty stack
        }
        return arr[top--]; // Return top element and decrement top
    }

    // Function to return the top item from the stack without removing it
    int peek() {
        if (top == -1) {
            cout << "Stack is empty." << endl;
            return -1; // Indicates empty stack
        }
        return arr[top]; // Return top element
    }

    // Function to check if the stack is empty
    bool isEmpty() {
        return top == -1; // Returns true if stack is empty
    }

    // Function to return the size of the stack
    int size() {
        return top + 1; // Returns the number of elements in the stack
    }
};

int main() {
    Stack stack(5); // Create a stack of capacity 5

    stack.push(10);
    stack.push(20);
    stack.push(30);
    stack.push(40);
    stack.push(50);
    
    // Trying to push another element to check overflow
    stack.push(60);

    cout << "Top element is: " << stack.peek() << endl;

    cout << "Popping elements from stack: " << endl;
    while (!stack.isEmpty()) {
        cout << stack.pop() << " popped from stack." << endl;
    }

    // Trying to pop from an empty stack to check underflow
    stack.pop();

    return 0;
}
