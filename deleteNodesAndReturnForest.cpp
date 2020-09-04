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
    vector<TreeNode*> res;
    unordered_set<int> toDelete;
    
    void postorder(TreeNode* &node)
    {
        if (node)
        {
            postorder(node->left);
            postorder(node->right);
            if (toDelete.count(node->val) > 0)
            {
                if (node->left)
                    res.push_back(node->left);
                if (node->right)
                    res.push_back(node->right);
                node = nullptr;
            }
        }
    }
    
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) 
    {
        for (int& n : to_delete)
            toDelete.insert(n);
        postorder(root);
        if (root && toDelete.count(root->val) == 0)
            res.push_back(root);
        return res;
    }
};