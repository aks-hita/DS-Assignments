#include <iostream>
using namespace std;
//Doubly Linked List
class Node {
public:
    int data;
    Node* prev;
    Node* next;
    Node(int val) {
        data = val;
        prev = next = nullptr;
    }
};
class DoublyLinkedList {
public:
    Node* head;
    Node* tail;
    DoublyLinkedList() {
        head=tail=nullptr;
    }
    void insertAtEnd(int val) {
        Node* newNode = new Node(val);
        if (!head) {
            head = tail = newNode;
            return;
        }
        tail->next = newNode;
        newNode->prev = tail;
        tail = newNode;
    }
    int getSize() {
        int count = 0;
        Node* temp = head;
        while (temp) {
            count++;
            temp = temp->next;
        }
        return count;
    }
    void display() {
        Node* temp = head;
        cout << "DLL: ";
        while (temp) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};
//Circular Singly Linked List
class CircularSinglyLinkedList {
public:
    Node* tail;
    CircularSinglyLinkedList() {
        tail = nullptr;
    }
    void insert(int val) {
        Node* newNode = new Node(val);
        if (!tail) {
            tail = newNode;
            tail->next = tail;
            return;
        }
        newNode->next = tail->next;
        tail->next = newNode;
        tail = newNode;
    }

    int getSize() {
        if (!tail) return 0;
        int count = 0;
        Node* temp = tail->next;
        do {
            count++;
            temp=temp->next;
        }
        while (temp != tail->next);
        return count;
    }
};
int main(){
    // Test DLL
    DoublyLinkedList dll;
    dll.insertAtEnd(10);
    dll.insertAtEnd(20);
    dll.insertAtEnd(30);
    dll.display();
    cout << "Doubly Linked List size: " << dll.getSize() << endl;

    // Test Circular SLL
    CircularSinglyLinkedList cll;
    cll.insert(5);
    cll.insert(15);
    cll.insert(25);
    cout << "Circular Singular Linked List size: " << cll.getSize() << endl;
    return 0;
}