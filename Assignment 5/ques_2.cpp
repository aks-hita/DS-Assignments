#include<iostream>
using namespace std;
class Node{
    public:
    int data;
    Node* next;
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
    Node* mid(){
        Node* slow=head;
        Node* fast=head;
        while(fast!=nullptr){
            slow=slow->next;
            fast=fast->next->next;
            return slow;
        }
    }
    // Node* search(int num){
    //     Node* curr=head;
    //     while(curr!=nullptr){
    //         if(curr->data==num){
    //             return curr;}
    //     curr=curr->next;
    //     }
    //     return nullptr;
    // }
    // Node* search_prev(int num){
    //     Node* curr=head;
    //     while(curr!=nullptr&&curr->next!=nullptr){
    //         if(curr->next->data==num) 
    //             return curr;
    //         curr=curr->next;
    //     }
    //     return nullptr; 
    // }
    // void del(int val){
    //     Node* del=search(val);
    //     if(del==nullptr){cout<<"Not found."<<endl;return;}
    //     if(del==head){Node* ptr_del=head;head=head->next;delete(ptr_del);return;}
    //     Node* prev=search_prev(val);
    //     if(prev==nullptr){cout<<"Error!"<<endl;return;}
    //     prev->next=del->next;
    //     delete(del);
    // }
    // void remove(int n){
    //     Node* s=search(n);
    //     if(s==nullptr){cout<<"Value not found."<<endl;return;}
    //     int ctr=1;
    //     while(s!=nullptr){
    //         del(n);
    //         s=search(n);
    //         if(s!=nullptr)ctr++;
    //     }
    // }
};
int main(){
    LinkedList l(1);
    l.insert(2);l.insert(3);l.insert(4);l.insert(5);
    l.display();
    cout<<"The middle is "<<l.mid()->data<<endl;
    return 0;
}