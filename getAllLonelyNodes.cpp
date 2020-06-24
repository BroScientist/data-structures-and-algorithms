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
    vector<int> results;
    void preorder(TreeNode* root)
    {
        if (root == nullptr)
            return;
        checkChildren(root);
        preorder(root->left);
        preorder(root->right);
    }
    void checkChildren(TreeNode* root)
    {
        if (root->left == nullptr && root->right != nullptr)
            results.push_back(root->right->val);
        if (root->left != nullptr && root->right == nullptr)
            results.push_back(root->left->val);
    }
    
    vector<int> getLonelyNodes(TreeNode* root) {
        preorder(root);
        return results;
    }
};