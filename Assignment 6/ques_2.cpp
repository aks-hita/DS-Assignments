#include<iostream>
using namespace std;
class DNode{public:
    int data;
    DNode* next;
    DNode* prev;
    DNode(){next=nullptr,prev=nullptr;}
    DNode(int val){data=val,next=prev=nullptr;}
};
class circDLinked{public:
    DNode* head;
    DNode* tail;
    circDLinked():head(nullptr),tail(nullptr){}
    circDLinked(int val){head=tail=new DNode(val);head->next=tail;tail->prev=head;}
    void insert(int val){
        DNode* temp=tail;
        tail= new DNode(val);
        temp->next=tail;
        tail->next=head;
        head->prev=tail;
    }
    void displayWHead(){
        DNode* curr=head;
        if(head==nullptr){cout<<"List is empty."<<endl;return;}
    do{
        cout<<curr->data<<" -> ";
        curr=curr->next;
    }
        while(curr!=head);
        cout<<head->data<<endl;
    }
};
int main(){
    circDLinked L(20);
    L.insert(100);
    L.insert(40);L.insert(80);L.insert(60);
    L.displayWHead();
}