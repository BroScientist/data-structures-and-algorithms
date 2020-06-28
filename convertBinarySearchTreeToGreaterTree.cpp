#include <iostream>
#include <numeric>
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

class Solution {
public:
    vector<int> sortedValues;
    int index = 1;
    void obtainSortedValues(TreeNode* root)
    {
        if (root == nullptr)
            return;
        obtainSortedValues(root->left);
        sortedValues.push_back(root->val);
        obtainSortedValues(root->right);
    }
    
    void inorder(TreeNode* root)
    {
        if (root == nullptr)
            return;
        inorder(root->left);
        root->val += accumulate(sortedValues.begin() + index++, sortedValues.end(), 0);
        inorder(root->right);
    }
    TreeNode* convertBST(TreeNode* root) {
        obtainSortedValues(root);
        inorder(root);
        return root;
    }
};