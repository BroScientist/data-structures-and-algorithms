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
    
    int longest = 0;
    
    int maxDepth(TreeNode* node, int pathVal)
    {
        if (!node || node->val != pathVal)
            return 0;
        return max(maxDepth(node->left, pathVal), maxDepth(node->right, pathVal)) + 1;
    }
    
    void preorder(TreeNode* node)
    {
        if (node)
        {
            int left = 0, right = 0;
            if (node->left && node->left->val == node->val)
                left = maxDepth(node->left, node->left->val);
            if (node->right && node->right->val == node->val)
                right = maxDepth(node->right, node->right->val);
            longest = max(longest, left + right);
            preorder(node->left);
            preorder(node->right);
        }
    }

    int longestUnivaluePath(TreeNode* root) {
        preorder(root);
        return longest;
    }
};