#include <iostream>
#include <vector>
using namespace std;


class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};

class Solution {
public:
    vector<int> result;
    void preorder_traversal(Node* root)
    {
        if (root == nullptr)
            return;
        result.push_back(root->val);
        if (root->children.size() == 0)
            return;
        for (int i = 0; i < root->children.size() - 1; i++)
        {
            preorder_traversal(root->children[i]);
        }
        preorder_traversal(root->children[root->children.size() - 1]);
    }
    
    vector<int> preorder(Node* root) {
        preorder_traversal(root);
        return result;
    }
};