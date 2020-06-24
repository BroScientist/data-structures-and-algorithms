#include <vector>
#include <iostream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    vector<int> nodes;
    void inorder(TreeNode* root)
    {
        if (root == nullptr)
            return;
        inorder(root->left);
        nodes.push_back(root->val);
        inorder(root->right);
    }
    
    TreeNode* increasingBST(TreeNode* root) {
        inorder(root);
        TreeNode* newRoot = new TreeNode(nodes[0], nullptr, nullptr);
        TreeNode* curr = newRoot;
        for (int i = 1; i < nodes.size(); i++)
        {
            TreeNode* newNode = new TreeNode(nodes[i], nullptr, nullptr);
            curr->right = newNode;
            curr = curr->right;
        }
        return newRoot;
    }
};