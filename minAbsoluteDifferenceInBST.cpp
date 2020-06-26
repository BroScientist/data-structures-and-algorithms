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

class Solution {
public:
    vector<int> values;
    
    void preorder(TreeNode* root)
    {
        if (root == nullptr)
            return;
        values.push_back(root->val);
        preorder(root->left);
        preorder(root->right);
    }
    int getMinimumDifference(TreeNode* root) {
        if (root->left == nullptr && root->right == nullptr)
            return 2147483647;
        preorder(root);
        sort(values.begin(), values.end());
        int min = 2147483647;
        for (int i = 0; i < values.size() - 1; i++)
        {
            if (values[i + 1] - values[i] < min)
                min = values[i + 1] - values[i];
        }
        return min;
    }
};