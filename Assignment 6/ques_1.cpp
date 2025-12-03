#include <iostream>
using namespace std;
class DNode {
public:
    int data;
    DNode* prev;
    DNode* next;
    DNode(int val) {
        data = val;
        prev = next = nullptr;
    }
};
class DoublyLinkedList {
    DNode* head;
public:
    DoublyLinkedList() : head(nullptr) {}
    void insertAtBeginning(int val) {
        DNode* newNode = new DNode(val);
        if (head==nullptr) {
            head = newNode;
            return;
        }
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
    }
    void insertAtEnd(int val) {
        DNode* newNode = new DNode(val);
        if (head==nullptr) {
            head = newNode;
            return;
        }
        DNode* temp = head;
        while (temp->next!=nullptr)
            temp = temp->next;  
        temp->next = newNode;
        newNode->prev = temp;
    }
    void insertAfter(int key, int val) {
        DNode* temp = head;
        while (temp && temp->data != key)
            temp = temp->next;
        if (temp==nullptr) {
            cout << "Node not found\n";
            return;
        }
        DNode* newNode = new DNode(val);
        newNode->next = temp->next;
        newNode->prev = temp;
        if (temp->next!=nullptr)
            temp->next->prev = newNode;
        temp->next = newNode;
    }
    void insertBefore(int key, int val) {
        if (!head) return;
        if (head->data == key) {
            insertAtBeginning(val);
            return;
        }
        DNode* temp = head;
        while (temp && temp->data != key)
            temp = temp->next;
        if (temp==nullptr) {
            cout << "Node not found!\n";
            return;
        }
        DNode* newNode = new DNode(val);
        newNode->next = temp;
        newNode->prev = temp->prev;
        temp->prev->next = newNode;
        temp->prev = newNode;
    }
    void deleteNode(int key) {
        if (!head) return;
        DNode* temp = head;
        if (head->data == key) {
            head = head->next;
            if (head)
                head->prev = nullptr;
            delete temp;
            return;
        }
        while (temp && temp->data != key)
            temp = temp->next;

        if (!temp) {
            cout << "Node not found!\n";
            return;
        }
        if (temp->next)
            temp->next->prev = temp->prev;
        if (temp->prev)
            temp->prev->next = temp->next;

        delete temp;
    }
    void search(int key) {
        DNode* temp = head;
        int pos = 1;
        while (temp) {
            if (temp->data == key) {
                cout << "Node found at position " << pos << "\n";
                return;
            }
            temp = temp->next;
            pos++;
        }
        cout << "Node not found!\n";
    }
    void display() {
        DNode* temp = head;
        cout << "List: ";
        while (temp) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << "\n";
    }
};
int main() {
    DoublyLinkedList dll;
    int choice, val, key;
    do {
        cout << "\n====== Doubly Linked List Menu ======\n";
        cout << "1. Insert at Beginning\n";
        cout << "2. Insert at End\n";
        cout << "3. Insert After a Node\n";
        cout << "4. Insert Before a Node\n";
        cout << "5. Delete a Node\n";
        cout << "6. Search for a Node\n";
        cout << "7. Display List\n";
        cout << "8. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice) {
            case 1:
                cout << "Enter value to insert at beginning: ";
                cin >> val;
                dll.insertAtBeginning(val);
                break;

            case 2:
                cout << "Enter value to insert at end: ";
                cin >> val;
                dll.insertAtEnd(val);
                break;

            case 3:
                cout << "Enter key after which to insert: ";
                cin >> key;
                cout << "Enter value to insert: ";
                cin >> val;
                dll.insertAfter(key, val);
                break;

            case 4:
                cout << "Enter key before which to insert: ";
                cin >> key;
                cout << "Enter value to insert: ";
                cin >> val;
                dll.insertBefore(key, val);
                break;

            case 5:
                cout << "Enter value to delete: ";
                cin >> key;
                dll.deleteNode(key);
                break;

            case 6:
                cout << "Enter value to search: ";
                cin >> key;
                dll.search(key);
                break;

            case 7:
                dll.display();
                break;

            case 8:
                cout << "Exiting...\n";
                break;

            default:
                cout << "Invalid choice! Please try again.\n";
        }
    } while (choice != 8);
    return 0;
}