#include <iostream>  

class Node {  
public:  
    int data;  
    Node* next;  
    Node* prev;  

    Node(int value) {  
        data = value;  
        next = nullptr;  
        prev = nullptr;  
    }  
};  

class DoublyLinkedList {  
private:  
    Node* head;  
    Node* tail;  

public:  
    DoublyLinkedList() : head(nullptr), tail(nullptr) {}  

    // Thêm phần tử vào cuối danh sách  
    void append(int value) {  
        Node* newNode = new Node(value);  
        if (tail) {  
            tail->next = newNode; // Gán next của tail hiện tại cho node mới  
            newNode->prev = tail; // Gán prev của node mới là tail hiện tại  
        } else {  
            head = newNode; // Nếu danh sách rỗng, gán head cho node mới  
        }  
        tail = newNode; // Cập nhật tail cho node mới  
    }   

    // Duyệt danh sách và in ra các phần tử  
    void display() {  
        Node* currentNode = head;  
        while (currentNode != nullptr) {  
            std::cout << currentNode->data << " <-> ";  
            currentNode = currentNode->next;  
        }  
        std::cout << "nullptr" << std::endl;  
    }  

    // Tìm kiếm một phần tử trong danh sách  
    bool search(int value) {  
        Node* currentNode = head;  
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