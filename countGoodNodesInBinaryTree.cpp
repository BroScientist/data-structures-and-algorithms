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

    int count = 0;
    void preorder(TreeNode* node, int upper)
    {
        if (node)
        {
            // if node has value that is at least as large as the max of the path from root to it
            // it is a good node so we increment count and update the value of upper
            if (node->val >= upper)
                upper = node->val, count++;
            preorder(node->left, upper);
            preorder(node->right, upper);
        }
    }
    
    int goodNodes(TreeNode* root) {
        preorder(root, root->val);
        return count;
    }
};