/*
    References :
    https://www.geeksforgeeks.org/ternary-search-tree/
    https://www.cs.usfca.edu/~galles/visualization/TST.html
*/
#include <iostream>
#include <string>
using namespace std;

class TNode {

public :
    char data;
    bool isEndOfWord;
    TNode* left;
    TNode* right;
    TNode* eq; // Is responsible for choosing next index
    TNode(char data) {
        this->data = data;
        this->left = this->right = this->eq = nullptr;
        this->isEndOfWord = false;
    }

    void insert(TNode*& root, string s, int index = 0) {
        char c = s[index];
        if (!root) {
            root = new TNode(c);
        }

        if (c < root->data) {
            insert(root->left, s, index);
        }
        else if (c > root->data) {
            insert(root->right, s, index);
        }
        else {
            if (index + 1 == s.length()) {
                root->isEndOfWord = true;
            }
            else {
                // Is responsible for choosing next index
                insert(root->eq, s, index + 1);
            }

        }
    }

    void traverser(TNode* root, string& output) {
        if (root == nullptr)
            return;

        traverser(root->left, output);
        output.push_back(root->data);
        if (root->isEndOfWord) {
            cout << output << endl;
            
        }

        traverser(root->eq, output);
        output.pop_back(); // Is responsible for choosing next index so remove recently added element
        traverser(root->right, output);
    }

    bool search(TNode* root, string s, int index = 0) {
        if (root == nullptr)
            return false;

        char c = s[index];
        if (c < root->data) {
            return search(root->left, s, index);
        }
        else if (c > root->data) {
            return search(root->right, s, index);
        }
        else {
            if (index + 1 == s.length())
                return root->isEndOfWord;
            else
                return search(root->eq, s, index+1);
        }
    }
};

int main() {
    TNode* root = nullptr;
    root->insert(root, "CAT");
    root->insert(root, "CAP");
    root->insert(root, "CATS");
    root->insert(root, "CUT");
    root->insert(root, "CUP");

    string output;
    root->traverser(root, output);

    cout << root->search(root, "CUP") << endl;
    cout << root->search(root, "CUT") << endl;
    cout << root->search(root, "CATS") << endl;
    cout << root->search(root, "CAP") << endl;
    cout << root->search(root, "CAT") << endl;
    cout << root->search(root, "CAR") << endl;

    return 0;
}