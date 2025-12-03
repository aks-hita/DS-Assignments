#include <iostream>
using namespace std;
class Treenode {
public:
    int data;
    Treenode* left;
    Treenode* right;
    Treenode(int d) {
        data = d;
        left = right = nullptr;
    }
};
Treenode* insert(Treenode* root, int val) {
    Treenode* newNode = new Treenode(val);
    if (root == nullptr)
        return newNode;   
    Treenode* curr = root;
    Treenode* parent = nullptr;
    while (curr != nullptr) {
        parent = curr;
        if (val == curr->data) {
            cout << "Duplicate value " << val << endl;
            delete newNode;  
            return root;     
        }
        else if (val < curr->data)
            curr = curr->left;
        else
            curr = curr->right;
    }
    // Attach new node to the correct side of parent
    if (val < parent->data)
        parent->left = newNode;
    else
        parent->right = newNode;
    return root;
}
Treenode* findMin(Treenode* root) {
    while (root && root->left)
        root = root->left;
    return root;
}
Treenode* deleteNode(Treenode* root, int key) {
    if (root == nullptr)
        return root;
    if (key < root->data)
        root->left = deleteNode(root->left, key);
    else if (key > root->data)
        root->right = deleteNode(root->right, key);
    else {
        //no child
        if (root->left == nullptr && root->right == nullptr) {
            delete root;
            return nullptr;
        }
        //1 child 
        else if (root->left == nullptr) {
            Treenode* temp = root->right;
            delete root;
            return temp;
        }
        else if (root->right == nullptr) {
            Treenode* temp = root->left;
            delete root;
            return temp;
        }
        //2 child
        else {
            Treenode* succ = findMin(root->right);
            root->data = succ->data;
            root->right = deleteNode(root->right, succ->data);
        }
    }
    return root;
}
int maxDepth(Treenode* root) {
    if (root == nullptr)
        return 0;
    int leftDepth = maxDepth(root->left);
    int rightDepth = maxDepth(root->right);

    return max(leftDepth, rightDepth) + 1;
}
int minDepth(Treenode* root) {
    if (root == nullptr)
        return 0;
    if (root->left == nullptr)
        return minDepth(root->right) + 1;
    if (root->right == nullptr)
        return minDepth(root->left) + 1;
    return min(minDepth(root->left), minDepth(root->right)) + 1;
}
int main(){
    return 0;
}