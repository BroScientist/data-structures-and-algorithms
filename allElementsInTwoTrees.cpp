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
    vector<int> treeValues;
    
    void inorder(TreeNode* root)
    {
        if (root)
        {
            inorder(root->left);
            treeValues.push_back(root->val);
            inorder(root->right);
        }
    }
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        inorder(root1);
        inorder(root2);
        // tree1.insert(tree1.end(), tree2.begin(), tree2.end());
        sort(treeValues.begin(), treeValues.end());
        return treeValues;
    }
};