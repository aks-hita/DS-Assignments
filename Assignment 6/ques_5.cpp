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
bool isCircular(Node* head) {
    if (head == nullptr)
        return false;
    Node* temp = head->next;
    while (temp != nullptr && temp != head)
        temp = temp->next;
    return (temp == head);
}
int main() {
    Node* head = new Node(10);
    Node* second = new Node(20);
    Node* third = new Node(30);
    Node* fourth = new Node(40);
    head->next = second;
    second->next = third;
    third->next = fourth;
    fourth->next = nullptr;  
    if (isCircular(head))
        cout << "The list is circular.\n";
    else
        cout << "The list is NOT circular.\n";
    fourth->next = head;  
    if (isCircular(head))
        cout << "After linking last to head: The list is circular.\n";
    else
        cout << "After linking last to head:\nThe list is NOT circular.\n";
    return 0;
}