#include <iostream>
#include <map>
using namespace std;

struct TreeNode {
    int data;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int data) : data(data), left(nullptr), right(nullptr) {
    }
};

void verticalSumPreorder(TreeNode* root, int col, map<int, int>& m) {
    if (!root)
        return;

    m[col] = m[col] + root->data;
    verticalSumPreorder(root->left, col - 1, m);
    verticalSumPreorder(root->right, col + 1, m);
}

void verticalSumInorder(TreeNode* root, int col, map<int, int>& m) {
    if (!root)
        return;

    verticalSumInorder(root->left, col - 1, m);
    m[col] = m[col] + root->data;
    verticalSumInorder(root->right, col + 1, m);
}

int main() {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(7);

    map<int, int> m;
    verticalSumInorder(root, 0, m);
    for (auto i : m) {
        cout << i.first << " : " << i.second << endl;
    }
    cout << "----------" << endl;
    map<int, int> m1;
    verticalSumPreorder(root, 0, m1);
    for (auto i : m1) {
        cout << i.first << " : " << i.second << endl;
    }
}

