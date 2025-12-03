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
void preorderTraverse(Node* ptr){
    if(ptr==nullptr){return;}
    cout<<ptr->data<<" ";
    preorderTraverse(ptr->left);
    preorderTraverse(ptr->right);
}
void inorderTraverse(Node* ptr){
    if(ptr==nullptr){return;}
    inorderTraverse(ptr->left);
    cout<<ptr->data<<" ";
    inorderTraverse(ptr->right);
}
void postorderTraverse(Node* ptr){
    if(ptr==nullptr){return;}
    postorderTraverse(ptr->left);
    postorderTraverse(ptr->right);
    cout<<ptr->data<<" ";
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

    cout<<"Pre-Order Traversal: "<<endl;
    preorderTraverse(root);
    cout<<endl<<"In-Order Traversal: "<<endl;
    inorderTraverse(root);
    cout<<endl<<"Post-Order Traversal: "<<endl;
    postorderTraverse(root);
    cout<<"\n";
    return 0;
}
