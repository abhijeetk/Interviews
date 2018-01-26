#include <iostream>

using namespace std;

struct TreeNode {
    int data;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int data) : data(data), left(nullptr), right(nullptr) {
    }
};

/* create new mirror tree */
TreeNode* MirrorOfTree(TreeNode* root) {
    if (!root)
        return nullptr;


    TreeNode* left = MirrorOfTree(root->left);
    TreeNode* right = MirrorOfTree(root->right);

    TreeNode* newNode = new TreeNode(root->data);
    newNode->left = right;
    newNode->right = left;

    return newNode;
}

/* Modify existing tree */
TreeNode* MirrorOfTree_1(TreeNode* root) {
    if (root) {
        TreeNode* left = MirrorOfTree_1(root->left);
        TreeNode* right = MirrorOfTree_1(root->right);

        TreeNode* temp;
        temp = root->left;
        root->left = root->right;
        root->right = temp;
    }
    return root;
}

void inorder(TreeNode* root) {
    if (!root)
        return;

    inorder(root->left);
    cout << root->data << endl;
    inorder(root->right);
}

int main() {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);

    inorder(root);
    cout << endl;

    TreeNode * newRoot = MirrorOfTree(root);
    inorder(newRoot);
    cout << endl;

    TreeNode * newRoot1 = MirrorOfTree_1(root);
    inorder(newRoot1);
    cout << endl;

    inorder(root);
    cout << endl;

    return 0;
}