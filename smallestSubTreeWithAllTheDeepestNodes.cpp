/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    unordered_map<TreeNode*, int> depth;
    int maxDepth = 0;
    void preorder(TreeNode* node, int level)
    {
        if (node)
        {
            depth[node] = level;
            maxDepth = max(maxDepth, level);
            preorder(node->left, level + 1);
            preorder(node->right, level + 1);
        }
    }
    
    TreeNode* answer(TreeNode* node)
    {
        if (!node || depth[node] == maxDepth)
            return node;
        TreeNode* left = answer(node->left);
        TreeNode* right = answer(node->right);
        if (left && right)
            return node;
        if (left)
            return left;
        if (right)
            return right;
        return nullptr;
    }
    
    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
        preorder(root, 0);
        return answer(root);
    }
};