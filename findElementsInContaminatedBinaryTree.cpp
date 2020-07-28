#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

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

class FindElements {
public:
    unordered_map<int, int> seen;
    void preorder(TreeNode* root)
    {
        if (root)
        {
            seen[root->val]++;
            if (root->left)
                root->left->val = 2 * root->val + 1;
            if (root->right)
                root->right->val = 2 * root->val + 2;
            preorder(root->left);
            preorder(root->right);
        }
    }
    FindElements(TreeNode* root) {
        root->val = 0;
        preorder(root);
    }
    
    bool find(int target) {
        return seen.find(target) != seen.end();   
    }
};

/**
 * Your FindElements object will be instantiated and called as such:
 * FindElements* obj = new FindElements(root);
 * bool param_1 = obj->find(target);
 */