#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int value) {
        data = value;
        next = nullptr;
    }
};

class CircularLinkedList {
private:
    Node* head;

public:
    CircularLinkedList() {
        head = nullptr;
    }

    // Function to insert a new node at the end of the list
    void insert(int value) {
        Node* newNode = new Node(value);

        if (head == nullptr) {
            head = newNode;
            newNode->next = head;  // Point to itself, making it circular
        } else {
            Node* temp = head;
            while (temp->next != head) {
                temp = temp->next;
            }
            temp->next = newNode;
            newNode->next = head;  // Point new node to head
        }
    }

    // Function to display the circular linked list
    void display() {
        if (head == nullptr) {
            cout << "The list is empty." << endl;
            return;
        }

        Node* temp = head;
        do {
            cout << temp->data << " -> ";
            temp = temp->next;
        } while (temp != head);

        cout << "HEAD" << endl;  // Indicating it's circular
    }

    // Function to delete the first node with a given value
    void deleteNode(int value) {
        if (head == nullptr) {
            cout << "List is empty." << endl;
            return;
        }

        Node* temp = head;
        Node* prev = nullptr;

        // If head node contains the value
        if (head->data == value) {
            if (head->next == head) {  // If only one node is present
                delete head;
                head = nullptr;
            } else {
                Node* last = head;
                while (last->next != head) {
                    last = last->next;
                }
                last->next = head->next;  // Update last node to point to next of head
                Node* toDelete = head;
                head = head->next;  // Move head
                delete toDelete;
            }
            return;
        }

        // For non-head nodes
        do {
            prev = temp;
            temp = temp->next;
        } while (temp != head && temp->data != value);

        if (temp == head) {
            cout << "Value not found in the list." << endl;
            return;
        }

        prev->next = temp->next;
        delete temp;
    }

    // Destructor to free memory
    ~CircularLinkedList() {
        if (head == nullptr) return;

        Node* temp = head;
        do {
            Node* nextNode = temp->next;
            delete temp;
            temp = nextNode;
        } while (temp != head);
    }
};

int main() {
    CircularLinkedList list;

    list.insert(10);
    list.insert(20);
    list.insert(30);
    list.insert(40);

    cout << "Circular Linked List: ";
    list.display();

    cout << "Deleting node with value 20." << endl;
    list.deleteNode(20);
    list.display();

    return 0;
}
