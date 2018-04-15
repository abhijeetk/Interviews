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

int diameterOpt(Node *tree, int& height) {
    if (!tree)
        return 0;

    int leftHeight = 0;
    int rightHeight = 0;

    int leftDiameter = diameterOpt(tree->left, leftHeight);
    int rightDiameter = diameterOpt(tree->right, rightHeight);


    height = 1 + std::max(leftHeight, rightHeight);

    return std::max(std::max(leftDiameter, rightDiameter),
        1 + leftHeight + rightHeight);
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

    int h = 0;
    d = diameterOpt(root, h);
    cout << "D : " << d << endl;

    return 0;
}