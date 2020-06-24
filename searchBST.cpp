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
    TreeNode* result = nullptr;
    void search(TreeNode* root, int val) {
        if (root != nullptr)
        {
            if (root->val == val)
                result = root;
            if (val < root->val)
                search(root->left, val);
            if (val > root->val)
                search(root->right, val);
        }
    }
    
    TreeNode* searchBST(TreeNode* root, int val) {
        search(root, val);
        return result;   
    }
};