#include <iostream>
#include <vector>
#include <functional>
#include <algorithm>

using namespace std;

struct TreeNode {
    int data;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int data) : data(data), left(nullptr), right(nullptr) {
        cout << "Node" << data << "constructed" << endl;
    }
};

void deepestNode(TreeNode* root, int depth, int& maxDepth, TreeNode*& res) {
    if (!root)
        return;

    if (root->left == nullptr && root->right == nullptr) {
        if (depth > maxDepth) {
            maxDepth = depth;
            res = root;
        }
    }
    else {
        deepestNode(root->left, depth + 1, maxDepth, res);

        deepestNode(root->right, depth + 1, maxDepth, res);
    }
}


int main() {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->left->right->left = new TreeNode(6);
    root->left->right->right = new TreeNode(7);
    TreeNode* res = nullptr;
    int maxDepth = 0;
    deepestNode(root, 0, maxDepth, res);
    cout << res->data << endl;


    TreeNode* root1 = new TreeNode(1);
    root1->left = new TreeNode(2);
    root1->left->left = new TreeNode(3);
    root1->left->left->left = new TreeNode(6);
    root1->left->left->right = new TreeNode(5);
    res = nullptr;
    maxDepth = 0;
    deepestNode(root1, 0, maxDepth, res);
    cout << res->data << endl;

    TreeNode* root2 = new TreeNode(1);
    root2->right = new TreeNode(2);
    root2->right->right = new TreeNode(3);
    res = nullptr;
    maxDepth = 0;
    deepestNode(root2, 0, maxDepth, res);
    cout << res->data << endl;

    return 0;
}