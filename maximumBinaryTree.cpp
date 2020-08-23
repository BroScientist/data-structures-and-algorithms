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
    // helper function for finding the index of the maximum number within a certain range
    int max(vector<int>& nums, int start, int end)
    {
        int maxIndex = start;
        for (int i = start; i < end; i++)
            if (nums[i] > nums[maxIndex])
                maxIndex = i;
        return maxIndex;
    }
    
    TreeNode* constructTree(vector<int>& nums, int start, int end)
    {
        if (start == end)
            return nullptr;
        // find max and use it as root
        int maxIndex = max(nums, start, end);
        TreeNode* root = new TreeNode(nums[maxIndex]);
        // call constructTree on the left and right of maxIndex to fill and left and right child
        root->left = constructTree(nums, start, maxIndex);
        root->right = constructTree(nums, maxIndex + 1, end);
        return root;
    }
    
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        return constructTree(nums, 0, nums.size());
    }
};