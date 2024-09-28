//C++ implementation of a binary tree that includes methods for in-order, pre-order, and post-order traversals

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

// Class for Binary Tree
class BinaryTree {
private:
    Node* root;

    // Helper function for pre-order traversal
    void preOrder(Node* node) {
        if (node == nullptr) return;
        cout << node->data << " "; // Visit the root
        preOrder(node->left);       // Traverse left subtree
        preOrder(node->right);      // Traverse right subtree
    }

    // Helper function for in-order traversal
    void inOrder(Node* node) {
        if (node == nullptr) return;
        inOrder(node->left);        // Traverse left subtree
        cout << node->data << " ";  // Visit the root
        inOrder(node->right);       // Traverse right subtree
    }

    // Helper function for post-order traversal
    void postOrder(Node* node) {
        if (node == nullptr) return;
        postOrder(node->left);      // Traverse left subtree
        postOrder(node->right);     // Traverse right subtree
        cout << node->data << " ";   // Visit the root
    }

public:
    // Constructor
    BinaryTree() {
        root = nullptr;
    }

    // Function to set the root of the tree
    void setRoot(Node* node) {
        root = node;
    }

    // Public method for pre-order traversal
    void preOrder() {
        cout << "Pre-order Traversal: ";
        preOrder(root);
        cout << endl;
    }

    // Public method for in-order traversal
    void inOrder() {
        cout << "In-order Traversal: ";
        inOrder(root);
        cout << endl;
    }

    // Public method for post-order traversal
    void postOrder() {
        cout << "Post-order Traversal: ";
        postOrder(root);
        cout << endl;
    }
};

// Main function
int main() {
    BinaryTree tree;

    // Creating the following binary tree:
    //       1
    //      / \
    //     2   3
    //    / \
    //   4   5

    Node* root = new Node(1);
    Node* node2 = new Node(2);
    Node* node3 = new Node(3);
    Node* node4 = new Node(4);
    Node* node5 = new Node(5);

    root->left = node2;
    root->right = node3;
    node2->left = node4;
    node2->right = node5;

    tree.setRoot(root);

    // Perform traversals
    tree.preOrder();
    tree.inOrder();
    tree.postOrder();

    // Clean up memory (not shown, but it's important to free allocated nodes)

    return 0;
}
