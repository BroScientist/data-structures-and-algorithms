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
    bool equiv = true;
    unordered_map<int, set<int>> map; // parent to child node values
    void fillMap(TreeNode* node)
    {
        if (node)
        {
            if (node->left)
                map[node->val].insert(node->left->val);
            else
                map[node->val].insert(-1);
            if (node->right)
                map[node->val].insert(node->right->val);
            else
                map[node->val].insert(-1);
            
            fillMap(node->left);
            fillMap(node->right);
        }
    }
    
    void preorder(TreeNode* node)
    {
        if (!equiv)
            return;
        
        if (node)
        {
            set<int> children;
            if (node->left)
                children.insert(node->left->val);
            else
                children.insert(-1);
            if (node->right)
                children.insert(node->right->val);
            else
                children.insert(-1);
            
            if (children != map[node->val])
                equiv = false;
            
            preorder(node->left);
            preorder(node->right);
        }
    }
    
    bool flipEquiv(TreeNode* root1, TreeNode* root2) {
        if ((root1 && !root2) || (root2 && !root1))
            return false;
        if (root1 && root2 && root1->val != root2->val)
            return false;
        fillMap(root1);
        preorder(root2);
        return equiv;
    }
};