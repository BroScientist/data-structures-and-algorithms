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
    unordered_set<int> seen;
    bool found = false;
    
    // I forgot the & bruh... I'm so goddamn washed
    void traverse(TreeNode* &node)
    {
        if (found)
            return;
        if (node)
        {
            if (node->right && seen.find(node->right->val) != seen.end())
            {
                node = nullptr;
                found = true;
                return;
            }
            seen.insert(node->val);
            traverse(node->right);
            traverse(node->left);
        }
    }
    
    TreeNode* correctBinaryTree(TreeNode* root) 
    {
        traverse(root);
        return root;
    }

};