/*
-----------------------------------------------
        Convert TREE into GRAPH
-----------------------------------------------
LeetCode 742. Closest Leaf in a Binary Tree
Problem:
Given a binary tree where every node has a unique value, and a target key k,
find the value of the closest leaf node to target k in the tree.

Here, closest to a leaf means the least number of edges travelled on the binary tree
to reach any leaf of the tree. Also, a node is called a leaf if it has no children.

In the following examples, the input tree is represented in flattened form row by row.
The actual root tree given will be a TreeNode object.

Example 1:
Input:
root = [1, 3, 2], k = 1
Diagram of binary tree:
1
/ \
3   2

Output: 2 (or 3)
Explanation: Either 2 or 3 is the closest leaf node to the target of 1.

Example 2:
Input:
root = [1], k = 1
Output: 1
Explanation: The closest leaf node is the root node itself.

Example 3:
Input:
root = [1,2,3,4,null,null,null,5,null,6], k = 2
Diagram of binary tree:
1
/ \
2   3
/
4
/
5
/
6

Output: 3
Explanation: The leaf node with value 3 (and not the leaf node with value 6) is closest to the node with value 2.
*/

#include <iostream>
#include <unordered_map>
#include <vector>
#include <queue>
#include <unordered_set>
using namespace std;

class TreeNode {
public:
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int data) {
        this->val = data;
        this->left = this->right = nullptr;
    }
};

class Solution {
public :
    int findClosetLeaf(TreeNode* root, int k) {
        if (!root)
            return -1;
        start = nullptr;
        buildGraph(root, nullptr, k);
        queue<TreeNode*> q;
        unordered_set<TreeNode*> visited;
        q.push(start);
        visited.insert(start);
        while (!q.empty()) {
            TreeNode* n = q.front();
            q.pop();
            for (TreeNode* c : graph_[n]) {
                //cout << c->val << endl;
                if (visited.count(c) > 0)
                    continue;

                if (c->left == nullptr && c->right == nullptr)
                    return c->val;

                q.push(c);
                visited.insert(c);
            }
        }
        return 0;
    }

private :
    unordered_map<TreeNode*, vector<TreeNode*>> graph_;
    TreeNode* start;
    void buildGraph(TreeNode* node, TreeNode* parent, int k) {
        if (!node)
            return;

        if (node->val == k)
            start = node;

        if (parent) { // if both 'parent' and 'node' exist
            graph_[parent].push_back(node);
            graph_[node].push_back(parent);
        }

        buildGraph(node->left, node, k);
        buildGraph(node->right, node, k);
    }
};

int main() {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->left->left = new TreeNode(5);
    root->left->left->left->left = new TreeNode(6);

    Solution s;
    cout << "ANS : " << s.findClosetLeaf(root, 4) << endl;

    return 0;
}