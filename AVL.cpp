#include <iostream>  
using namespace std;  

// Structure for a node in the AVL tree  
class AVLNode {  
public:  
    int key; // Key of the node  
    int height; // Height of the node  
    AVLNode* left; // Pointer to the left child  
    AVLNode* right; // Pointer to the right child  

    AVLNode(int k) : key(k), height(1), left(nullptr), right(nullptr) {}  
};  

// Structure for the AVL tree  
class AVLTree {  
private:  
    AVLNode* root; // Root of the AVL tree  

    // Function to get the height of a node  
    int height(AVLNode* N) {  
        return (N == nullptr) ? 0 : N->height;  
    }  

    // Function to get the balance factor of a node  
    int getBalance(AVLNode* N) {  
        if (N == nullptr) return 0;  
        return height(N->left) - height(N->right);  
    }  

    // Function to perform right rotation  
    AVLNode* rightRotate(AVLNode* y) {  
        AVLNode* x = y->left;  
        AVLNode* T2 = x->right;  

        // Perform rotation  
        x->right = y;  
        y->left = T2;  

        // Update heights  
        y->height = max(height(y->left), height(y->right)) + 1;  
        x->height = max(height(x->left), height(x->right)) + 1;  

        // Return the new root after rotation  
        return x;  
    }  

    // Function to perform left rotation  
    AVLNode* leftRotate(AVLNode* x) {  
        AVLNode* y = x->right;  
        AVLNode* T2 = y->left;  

        // Perform rotation  
        y->left = x;  
        x->right = T2;  

        // Update heights  
        x->height = max(height(x->left), height(x->right)) + 1;  
        y->height = max(height(y->left), height(y->right)) + 1;  

        // Return the new root after rotation  
        return y;  
    }  

    // Function to insert a node into the AVL tree, allowing duplicate values  
    AVLNode* insert(AVLNode* node, int key) {  
        // Step 1: Insert the node like in a binary tree  
        if (node == nullptr) {  
            return new AVLNode(key); // Allocate a new node  
        }  

        if (key < node->key) {  
            node->left = insert(node->left, key);  
        } else { // Insert to the right if key >= node->key (allow duplicates)  
            node->right = insert(node->right, key);  
        }  

        // Step 2: Update the height of the ancestor node  
        node->height = 1 + max(height(node->left), height(node->right));  

        // Step 3: Get the balance factor of the ancestor node  
        int balance = getBalance(node);  

        // If the balance factor is > 1, the left subtree is heavy  
        // Left-Left case  
        if (balance > 1 && key < node->left->key) {  
            return rightRotate(node);  
        }  

        // Left-Right case  
        if (balance > 1 && key > node->left->key) {  
            node->left = leftRotate(node->left);  
            return rightRotate(node);  
        }  

        // If the balance factor is < -1, the right subtree is heavy  
        // Right-Right case  
        if (balance < -1 && key > node->right->key) {  
            return leftRotate(node);  
        }  

        // Right-Left case  
        if (balance < -1 && key < node->right->key) {  
            node->right = rightRotate(node->right);  
            return leftRotate(node);  
        }  

        // Return the possibly updated node pointer  
        return node;  
    }  

    // Function to traverse the tree in inorder  
    void inOrder(AVLNode* root) {  
        if (root != nullptr) {  
            inOrder(root->left);  
            cout << root->key << " ";  
            inOrder(root->right);  
        }  
    }  

    // Function to delete the AVL tree  
    void destroyTree(AVLNode* node) {  
        if (node != nullptr) {  
            destroyTree(node->left);  
            destroyTree(node->right);  
            delete node; // Delete the current node  
        }  
    }  

public:  
    // Constructor for the AVL tree  
    AVLTree() : root(nullptr) {}  

    // Public function to insert a node into the AVL tree  
    void insert(int key) {  
        root = insert(root, key);  
    }  

    // Public function to traverse the tree in inorder  
    void inOrder() {  
        cout << "Inorder traversal of AVL tree: ";  
        inOrder(root);  
        cout << endl;  
    }  

    // Destructor for the AVL tree  
    ~AVLTree() {  
        destroyTree(root); // Call the helper function to delete all nodes  
        root = nullptr; // Set root to nullptr after deletion  
    }  
};  

int main() {  
    AVLTree tree;  

    // Insert 
    tree.insert(10);  
    tree.insert(20);  
    tree.insert(20);  
    tree.insert(19);  
    tree.insert(30);  
    tree.insert(40);  
    tree.insert(19);  
    tree.insert(1);  
    tree.insert(50);  
    tree.insert(25);  
    tree.insert(1);  

    std::cout << "AVL Tree: ";  
    tree.inOrder(); 
    std::cout << std::endl;  

    tree.~AVLTree();

    return 0;  
}