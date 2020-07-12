#include <iostream>
#include <queue>
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
    vector<int> currLevel;
    
    void levelorder(TreeNode* root)
    {
        queue<TreeNode*> queue;
        TreeNode* tmp = root;
        queue.push(tmp);
        int nodeCount;
        
        while (!queue.empty())
        {
            nodeCount = queue.size();
            currLevel.clear();
            while (nodeCount != 0)
            {
                tmp = queue.front();
                // cout << tmp->val << endl;
                currLevel.push_back(tmp->val);
                queue.pop();
                if (tmp->left)
                    queue.push(tmp->left);
                if (tmp->right)
                    queue.push(tmp->right);
                nodeCount--;
            }
            // cout << endl;
                 
        }
    }
    int findBottomLeftValue(TreeNode* root) {
        levelorder(root);
        return currLevel[0];
    }
};