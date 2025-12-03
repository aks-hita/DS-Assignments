#include<iostream>
using namespace std;
class Node{ public:
    char data;
    Node* next;
    Node* prev;
    Node(){next=prev=nullptr;}
    Node(char val){data=val;next=prev=nullptr;}
};
class List{ public:
    Node* head;
    Node* tail;
    List(){}
    List(char val){head=tail=new Node(val);head->next=tail;tail->prev=head;}
    void insert(char val){
        Node* temp=tail;
        tail=new Node(val);
        tail->prev=temp;
        temp->next=tail;
    }
    bool isPalindrome(){
        Node* left=head;
        Node* right=tail;
        while(left!=nullptr&& right != nullptr && left != right && left->prev != right){
        if(left->data!=right->data)
            return false;
        left=left->next;
        right=right->prev;
        }
        return true;
    }
    void display(){
        Node* curr=head;
        while(curr!=nullptr){
            cout<<curr->data<<" ";
            curr=curr->next;
        }
        cout<<endl;
    }
};
int main(){
    List l('L');l.insert('E');l.insert('V');l.insert('E');l.insert('L');
    l.display();
    if(l.isPalindrome())cout<<"It is a plaindrome."<<endl;
    else cout<<"It is not a palindrome."<<endl;
}