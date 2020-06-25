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
    
    void swap(TreeNode* parent, TreeNode* l, TreeNode* r)
    {
        TreeNode* temp = r;
        parent->right = l;
        parent->left = temp;
    }
    
    void traverse(TreeNode* root)
    {
        if (root == nullptr)
            return;
        swap(root, root->left, root->right);
        traverse(root->left);
        traverse(root->right);
    }
    
    TreeNode* invertTree(TreeNode* root) {
        traverse(root);
        return root;
    }
};