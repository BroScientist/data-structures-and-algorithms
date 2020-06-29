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

struct Block {
    TreeNode* node;
    int level;
    Block(TreeNode* node, int level) : node(node), level(level) {}
};

class Solution {
public:
    // vector<vector<int>> result;
    vector<double> levelValues, result;

    void levelorder(TreeNode* root)
    {
        queue<Block*> q;
        Block* temp = new Block(root, 1);
        int currLevel = 1;
        Block* data;
        q.push(temp);
        while (!q.empty())
        {
            temp = q.front();
            q.pop();
            if (temp->level > currLevel)
            {
                currLevel = temp->level;
                double sum = 0;
                for (double& n : levelValues)
                    sum += n;
                result.push_back(sum / levelValues.size());
                levelValues.clear(); 
            }
            levelValues.push_back(temp->node->val);
            if (temp->node->left)
            {
                data = new Block(temp->node->left, temp->level + 1);
                q.push(data);
            }
            if (temp->node->right)
            {
                data = new Block(temp->node->right, temp->level + 1);
                q.push(data);
            }
        }
    }
    vector<double> averageOfLevels(TreeNode* root) {
        if (!root)
            return result;
        levelorder(root);
        double sum = 0;
        for (double& n : levelValues)
            sum += n;
        result.push_back(sum / levelValues.size());
        return result;
    }
};