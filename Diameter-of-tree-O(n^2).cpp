#include <iostream>
#include <algorithm>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int data) : data(data), left(nullptr), right(nullptr) {
    }
};

int height(Node *tree) {
    if (!tree)
        return 0;

    return 1 + std::max(height(tree->left), height(tree->right));
}

int diameter(Node *tree) {
    if (!tree)
        return 0;

    int leftDiameter = diameter(tree->left);
    int rightDiameter = diameter(tree->right);

    int leftHeight = height(tree->left);
    int rightHeight = height(tree->right);

    return std::max(std::max(leftDiameter, rightDiameter),
        1 + leftHeight + rightHeight);
}

int main() {
/*
    Constructed binary tree is
           1
         /  \
        2    3
       /  \
      4    5
*/
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);

    int d = diameter(root);
    cout << "D : " << d << endl;
    return 0;
}