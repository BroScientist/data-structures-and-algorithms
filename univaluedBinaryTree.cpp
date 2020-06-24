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
    bool univalued = true;
    void preorder(TreeNode* root, int number)
    {
        if (root != nullptr)
        {
            if (root->val != number)
            {
                univalued = false;
                return;
            }
            preorder(root->left, number);
            preorder(root->right, number);
        }
       
    }
    
    bool isUnivalTree(TreeNode* root) {
        preorder(root, root->val);
        return univalued;
    }
};