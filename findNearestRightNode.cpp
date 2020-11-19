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
    TreeNode* findNearestRightNode(TreeNode* root, TreeNode* u) {
        vector<TreeNode*> level;
        queue<TreeNode*> q;
        TreeNode* tmp = root;
        q.push(tmp);
        while (!q.empty())
        {
            int nodeCount = q.size(), index = -1, targetIndex = -1;
            while (nodeCount != 0)
            {
                tmp = q.front();
                q.pop();
                level.push_back(tmp);
                index++;
                // if the current node is equal to target, set targetIndex as current index
                if (tmp->val == u->val)
                    targetIndex = index;
                if (tmp->left)
                    q.push(tmp->left);
                if (tmp->right)
                    q.push(tmp->right);
                nodeCount--;
            }
            // if targetIndex has been set, determine if it is the last element in its level
            // if it is, it means there is nothing to the right of it (return null), otherwise return the eleemnt to its right
            if (targetIndex != -1)
                return targetIndex == level.size() - 1 ? nullptr : level[targetIndex + 1];
            // if targetIndex has not been set yet (target node is not on this level), clear the level and reset index
            level.clear();
            index = -1;
        }
        return nullptr;
    }
};