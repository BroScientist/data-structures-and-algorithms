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
    void postorder_traversal(Node* root)
    {
        if (root == nullptr)
            return;
        if (root->children.size() == 0)
        {
            result.push_back(root->val);
            return;
        }
        for (int i = 0; i < root->children.size() - 1; i++)
        {
            postorder_traversal(root->children[i]);
        }
        postorder_traversal(root->children[root->children.size() - 1]);
        result.push_back(root->val);
    }
    
    vector<int> postorder(Node* root) {
        postorder_traversal(root);
        return result;
    }
};