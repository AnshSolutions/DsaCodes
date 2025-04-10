#include <vector>
#include <iostream>
using namespace std;

// Function to create a binary search tree from a given array
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

TreeNode* insertBST(TreeNode* root, int val) {
    if (root == NULL) {
        return new TreeNode(val);
    }
    if (val < root->val) {
        root->left = insertBST(root->left, val);
    } else {
        root->right = insertBST(root->right, val);
    }
    return root;
}

TreeNode* createBinarySearchTree(vector<int>& arr) {
    TreeNode* root = NULL;
    for (int val : arr) {
        root = insertBST(root, val);
    }
    return root;
}

// Function to print the tree in inorder traversal
void inorder(TreeNode* root) {
    if (root != NULL) {
        inorder(root->left);
        cout << root->val << " ";
        inorder(root->right);
    }
}

// Example usage
int main() {
    vector<int> arr = {4, 2, 7, 1, 3, 6, 9};
    TreeNode* root = createBinarySearchTree(arr);
    cout << "Inorder traversal of the constructed BST: ";
    inorder(root);
    return 0;
} 