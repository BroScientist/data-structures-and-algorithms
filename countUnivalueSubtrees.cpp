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
    
    bool isLeaf(TreeNode* node)
    {
        return !node->left && !node->right;
    }
    
    bool isUnival(TreeNode* node, int unival)
    {
        if (isLeaf(node) && node->val == unival)
            return true;
        if (node->val != unival)
            return false;
        
        bool left = !node->left ? true : false;
        bool right = !node->right ? true : false;
        if (node->left && node->left->val == unival)
            left = isUnival(node->left, unival);
        if (left)
            if (node->right && node->right->val == unival)
                right = isUnival(node->right, unival);
        return left && right;
    }
    
    void preorder(TreeNode* node)
    {
        if (node)
        {
            if (isLeaf(node))
            {
                count++;
                return;
            }
            count += isUnival(node, node->val);
            preorder(node->left);
            preorder(node->right);
        }
    }
    
    int countUnivalSubtrees(TreeNode* root) {
        preorder(root);
        return count;
    }
};