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
#include <iostream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    int depth;
    int sum = 0;
    int maxDepth(TreeNode* root)
    {
        if (root == nullptr)
            return 0;
        return max(maxDepth(root->left), maxDepth(root->right)) + 1;
    }
    
    void sumLeaves(TreeNode* root, int level)
    {
        if (root == nullptr)
            return;
        if (level == depth)
        {
            sum += root->val;
            return;
        }
        sumLeaves(root->left, level + 1);
        sumLeaves(root->right,level + 1);
    }
    int deepestLeavesSum(TreeNode* root) {
        depth = maxDepth(root);
        sumLeaves(root, 1);
        return sum;
    }
};