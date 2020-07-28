#include <iostream>
#include <vector>
#include <queue>

using namespace std;

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
    vector<int> sums;
    void levelorder(TreeNode* root)
    {
        queue<TreeNode*> q;
        TreeNode* tmp = root;
        q.push(tmp);
        while (!q.empty())
        {
            int levelSum = 0;
            int nodeCount = q.size();
            while (nodeCount != 0)
            {
                TreeNode* tmp = q.front();
                q.pop();
                levelSum += tmp->val;
                if (tmp->left)
                    q.push(tmp->left);
                if (tmp->right)
                    q.push(tmp->right);
                nodeCount--;
            }
            // cout << levelSum << endl;
            sums.push_back(levelSum);
        }
    }
    int maxLevelSum(TreeNode* root) {
        if (!root)
            return 0;
        levelorder(root);
        int maxSum = *max_element(begin(sums), end(sums));
        for (int i = 0; i < sums.size(); i++)
            if (sums[i] == maxSum)
                return ++i;
        return 1;
    }
};