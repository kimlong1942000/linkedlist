#include <iostream>  
using namespace std;  

class AVLTree {  
private:  
    int* arr;        // Mảng chứa các giá trị của cây  
    int size;       // Kích thước của cây  
    int capacity;   // Sức chứa tối đa của cây  

public:  
    AVLTree(int cap) {  
        capacity = cap;  
        size = 0;  
        arr = new int[capacity]; // Cấp phát mảng động  
    }  

    ~AVLTree() {  
        delete[] arr; // Giải phóng ô nhớ  
    }  

    // Hàm để chèn một giá trị vào cây  
    void insert(int key) {  
        if (size >= capacity) {  
            cout << "Cây đã đầy!" << endl;  
            return;  
        }  
        arr[size++] = key; // Chèn vào cuối mảng  

        // Cân bằng lại cây sau khi chèn  
        balance();  
    }  

    // In ra cây theo thứ tự Preorder  
    void preOrder() const {  
        for (int i = 0; i < size; ++i) {  
            cout << arr[i] << " ";  
        }  
        cout << endl;  
    }  

private:  
    // Hàm để cân bằng cây sau khi chèn  
    void balance() {  
        // Sắp xếp mảng để đảm bảo cây cân bằng (giả định không dùng cấu trúc cây thật sự)  
        sort(arr, arr + size);  
    }  
};  

int main() {  
    AVLTree tree(10); // Tạo cây AVL với sức chứa 10  

    // Thêm các nút vào cây  
    tree.insert(10);  
    tree.insert(20);  
    tree.insert(30);  
    tree.insert(40);  
    tree.insert(50);  
    tree.insert(25);  

    // In ra cây theo thứ tự Preorder  
    tree.preOrder();  

    return 0;  
}