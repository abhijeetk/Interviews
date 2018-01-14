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

void createLinkedList(TreeNode* root, TreeNode** prevLeaf, TreeNode** head) {
    if (!root)
        return;

    if (root->left == nullptr && root->right == nullptr) {
        if (!*head)
            *head = root;

        if (*prevLeaf) {
            (*prevLeaf)->right = root;
            //For doubly linked list
            //root->left = *prevLeaf;
        }
        *prevLeaf = root;
        return;
    }

    createLinkedList(root->left, prevLeaf, head);
    createLinkedList(root->right, prevLeaf, head);
}

void test(TreeNode* head)
{
    while (head) {
        cout << head->data << "\t";
        head = head->right;
    }
    cout << endl;
}


int main() {
    TreeNode* root = new TreeNode(10);
    root->left = new TreeNode(20);
    root->right = new TreeNode(100);
    root->left->left = new TreeNode(30);
    root->left->right = new TreeNode(40);
    root->right->left = new TreeNode(9);
    root->right->right = new TreeNode(66);

    TreeNode* head, *prevLeaf;
    head = prevLeaf = nullptr;
    createLinkedList(root, &prevLeaf, &head);

    test(head);

    return 0;
}