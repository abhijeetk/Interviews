#include <iostream>

using namespace std;

struct TreeNode {
    char data;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int data) : data(data), left(nullptr), right(nullptr) {
    }
};

//int findIndex(char in[], char data, int inStart, int inEnd) {
//    for (int i = inStart; i <= inEnd; i++) {
//        if (in[i] == data)
//            return i;
//    }
//}

int findIndex(char in[], char data) {
    /*
        we can use map<char, int> m; to make lookup O(1)
    */
    int i = 0;
    while (in[i] != '\0') {
        if (in[i] == data)
            break;

        i++;
    }
    return i;
}

TreeNode* buildTree(char in[], char pre[], int inStart, int inEnd) {
    static int preIndex = 0;
    if (inStart > inEnd)
        return nullptr;

    char data = pre[preIndex];
    TreeNode* newNode = new TreeNode(data);
    preIndex++;
    if (inStart == inEnd)
        return newNode;

    //int inIndex = findIndex(in, data, inStart, inEnd);
    int inIndex = findIndex(in, data);
    cout << data << " : " << inIndex << endl;
    newNode->left = buildTree(in, pre, inStart, inIndex - 1);
    newNode->right = buildTree(in, pre, inIndex + 1, inEnd);
    return newNode;
}

void inorder(TreeNode* root) {
    if (!root)
        return;

    inorder(root->left);
    cout << root->data << endl;
    inorder(root->right);
}

int main() {
    char in[] = {'D', 'B', 'E', 'A', 'F', 'C' };
    char pre[] = { 'A', 'B', 'D', 'E', 'C', 'F' };
    unsigned int size = sizeof(in) / sizeof(char);
    TreeNode* root = buildTree(in, pre, 0, size-1);
    inorder(root);
    return 0;
}