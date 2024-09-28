#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* prev;
    Node* next;

    Node(int value) {
        data = value;
        prev = nullptr;
        next = nullptr;
    }
};

class DoublyLinkedList {
private:
    Node* head;

public:
    DoublyLinkedList() {
        head = nullptr;
    }

    // Function to insert a new node at the end of the list
    void insert(int value) {
        Node* newNode = new Node(value);

        if (head == nullptr) {
            head = newNode;
        } else {
            Node* temp = head;
            while (temp->next != nullptr) {
                temp = temp->next;
            }
            temp->next = newNode;
            newNode->prev = temp;
        }
    }

    // Function to display the linked list from start to end
    void displayForward() {
        if (head == nullptr) {
            cout << "The list is empty." << endl;
            return;
        }

        Node* temp = head;
        while (temp != nullptr) {
            cout << temp->data << " <-> ";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }

    // Function to display the linked list from end to start
    void displayBackward() {
        if (head == nullptr) {
            cout << "The list is empty." << endl;
            return;
        }

        Node* temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }

        while (temp != nullptr) {
            cout << temp->data << " <-> ";
            temp = temp->prev;
        }
        cout << "NULL" << endl;
    }

    // Function to delete the first node with a given value
    void deleteNode(int value) {
        if (head == nullptr) {
            cout << "List is empty." << endl;
            return;
        }

        Node* temp = head;

        // If head node itself holds the key
        if (temp != nullptr && temp->data == value) {
            head = temp->next; // Change head
            if (head != nullptr) {
                head->prev = nullptr; // Update the previous of new head
            }
            delete temp;
            return;
        }

        // Search for the node to be deleted
        while (temp != nullptr && temp->data != value) {
            temp = temp->next;
        }

        // If the value was not found in the list
        if (temp == nullptr) {
            cout << "Value not found in the list." << endl;
            return;
        }

        // Unlink the node from the doubly linked list
        if (temp->next != nullptr) {
            temp->next->prev = temp->prev;
        }

        if (temp->prev != nullptr) {
            temp->prev->next = temp->next;
        }

        delete temp;
    }

    // Destructor to free memory
    ~DoublyLinkedList() {
        Node* current = head;
        Node* nextNode;

        while (current != nullptr) {
            nextNode = current->next;
            delete current;
            current = nextNode;
        }
    }
};

int main() {
    DoublyLinkedList list;

    list.insert(10);
    list.insert(20);
    list.insert(30);
    list.insert(40);

    cout << "Doubly Linked List (Forward): ";
    list.displayForward();

    cout << "Doubly Linked List (Backward): ";
    list.displayBackward();

    cout << "Deleting node with value 20." << endl;
    list.deleteNode(20);
    list.displayForward();

    return 0;
}
