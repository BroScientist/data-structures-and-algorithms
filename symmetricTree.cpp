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
    vector<int> leftSub, rightSub;
    
    void preorder1(TreeNode* root)
    {
        if (root)
        {
            leftSub.push_back(root->val);
            preorder1(root->left);
            preorder1(root->right);
        }
        else
            leftSub.push_back(-1);
    }
    
    void preorder2(TreeNode* root)
    {
        if (root)
        {
            rightSub.push_back(root->val);
            preorder2(root->right);
            preorder2(root->left);
        }
        else
            rightSub.push_back(-1);
    }
    bool isSymmetric(TreeNode* root) {
        if (!root)
            return true;
        if (!root->left && !root->right)
            return true;
        if (root->left && root->right)
        { 
            preorder1(root->left);
            preorder2(root->right);
            // for (int& n : leftSub)
            //     cout << n << " ";
            // cout << endl;
            // for (int& n : rightSub)
            //     cout << n << " ";
            return leftSub == rightSub;
        }
        return false;
    }
};