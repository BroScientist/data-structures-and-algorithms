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

class BSTIterator {
public:
    vector<TreeNode*> sortedTree;
    int index = -1;
    void inorder(TreeNode* root)
    {
        if (root)
        {
            inorder(root->left);
            sortedTree.push_back(root);
            inorder(root->right);
        }
    }
    BSTIterator(TreeNode* root) {
        inorder(root);
    }
    
    /** @return the next smallest number */
    int next() {
        return sortedTree[++index]->val;
    }
    
    /** @return whether we have a next smallest number */
    bool hasNext() {
        return (index != sortedTree.size() - 1);
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */