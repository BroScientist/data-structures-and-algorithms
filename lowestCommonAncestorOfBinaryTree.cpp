#include <iostream>
#include <vector>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

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
    vector<TreeNode*> path, path1, path2;
    bool found = false;
    void preorder(TreeNode* root, int whichPath, TreeNode* target)
    {
        if (!root || found)
            return;
        path.push_back(root);    

        if (root->val == target->val)
        {
            if (whichPath == 1)
                for (TreeNode* node : path)
                {
                    path1.push_back(node);
                    // cout << node->val << " ";
                }
            else
                for (TreeNode* node : path)
                {
                    path2.push_back(node);
                    // cout << node->val << " ";
                }
            // cout << endl;
            path.pop_back();
            found = true;
            return;
        }
        preorder(root->left, whichPath, target);                                                                                           
        preorder(root->right, whichPath, target);
        path.pop_back();
    }
    
    
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        preorder(root, 1, p);
        found = false; path.clear();
        preorder(root, 2, q);
        
        TreeNode* lastAncestor = root;
        for (int i = 0; i < path1.size(); i++)
        {
            if (i == path2.size() || path1[i]->val != path2[i]->val)
                break;
            lastAncestor = path1[i];
        }
        return lastAncestor;
    }
};