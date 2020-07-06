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

struct Block
{
    TreeNode* node;
    TreeNode* parent;
    int level;
    Block(TreeNode* n, int l) : node(n), parent(nullptr), level(l) {}
    Block(TreeNode* n, TreeNode* p, int l) : node(n), parent(p), level(l) {}
};

class Solution {
public:
    // use level order traversal, find the two nodes and remember their parents
    bool isCousins(TreeNode* root, int x, int y)
    {
        queue<Block*> q;
        Block* tmp = new Block(root, 1);
        q.push(tmp);
        int nodeCount = 0;
        int xLevel, xParent, yLevel, yParent;
        bool foundOne = false;
        while (!q.empty())
        {
            nodeCount = q.size();
            while (nodeCount != 0)
            {
                tmp = q.front();
                q.pop();
                if (tmp->node->val == x)
                {
                    // if tmp == x but doesn't have a parent, set xParent to a value that doens't exist in the tree, such as 101)
                    xParent = (tmp->parent) ? tmp->parent->val : 101;
                    xLevel = tmp->level;
                }
                if (tmp->node->val == y)
                {
                    yParent = (tmp->parent) ? tmp->parent->val : 101;
                    yLevel = tmp->level;
                }
                if (tmp->node->left)
                    q.push(new Block(tmp->node->left, tmp->node, tmp->level+1));
                if (tmp->node->right)
                    q.push(new Block(tmp->node->right, tmp->node, tmp->level+1));
                nodeCount--;
            }
            if (xParent != yParent)
                if (xLevel == yLevel)
                    return true;
        }
        return false;
    }
};