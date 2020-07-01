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
    vector<int> list1, list2;
    void inorder(TreeNode* root, vector<int>& list)
    {
        if (root)
        {
            inorder(root->left, list);
            list.push_back(root->val);
            inorder(root->right, list);
        }
    }
    
    bool twoSumBSTs(TreeNode* root1, TreeNode* root2, int target) {
        inorder(root1, list1);
        inorder(root2, list2);
        int i = 0;
        int j = list2.size() - 1;
        int sum = 0;
        while(1)
        {
            sum = list1[i] + list2[j];
            if (sum == target)
                return true;
            // if list1 has been exhausted and sum is still less than target, return false
            // similarily, if list2 has been exhausted and sum is still greater than target, return false
            if ((sum < target && i == list1.size() - 1) || (sum > target && j == 0))
                return false;
            if (sum < target)
                i++;
            if (sum > target)
                j--;
        }
        return true;
    }
};