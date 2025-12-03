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
Node* search(Node* head,int num){
    Node* curr=head;
    while(curr!=nullptr){
        if(curr->data==num){
            return curr;}
    curr=curr->next;
    }
    return nullptr;
}
int searchCtr(Node* head,int num){
    int ctr=0;
    Node* curr=head;
    while(curr!=nullptr){
        ctr++;
        if(curr->data==num){
            return ctr;}
    curr=curr->next;
    }
    return -1;
}
Node* search_prev(Node* head,int num){
    Node* curr=head;
    while(curr!=nullptr&&curr->next!=nullptr){
        if(curr->next->data==num) 
            return curr;
    curr=curr->next;
    }
    return nullptr;
}
Node* tail(Node* head){
    Node* ptr=head;
    while(ptr->next!=nullptr){
        ptr=ptr->next;
    }
    return ptr;
}
int main(){
    int value;
    cout<<"Enter the first value: ";cin>>value;
    Node* head=createNode(value);
    char choice;
    do{
        cout<<"Pick an operation: "<<endl;
        cout<<"a. Insert at Beginning.\nb. Insertion at the End \nc. Insertion in the Middle."<<endl;
        cout<<"d. Deletion from the Beginning \ne. Deletion from the End \nf. Deletion of a Specific Node"<<endl;
        cout<<"g. Search for a Node \nh. Display all Node Values. \ni. End"<<endl;cin>>choice;
        switch (choice){
            case 'a':{
            int val;
            cout<<"Enter the value to insert: ";cin>>val;
            Node* ptr=createNode(val);
            ptr->next=head;
            head=ptr;
            break;
            }
            case 'b':{
            Node* n_tail=tail(head);
            int val;
            cout<<"Enter the value to insert: ";cin>>val;
            n_tail->next=createNode(val);
            break;
            }
            case 'c':{
            int val,aft_val;
            cout<<"Enter the value to insert: ";cin>>val;
            cout<<"Enter what value to insert it after: ";cin>>aft_val;
            Node* aft=search(head,aft_val);
            if(aft==nullptr){cout<<"Node not found."<<endl;break;}
            Node* ptr=createNode(val);
            ptr->next=aft->next;
            aft->next=ptr;
            break;
            }
            case 'd':{ 
            Node* ptr_del=head;
            head=head->next;
            delete(ptr_del);
            break;
            }
            case 'e':{
                if(head==nullptr){cout<<"List is empty"<<endl;break;}
                if(head->next==nullptr){delete(head);head=nullptr;break;}
                Node* ptr=head;
                Node* ptr_del=tail(head);
                while(ptr->next->next!=nullptr){
                    ptr=ptr->next;
                }
                ptr->next=nullptr;
                delete(ptr_del);
                break;
            }
            case 'f':{
                int val;
                cout<<"Enter value to Delete: ";cin>>val;
                Node* del=search(head,val);
                if(del==nullptr){cout<<"Not found."<<endl;break;}
                if(del==head){Node* ptr_del=head;head=head->next;delete(ptr_del);break;}
                Node* prev=search_prev(head,val);
                if(prev==nullptr){cout<<"Error!"<<endl;break;}
                prev->next=del->next;
                delete(del);
                break;
            }
            case 'g':{
                cout<<"Enter value to search for: ";cin>>value;
                int counter=searchCtr(head,value);
                if(counter==-1){cout<<"Not found."<<endl;}
                else{cout<<"The position of "<<value<<" is "<<counter<<endl;}
                break;
            }
            case 'h':{
                if(head==nullptr){cout<<"List is empty"<<endl;break;}
                Node* ptr=head;
                while(ptr!=nullptr){
                    cout<<ptr->data<<" ";
                    ptr=ptr->next;
                }
                cout<<endl;
                break;
            }
            case 'i':{cout<<"Thankyou!"<<endl;break;}
        }
    }
    while(choice!='i');
    Node* curr=head;
    while(curr!=nullptr){
        Node* nextNode=curr->next;
        delete curr;
        curr=nextNode;
    }
    return 0;
}