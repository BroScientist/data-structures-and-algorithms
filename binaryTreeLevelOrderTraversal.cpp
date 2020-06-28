#include <iostream>
#include <vector>
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


struct Block {
    TreeNode* node;
    int level;
    Block(TreeNode* node, int level) : node(node), level(level) {}
};

class Solution {
public:
    vector<vector<int>> result;
    vector<int> levelValues, levelResult;

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
                for (int& n : levelValues)
                    levelResult.push_back(n);
                result.push_back(levelResult);
                levelResult.clear();
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
    vector<vector<int>> levelOrder(TreeNode* root) {
        // never forget empty case...
        if (!root)
            return result;
        levelorder(root);
        for (int& n : levelValues)
            levelResult.push_back(n);
        result.push_back(levelResult);
        return result;
    }
};