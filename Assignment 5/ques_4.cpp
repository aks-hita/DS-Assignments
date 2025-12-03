#include<iostream>
using namespace std;
class Node{
    public:
    int data;
    Node* next;
    Node* prev;
    Node(int v){data=v;next=nullptr;}
    Node(){data=-1;next=nullptr;}
};
Node* createNode(int v){
    Node* newNode=new Node(v);
    return newNode;
}
class LinkedList{public:
    LinkedList(){}
    LinkedList(int val){head=tail=createNode(val);}
    Node* head=nullptr;
    Node* tail=nullptr;
    void insert(int val){
        Node* newN=createNode(val);
        tail->next=newN;
        tail=newN;
    }
    void display(){
    if(head==nullptr){cout<<"List is empty"<<endl;}
    else{
        Node* curr=head;
            while(curr!=nullptr){
                cout<<curr->data<<" -> ";
                curr=curr->next;
            }
        cout<<"null"<<endl;}
    }
    void rev(){
        Node* curr=head; Node* prev=nullptr;Node* next;
        while(curr!=nullptr){
            next=curr->next;
            curr->next=prev;
            prev=curr;
            curr=next;
        }
        head=prev;
    }
};
int main(){
    LinkedList l(1);
    l.insert(2);l.insert(3);l.insert(4);l.insert(5);
    l.display();
    l.rev();
    l.display();
    return 0;
}