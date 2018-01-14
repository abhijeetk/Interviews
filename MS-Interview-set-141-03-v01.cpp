/*
    https://www.geeksforgeeks.org/microsoft-interview-experience-set-141-off-campus-online-coding-test-idc/
    (*) Structure of the node of tree is as follows:
    struct TreeNode
    {
        int data;
        struct TreeNode* left;
        struct TreeNode* right;
    };

    (*) Don't allocate extra memory for Linked List, just let the right pointer of a leaf
    node point to the next leaf node to form a linked list.

    Example:
         10
       /    \
     20     100
    /  \       / \
   30   40    9   66

    Output: 30 -> 40 -> 9 -> 66
*/
#include <iostream>
using namespace std;

struct TreeNode
{
    int data;
    struct TreeNode* left;
    struct TreeNode* right;

    TreeNode(int data) {
        this->data = data;
        this->left = nullptr;
        this->right = nullptr;
    }
};

TreeNode* createLinkedList(TreeNode* root) {
    if (!root)
        return nullptr;

    if (root->left == nullptr && root->right == nullptr)
        return root;

    TreeNode* head = createLinkedList(root->left);
    head->right = createLinkedList(root->right);
    return head->right ? head->right : head;
}

int main() {
    TreeNode* root = new TreeNode(10);
    root->left = new TreeNode(20);
    root->right = new TreeNode(100);
    root->left->left = new TreeNode(30);
    root->left->right = new TreeNode(40);
    root->right->left = new TreeNode(9);
    root->right->right = new TreeNode(66);

    TreeNode* list = createLinkedList(root);

    return 0;
}