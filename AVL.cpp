#include <iostream>  

class AVLNode {  
public:  
    int key;  
    AVLNode* left;  
    AVLNode* right;  
    int height;  

    AVLNode(int value) : key(value), left(nullptr), right(nullptr), height(1) {}  
};  

class AVLTree {  
private:  
    AVLNode* root;  

    int getHeight(AVLNode* node) {  
        return node ? node->height : 0;  
    }  

    int getBalance(AVLNode* node) {  
        return node ? getHeight(node->left) - getHeight(node->right) : 0;  
    }  

    AVLNode* rightRotate(AVLNode* y) {  
        AVLNode* x = y->left;  
        AVLNode* T2 = x->right;  

        // Thực hiện quay  
        x->right = y;  
        y->left = T2;  

        // Cập nhật chiều cao  
        y->height = std::max(getHeight(y->left), getHeight(y->right)) + 1;  
        x->height = std::max(getHeight(x->left), getHeight(x->right)) + 1;  

        // Trả về nút mới  
        return x;  
    }  

    AVLNode* leftRotate(AVLNode* x) {  
        AVLNode* y = x->right;  
        AVLNode* T2 = y->left;  

        // Thực hiện quay  
        y->left = x;  
        x->right = T2;  

        // Cập nhật chiều cao  
        x->height = std::max(getHeight(x->left), getHeight(x->right)) + 1;  
        y->height = std::max(getHeight(y->left), getHeight(y->right)) + 1;  

        // Trả về nút mới  
        return y;  
    }  

    AVLNode* insert(AVLNode* node, int key) {  
        // Thực hiện chèn như trong BST  
        if (!node)   
            return new AVLNode(key);  

        if (key < node->key)  
            node->left = insert(node->left, key);  
        else if (key > node->key)  
            node->right = insert(node->right, key);  
        else // Không cho phép có giá trị trùng  
            return node;  

        // Cập nhật chiều cao của nút tổ phụ  
        node->height = 1 + std::max(getHeight(node->left), getHeight(node->right));  

        // Cân bằng cây  
        int balance = getBalance(node);  

        // Nếu cây mất cân bằng, 4 trường hợp có thể xảy ra  

        // Left Left Case  
        if (balance > 1 && key < node->left->key)  
            return rightRotate(node);  

        // Right Right Case  
        if (balance < -1 && key > node->right->key)  
            return leftRotate(node);  

        // Left Right Case  
        if (balance > 1 && key > node->left->key) {  
            node->left = leftRotate(node->left);  
            return rightRotate(node);  
        }  

        // Right Left Case  
        if (balance < -1 && key < node->right->key) {  
            node->right = rightRotate(node->right);  
            return leftRotate(node);  
        }  

        // Trả về con trỏ (nút) đã được cân bằng  
        return node;  
    }  

    void inOrder(AVLNode* node) {  
        if (node) {  
            inOrder(node->left);  
            std::cout << node->key << " ";  
            inOrder(node->right);  
        }  
    }  

public:  
    AVLTree() : root(nullptr) {}  

    void insert(int key) {  
        root = insert(root, key);  
    }  

    void inOrder() {  
        inOrder(root);  
    }  
};  

int main() {  
    AVLTree tree;  

    // Chèn các giá trị vào cây  
    tree.insert(10);  
    tree.insert(20);  
    tree.insert(30);  
    tree.insert(40);  
    tree.insert(50);  
    tree.insert(25);  

    // In ra các giá trị theo thứ tự tăng dần  
    std::cout << "AVL Tree: ";  
    tree.inOrder(); // Xuất ra: 10 20 25 30 40 50  
    std::cout << std::endl;  

    return 0;  
}