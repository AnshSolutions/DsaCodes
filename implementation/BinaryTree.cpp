#include <vector>
#include <iostream>
using namespace std;

// Function to create a binary tree from a given array
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

TreeNode* insertLevelOrder(vector<int>& arr, TreeNode* root, int i, int n) {
    if (i < n) {
        TreeNode* temp = new TreeNode(arr[i]);
        root = temp;

        root->left = insertLevelOrder(arr, root->left, 2 * i + 1, n);
        root->right = insertLevelOrder(arr, root->right, 2 * i + 2, n);
    }
    return root;
}

TreeNode* createBinaryTree(vector<int>& arr) {
    TreeNode* root = NULL;
    root = insertLevelOrder(arr, root, 0, arr.size());
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
    vector<int> arr = {1, 2, 3, 4, 5, 6, 7};
    TreeNode* root = createBinaryTree(arr);
    cout << "Inorder traversal of the constructed tree: ";
    inorder(root);
    return 0;
} 