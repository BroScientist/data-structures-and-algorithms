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
    TreeNode* minOf(TreeNode* root)
    {
        while (root->left)
            root = root->left;
        return root;
    }
    
    TreeNode* deleteNode(TreeNode* root, int key) {
        if (!root)
            return root;
        if (key == root->val)
        {
            // case 1: root has no children
            if (!root->left && !root->right)
            {
                delete root;
                root = nullptr;
                return root;
            }
            // case 2: root has 1 child, keep address of root in a tmp variable, and replace with it's subtree
            if (root->left && !root->right)
            {
                TreeNode* tmp = root;
                root = root->left;
                delete tmp;
                return root;
            }
            if (!root->left && root->right)
            {
                TreeNode* tmp = root;
                root = root->right;
                delete tmp;
                return root;
            }
            // case 3: root has 2 children
            else
            {
                // find the node with min value in root's right subtree, store as tmp
                // replace the value of root the value of that node
                // now, the min value of right node is redundant, so perform a search and delete it
                TreeNode* tmp = minOf(root->right);
                root->val = tmp->val;
                root->right = deleteNode(root->right, tmp->val);
            }
        }
        else if (key < root->val)
            root->left = deleteNode(root->left, key);
        else
            root->right = deleteNode(root->right, key);
            
        return root;
    }
};