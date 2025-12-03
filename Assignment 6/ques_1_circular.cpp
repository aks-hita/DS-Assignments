#include <iostream>
using namespace std;
class Node {
public:
    int data;
    Node* next;

    Node(int val) {
        data = val;
        next = nullptr;
    }
};
class CircularLinkedList {
    Node* head;
public:
    CircularLinkedList() : head(nullptr) {}
    void insertAtBeginning(int val) {
        Node* newNode = new Node(val);
        if (head==nullptr) {
            head = newNode;
            head->next = head;
            return;
        }
        Node* temp = head;
        while (temp->next != head)
            temp = temp->next;
        temp->next = newNode;
        newNode->next = head;
        head = newNode;
    }
    void insertAtEnd(int val) {
        Node* newNode = new Node(val);
        if (head==nullptr) {
            head = newNode;
            head->next = head;
            return;
        }
        Node* temp = head;
        while (temp->next != head)
            temp = temp->next;
        temp->next = newNode;
        newNode->next = head;
    }

    void insertAfter(int key, int val) {
        if (head==nullptr) return;
        Node* temp = head;
        do {
            if (temp->data == key) {
                Node* newNode = new Node(val);
                newNode->next = temp->next;
                temp->next = newNode;
                return;
            }
            temp = temp->next;
        } while (temp != head);
        cout << "Node not found!\n";
    }
    void deleteNode(int key) {
        if (head==nullptr ) return;
        Node* curr = head;
        Node* prev = nullptr;
        // Find the node
        do {
            if (curr->data == key)
                break;
            prev = curr;
            curr = curr->next;

        } while (curr != head);
        if (curr->data != key) {
            cout << "Node not found\n";
            return;
        }
        if (curr == head && curr->next == head) {
            head = nullptr;
            delete curr;
            return;
        }
        if (curr == head) {
            Node* temp = head;
            while (temp->next != head)
                temp = temp->next;
            head = head->next;
            temp->next = head;
            delete curr;
        }
        else {
            prev->next = curr->next;
            delete curr;
        }
    }
    void search(int key) {
        if (!head) return;
        Node* temp = head;
        int pos = 1;
        do {
            if (temp->data == key) {
                cout << "Node found at position " << pos << "\n";
                return;
            }
            temp = temp->next;
            pos++;
        } while (temp != head);
        cout << "Node not found!\n";
    }
    void display() {
        if (!head) {
            cout << "List is empty!\n";
            return;
        }
        Node* temp = head;
        cout << "List: ";
        do {
            cout << temp->data << " ";
            temp = temp->next;
        } while (temp != head);
        cout << "\n";
    }
};
int main() {
    CircularLinkedList list;
    int choice, val, key;
    do {
        cout << "\n--- Circular Singly Linked List Menu ---\n";
        cout << "1. Insert at Beginning\n";
        cout << "2. Insert at End\n";
        cout << "3. Insert After a Node\n";
        cout << "4. Delete a Node\n";
        cout << "5. Search a Node\n";
        cout << "6. Display List\n";
        cout << "0. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;
        switch (choice) {
        case 1:
            cout << "Enter value: ";
            cin >> val;
            list.insertAtBeginning(val);
            break;
        case 2:
            cout << "Enter value: ";
            cin >> val;
            list.insertAtEnd(val);
            break;
        case 3:
            cout << "Enter key and value: ";
            cin >> key >> val;
            list.insertAfter(key, val);
            break;
        case 4:
            cout << "Enter key to delete: ";
            cin >> key;
            list.deleteNode(key);
            break;
        case 5:
            cout << "Enter key to search: ";
            cin >> key;
            list.search(key);
            break;
        case 6:
            list.display();
            break;
        case 0:
            cout << "Exiting...\n";
            break;
        default:
            cout << "Invalid choice!\n";
        }
    } while (choice != 0);
    return 0;
}