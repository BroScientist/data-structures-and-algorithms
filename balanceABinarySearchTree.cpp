/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<int> nums;
    void inorder(TreeNode* node)
    {
        if (node)
        {
            inorder(node->left);
            nums.push_back(node->val);
            inorder(node->right);
        }
    }
    
    TreeNode* constructTree(vector<int>& nums, int left, int right)
    {
        if (left > right)
            return nullptr;
        int mid = (left + right) / 2;
        TreeNode* node = new TreeNode(nums[mid]);
        node->left = constructTree(nums, left, mid - 1);
        node->right = constructTree(nums, mid + 1, right);
        return node;
    }
    
    TreeNode* balanceBST(TreeNode* root) {
        inorder(root);
        TreeNode* balanced = constructTree(nums, 0, nums.size() - 1);
        return balanced;
    }
};