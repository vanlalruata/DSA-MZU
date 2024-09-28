//C++ program that implements a queue using arrays

#include <iostream>
using namespace std;

class Queue {
private:
    int* arr;         // Array to store queue elements
    int front;        // Index of the front element
    int rear;         // Index of the rear element
    int capacity;     // Maximum number of elements queue can hold
    int count;        // Current number of elements in the queue

public:
    // Constructor to initialize the queue
    Queue(int size) {
        capacity = size;
        arr = new int[capacity];
        front = 0;
        rear = -1;
        count = 0;
    }

    // Destructor to free memory
    ~Queue() {
        delete[] arr;
    }

    // Function to add an item to the queue
    void enqueue(int x) {
        if (count == capacity) {
            cout << "Queue Overflow! Cannot enqueue " << x << endl;
            return;
        }
        rear = (rear + 1) % capacity; // Circular increment
        arr[rear] = x;
        count++;
        cout << x << " enqueued to queue." << endl;
    }

    // Function to remove an item from the queue
    int dequeue() {
        if (count == 0) {
            cout << "Queue Underflow! Cannot dequeue from empty queue." << endl;
            return -1; // Indicates empty queue
        }
        int item = arr[front];
        front = (front + 1) % capacity; // Circular increment
        count--;
        return item; // Return dequeued item
    }

    // Function to return the front item from the queue without removing it
    int peek() {
        if (count == 0) {
            cout << "Queue is empty." << endl;
            return -1; // Indicates empty queue
        }
        return arr[front]; // Return front element
    }

    // Function to check if the queue is empty
    bool isEmpty() {
        return count == 0; // Returns true if queue is empty
    }

    // Function to return the current size of the queue
    int size() {
        return count; // Returns the number of elements in the queue
    }
};

int main() {
    Queue queue(5); // Create a queue of capacity 5

    queue.enqueue(10);
    queue.enqueue(20);
    queue.enqueue(30);
    queue.enqueue(40);
    queue.enqueue(50);
    
    // Trying to enqueue another element to check overflow
    queue.enqueue(60);

    cout << "Front element is: " << queue.peek() << endl;

    cout << "Dequeuing elements from queue: " << endl;
    while (!queue.isEmpty()) {
        cout << queue.dequeue() << " dequeued from queue." << endl;
    }

    // Trying to dequeue from an empty queue to check underflow
    queue.dequeue();

    return 0;
}
