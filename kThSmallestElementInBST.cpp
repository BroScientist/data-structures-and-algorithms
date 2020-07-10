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
    int target, visits = 0;
    void inorder(TreeNode* root, int i)
    {
        if (root)
        {
            inorder(root->left, i);
            visits++;
            // if the number of visits in an inorder traversal reaches i, then the current node is the ith smallest
            if (visits == i)
            {
                target = root->val;
                return;
            }
            inorder(root->right, i);
        }
    }
    int kthSmallest(TreeNode* root, int k) {
        inorder(root, k);
        return target;
    }
};