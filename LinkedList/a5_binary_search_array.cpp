//C++ program that implements a Binary Search Tree (BST) with methods for insertion, deletion, and searching.

#include <iostream>
using namespace std;

// Definition of a Node
struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int value) {
        data = value;
        left = nullptr;
        right = nullptr;
    }
};

// Class for Binary Search Tree
class BST {
private:
    Node* root;

    // Helper function to insert a new node
    Node* insert(Node* node, int key) {
        if (node == nullptr) {
            return new Node(key);
        }
        if (key < node->data) {
            node->left = insert(node->left, key);
        } else if (key > node->data) {
            node->right = insert(node->right, key);
        }
        return node; // Return unchanged node pointer
    }

    // Helper function to search for a key
    Node* search(Node* node, int key) {
        if (node == nullptr || node->data == key) {
            return node; // Key found or reached leaf
        }
        if (key < node->data) {
            return search(node->left, key); // Search in left subtree
        }
        return search(node->right, key); // Search in right subtree
    }

    // Helper function to find the minimum value node
    Node* minValueNode(Node* node) {
        Node* current = node;
        while (current && current->left != nullptr) {
            current = current->left; // Keep going left
        }
        return current;
    }

    // Helper function to delete a node
    Node* deleteNode(Node* node, int key) {
        if (node == nullptr) return node;

        // Traverse the tree
        if (key < node->data) {
            node->left = deleteNode(node->left, key);
        } else if (key > node->data) {
            node->right = deleteNode(node->right, key);
        } else {
            // Node found
            if (node->left == nullptr) {
                Node* temp = node->right; // Save the right child
                delete node;
                return temp; // Return right child
            } else if (node->right == nullptr) {
                Node* temp = node->left; // Save the left child
                delete node;
                return temp; // Return left child
            }

            // Node with two children: Get the inorder successor (smallest in the right subtree)
            Node* temp = minValueNode(node->right);
            node->data = temp->data; // Copy the inorder successor's data
            node->right = deleteNode(node->right, temp->data); // Delete the inorder successor
        }
        return node; // Return unchanged node pointer
    }

    // Helper function to perform in-order traversal
    void inOrder(Node* node) {
        if (node == nullptr) return;
        inOrder(node->left); // Traverse left subtree
        cout << node->data << " "; // Visit the node
        inOrder(node->right); // Traverse right subtree
    }

public:
    // Constructor
    BST() {
        root = nullptr;
    }

    // Public method to insert a new key
    void insert(int key) {
        root = insert(root, key);
    }

    // Public method to search for a key
    bool search(int key) {
        return search(root, key) != nullptr;
    }

    // Public method to delete a key
    void deleteNode(int key) {
        root = deleteNode(root, key);
    }

    // Public method for in-order traversal
    void inOrder() {
        cout << "In-order Traversal: ";
        inOrder(root);
        cout << endl;
    }
};

// Main function
int main() {
    BST bst;

    bst.insert(50);
    bst.insert(30);
    bst.insert(20);
    bst.insert(40);
    bst.insert(70);
    bst.insert(60);
    bst.insert(80);

    // Display in-order traversal
    bst.inOrder();

    // Searching for a key
    int key = 40;
    if (bst.search(key)) {
        cout << key << " is found in the BST." << endl;
    } else {
        cout << key << " is not found in the BST." << endl;
    }

    // Deleting a key
    bst.deleteNode(20);
    cout << "After deleting 20:" << endl;
    bst.inOrder();

    bst.deleteNode(30);
    cout << "After deleting 30:" << endl;
    bst.inOrder();

    bst.deleteNode(50);
    cout << "After deleting 50:" << endl;
    bst.inOrder();

    return 0;
}
