#include <iostream>  

class DoubleNode {  
public:  
    int data;  
    DoubleNode* next;  
    DoubleNode* prev;  

    DoubleNode(int value) {  
        data = value;  
        next = nullptr;  
        prev = nullptr;  
    }  
};  

class DoublyLinkedList {  
public:  
    DoubleNode* head;  

    DoublyLinkedList() {  
        head = nullptr;  
    }  

    // Thêm nút vào cuối danh sách  
    void append(int data) {  
        DoubleNode* newNode = new DoubleNode(data);  
        if (!head) {  
            head = newNode;  
            return;  
        }  
        DoubleNode* lastNode = head;  
        while (lastNode->next != nullptr) {  
            lastNode = lastNode->next;  
        }  
        lastNode->next = newNode;  
        newNode->prev = lastNode;  
    }  

    // Duyệt danh sách và in ra các phần tử  
    void display() {  
        DoubleNode* currentNode = head;  
        while (currentNode != nullptr) {  
            std::cout << currentNode->data << " <-> ";  
            currentNode = currentNode->next;  
        }  
        std::cout << "nullptr" << std::endl;  
    }  

    // Tìm kiếm một phần tử trong danh sách  
    bool search(int value) {  
        DoubleNode* currentNode = head;  
        while (currentNode != nullptr) {  
            if (currentNode->data == value) {  
                return true; // Tìm thấy  
            }  
            currentNode = currentNode->next;  
        }  
        return false; // Không tìm thấy  
    }  
};  

int main() {  
    DoublyLinkedList doublyLinkedList;  
    doublyLinkedList.append(1);  
    doublyLinkedList.append(2);  
    doublyLinkedList.append(3);  
    doublyLinkedList.display(); // Xuất: 1 <-> 2 <-> 3 <-> nullptr  

    // Tìm kiếm giá trị trong danh sách  
    int valueToSearch = 2;  
    if (doublyLinkedList.search(valueToSearch)) {  
        std::cout << "Tìm thấy giá trị " << valueToSearch << " trong danh sách." << std::endl;  
    } else {  
        std::cout << "Không tìm thấy giá trị " << valueToSearch << " trong danh sách." << std::endl;  
    }  

    valueToSearch = 4;  
    if (doublyLinkedList.search(valueToSearch)) {  
        std::cout << "Tìm thấy giá trị " << valueToSearch << " trong danh sách." << std::endl;  
    } else {  
        std::cout << "Không tìm thấy giá trị " << valueToSearch << " trong danh sách." << std::endl;  
    }  

    return 0;  
}