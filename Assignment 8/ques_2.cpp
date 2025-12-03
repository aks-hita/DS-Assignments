#include<iostream>
using namespace std;
class Node{
    public:
    int data;
    Node* left;
    Node* right;
};
Node* createNode(int a){
    Node* newNode=new Node;
    newNode->data=a;
    newNode->left=newNode->right=nullptr;
    return newNode;
}
Node* min(Node* ptr){
    while(ptr->left!=nullptr){
        ptr=ptr->left;
    }
    return ptr;
}
Node* max(Node* ptr){
    while(ptr->right!=nullptr){
        ptr=ptr->right;
    }
    return ptr;
}
Node* search(Node* ptr, int x){
    if(ptr==nullptr ||  x==ptr->data){return ptr;}
    if(x<ptr->data){return search(ptr->left,x);}
    else {return search(ptr->right,x);}
}
Node* iterativeSearch(Node* ptr, int x){
    while(ptr!=nullptr && ptr->data!=x){
        if(x<ptr->data){
            ptr=ptr->left;}
        else {
            ptr=ptr->right;}
    }
    return ptr;
}
Node* succ(Node* ptr,int x){
    Node* succ=nullptr;
    Node* curr=ptr;
    while(curr!=nullptr && curr->data!=x){
        if(x<curr->data){
            succ=curr;
            curr=curr->left;
        }
        else{
            curr=curr->right;
        }
    }
    if (curr->data==x&& curr->right!=nullptr){
        return min(curr->right);}
    if(curr==nullptr){return nullptr;}
    return succ;
}
Node* pred(Node* ptr,int x){
    Node* prev=nullptr;
    Node* curr=ptr;
    if(curr==nullptr){return nullptr;}
    while(curr!=nullptr && curr->data!=x){
        if(x>curr->data){
            prev=curr;
            curr=curr->right;
        }
        else if(x<curr->data){
            curr=curr->left;
        }
        else{
        if(curr->left!=nullptr){
            return max(curr->left);}
            break;
    }
    }
    
    return prev;
}
int main(){
    //Level 0
    Node* root=createNode(60);
    //Level 1
    root->left=createNode(41);
    root->right=createNode(74);
    //Level 2
    root->left->left=createNode(16);
    root->left->right=createNode(53);
    root->right->left=createNode(65);
    //Level 3
    root->left->left->right=createNode(25);
    root->left->right->left=createNode(46);
    root->left->right->right=createNode(55);
    root->right->left->left=createNode(63);
    root->right->left->right=createNode(70);
    //Level 4
    root->left->right->left->left=createNode(42);
    root->right->left->left->left=createNode(62);
    root->right->left->left->right=createNode(64);
    Node* result=min(root);
    cout<<"The smallest value in the tree is "<<result->data<<endl;
    Node* result2=max(root);
    cout<<"The largest value in the tree is "<<result2->data<<endl;
    Node* result3=succ(root,70);
    cout<<"The successor of 70 is "<<result3->data<<endl;
    Node* result4=pred(root,70);
    cout<<"The predecessor of 70 is "<<result4->data<<endl;
    Node* ptr=iterativeSearch(root,55);
    cout<<"Searching for: 55"<<endl;
    if(ptr!=nullptr){cout<<"Value at the node returned: "<<ptr->data<<endl;}
    else{cout<<"Value not found."<<endl;}
    return 0;
}
