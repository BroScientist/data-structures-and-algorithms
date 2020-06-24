#include <vector>
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
    int sum = 0;
    void preorder(TreeNode* root, int L, int R)
    {
        if (root == nullptr)
            return;
        if (root->val >= L && root->val <= R)
            sum += root->val;
        preorder(root->left, L, R);
        preorder(root->right, L, R);
    }
    int rangeSumBST(TreeNode* root, int L, int R) {
        preorder(root, L, R);
        return sum;
    }
};