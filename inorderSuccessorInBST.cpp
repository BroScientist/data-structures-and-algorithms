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
    TreeNode* res;
    bool found = false, done = false;
    // I thought this question asked for min of right subtree, as in:
    //     void findMin(TreeNode* root)
    //     {
    //         while (root->left)
    //             root = root->left;
    //         res = root;
    //     }
    
    void inorder(TreeNode* root, TreeNode* p)
    {
        if (root)
        {
            inorder(root->left, p);
            if (done)
                return;
            if (found)
            {
                res = root;
                // once the result node has been set, mark as done
                done = true;
                return;
            }
            if (root->val == p->val)
                found = true;
            inorder(root->right, p);
        }
    }
    TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {
        inorder(root, p);
        return res;
    }
};
