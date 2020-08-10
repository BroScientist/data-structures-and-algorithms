#include <vector>
#include <iostream>
#include <queue>
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
    int minDepth(TreeNode* root) {
        if (!root)
            return 0;
        queue<TreeNode*> queue;
        queue.push(root);
        int nodeCount, level = 1;
        while (!queue.empty())
        {
            nodeCount = queue.size();
            while (nodeCount != 0)
            {
                TreeNode* tmp = queue.front();
                queue.pop();
                if (!tmp->left && !tmp->right)
                    return level;
                if (tmp->left)
                    queue.push(tmp->left);
                if (tmp->right)
                    queue.push(tmp->right);
                nodeCount--;
            }
            level++;
        }
        return -1;
    }
};