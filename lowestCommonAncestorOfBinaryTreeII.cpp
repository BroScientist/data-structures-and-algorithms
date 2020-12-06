/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    // traverse the tree and keep track of the current path
    // if p or q is encountered, store current path as pPath or qPath
    // if the other node is encountered, check path for res
    
    vector<TreeNode*> path, qPath, pPath;
    bool pFound = false, qFound = false;
    void preorder(TreeNode* node, TreeNode* p, TreeNode* q)
    {
        if (node)
        {
            path.push_back(node);
            if (node->val == p->val)
            {
                pPath = path;
                pFound = true;
            }
            if (node->val == q->val)
            {
                qPath = path;
                qFound = true;
            }
            
            if (!node->left && !node->right)
            {
                path.pop_back();
                return;
            }
            preorder(node->left, p, q);
            preorder(node->right, p, q);
            path.pop_back();
        }
    }
    
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        // find paths by calling the traversal function
        preorder(root, p, q);
        
        // if both p and q are present, scan their path to find the last common node
        if (pFound && qFound)
        {
            // do this by inserting all of one path into a set
            unordered_set<int> seen;
            for (TreeNode* n : pPath)
                seen.insert(n->val);
            // then loop through the second path from behind, the first duplicate is the answer
            for (int i = qPath.size() - 1; i >= 0; i--)
                if (seen.find(qPath[i]->val) != seen.end())
                    return qPath[i];
        }
        
        // otherwise, return null
        return nullptr;
    }
};