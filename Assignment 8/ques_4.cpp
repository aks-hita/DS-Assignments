#include <iostream>
#include<climits>
using namespace std;
class TreeNode {
public:
    int data;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int d) {
        data = d;
        left = right = nullptr;
    }
};
bool isBST(TreeNode* root, long long minVal, long long maxVal) {
    if (root == NULL)
        return true;
    // node must be within allowed range
    if (root->data <= minVal || root->data >= maxVal)
        return false;
    //  for left and right subtrees
    return isBST(root->left, minVal, root->data) &&
        isBST(root->right, root->data, maxVal);
}
int main() {
    /*
        Example Tree:
                4
               / \
              2   5
             / \
            1   3
    */

    TreeNode* root = new TreeNode(4);
    root->left = new TreeNode(2);
    root->right = new TreeNode(5);
    root->left->left = new TreeNode(1);
    root->left->right = new TreeNode(3);
    if (isBST(root,INT_MIN,INT_MAX))
        cout << "The tree is a BST.\n";
    else
        cout << "The tree is NOT a BST.\n";
    return 0;
}