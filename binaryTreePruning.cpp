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
    bool dfs(TreeNode* &node)
    {
        if (node)
        {
            bool l = dfs(node->left);
            bool r = dfs(node->right);
            if (node->val != 1 && !l && !r)
            {
                node = nullptr;
                return false;
            }
            return true;
        }
        return false;
    }
    
    TreeNode* pruneTree(TreeNode* root) {
        dfs(root);
        return root;
    }
};