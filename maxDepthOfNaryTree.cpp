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

    int maxDepth(Node* root) {
        if (root == nullptr)
            return 0;
        if (root->children.empty())
            return 1;
        vector<int> heights;
        for (auto kid : root->children)
            heights.push_back(maxDepth(kid));
        return *max_element(heights.begin(), heights.end()) + 1;
    }
};