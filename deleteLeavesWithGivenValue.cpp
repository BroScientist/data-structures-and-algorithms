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
    bool isTargetLeaf(TreeNode* node, int target)
    {
        if (node)
            return (node->left == nullptr && node->right == nullptr && node->val == target);
        return false;
    }
    void postorder(TreeNode* node, int target)
    {
        if (node)
        {
            postorder(node->left, target);
            postorder(node->right, target);
            if (isTargetLeaf(node->left, target))
            {
                delete node->left;
                node->left = nullptr;
            }
            if (isTargetLeaf(node->right, target))
            {
                delete node->right;
                node->right = nullptr;
            }
        }
    }
    TreeNode* removeLeafNodes(TreeNode* root, int target) {
        postorder(root, target);
        if (root->val == target && isTargetLeaf(root, target))
            return nullptr;
        return root;
    }
};