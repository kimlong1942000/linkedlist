#include <iostream>  

class Node 
{  
private:  
    int data;  
    Node* next;  
    Node* tail;

    Node(int value) {  
        data = value;  
        next = nullptr;  
    }  
};  

class LinkedList 
{  
    private:  
    Node* head;  
    Node* tail;  

public:  
    LinkedList() : head(nullptr), tail(nullptr) {}  
    // Thêm nút vào cuối danh sách  
    void append(int data) {  
        Node* newNode = new Node(data);  
        if (tail) {  
            tail->next = newNode; // Nếu có tail, gán next của nó cho node mới  
        } else {  
            head = newNode; // Nếu là phần tử đầu tiên, gán head cho node mới  
        }  
        tail = newNode; // Cập nhật tail cho node mới  
    }  

    // Duyệt danh sách và in ra các phần tử  
    void display() {  
        Node* currentNode = head;  
        while (currentNode != nullptr) {  
            std::cout << currentNode->data << " -> ";  
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
    LinkedList linkedList;  
    linkedList.append(1);  
    linkedList.append(2);  
    linkedList.append(3);  
    linkedList.display(); // Xuất: 1 -> 2 -> 3 -> nullptr  

    // Tìm kiếm giá trị trong danh sách  
    int valueToSearch = 2;  
    if (linkedList.search(valueToSearch)) {  
        std::cout << "Tìm thấy giá trị " << valueToSearch << " trong danh sách." << std::endl;  
    } else {  
        std::cout << "Không tìm thấy giá trị " << valueToSearch << " trong danh sách." << std::endl;  
    }  

    valueToSearch = 4;  
    if (linkedList.search(valueToSearch)) {  
        std::cout << "Tìm thấy giá trị " << valueToSearch << " trong danh sách." << std::endl;  
    } else {  
        std::cout << "Không tìm thấy giá trị " << valueToSearch << " trong danh sách." << std::endl;  
    }  

    return 0;  
}