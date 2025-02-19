#include <iostream>  
using namespace std;  

struct Node {  
    int value;  
    Node* left;  
    Node* right;  

    Node(int key) {  
        value = key;  
        left = right = nullptr;  
    }  
};  

class BinaryTree {  
private:
        Node* root;  

public:  

    BinaryTree() {  
        root = nullptr;  
    }  

    void insert(int key) {  
        if (root == nullptr) {  
            root = new Node(key);  
        } else {  
            insertRecursively(root, key);  
        }  
    }  

    void insertRecursively(Node* node, int key) {  
        if (key < node->value) {  
            if (node->left == nullptr) {  
                node->left = new Node(key);  
            } else {  
                insertRecursively(node->left, key);  
            }  
        } else {  
            if (node->right == nullptr) {  
                node->right = new Node(key);  
            } else {  
                insertRecursively(node->right, key);  
            }  
        }  
    }  

    Node* search(int key) {  
        return searchRecursively(root, key);  
    }  

    Node* searchRecursively(Node* node, int key) {  
        if (node == nullptr || node->value == key) {  
            return node;  
        }  
        if (key < node->value) {  
            return searchRecursively(node->left, key);  
        }  
        return searchRecursively(node->right, key);  
    }  

    void inorder() {  
        inorderTraversal(root);  
        cout << endl;  
    }  

    void inorderTraversal(Node* node) {  
        if (node) {  
            inorderTraversal(node->left);  
            cout << node->value << " ";  
            inorderTraversal(node->right);  
        }  
    }  

    void preorder() {  
        preorderTraversal(root);  
        cout << endl;  
    }  

    void preorderTraversal(Node* node) {  
        if (node) {  
            cout << node->value << " ";  
            preorderTraversal(node->left);  
            preorderTraversal(node->right);  
        }  
    }  

    void postorder() {  
        postorderTraversal(root);  
        cout << endl;  
    }  

    void postorderTraversal(Node* node) {  
        if (node) {  
            postorderTraversal(node->left);  
            postorderTraversal(node->right);  
            cout << node->value << " ";  
        }  
    }  

    void deleteNode(int key) {  
        root = deleteRecursively(root, key);  
    }  

    Node* deleteRecursively(Node* node, int key) {  
        if (node == nullptr) {  
            return node;  
        }  

        if (key < node->value) {  
            node->left = deleteRecursively(node->left, key);  
        } else if (key > node->value) {  
            node->right = deleteRecursively(node->right, key);  
        } else {  
            // Nút với một hoặc không có con  
            if (node->left == nullptr) {  
                Node* temp = node->right;  
                delete node;  
                return temp;  
            } else if (node->right == nullptr) {  
                Node* temp = node->left;  
                delete node;  
                return temp;  
            }  

            // Nút với hai con: Lấy giá trị nhỏ nhất trong cây con bên phải  
            Node* temp = minValueNode(node->right);  
            node->value = temp->value;  
            node->right = deleteRecursively(node->right, temp->value);  
        }  
        return node;  
    }  

    Node* minValueNode(Node* node) {  
        Node* current = node;  
        while (current && current->left != nullptr) {  
            current = current->left;  
        }  
        return current;  
    }  
};  

int main() {  
    BinaryTree tree;  
    tree.insert(50);  
    tree.insert(30);  
    tree.insert(20);  
    tree.insert(40);  
    tree.insert(70);  
    tree.insert(60);  
    tree.insert(80);  

    cout << "Duyệt cây theo thứ tự (In-order): ";  
    tree.inorder();  

    cout << "Duyệt cây theo thứ tự trước (Pre-order): ";  
    tree.preorder();  

    cout << "Duyệt cây theo thứ tự sau (Post-order): ";  
    tree.postorder();  

    int searchKey = 40;  
    Node* foundNode = tree.search(searchKey);  
    cout << "Tìm kiếm " << searchKey << ": "   
         << (foundNode ? to_string(foundNode->value) : "Không tìm thấy") << endl;  

    cout << "Xoá 20" << endl;  
    tree.deleteNode(20);  
    cout << "Duyệt cây sau khi xoá 20: ";  
    tree.inorder();  

    return 0;  
}