#include <iostream>
#include <unordered_map>
#include <queue>
#include <vector>
#include <unordered_set>
using namespace std;


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    unordered_map<TreeNode*, TreeNode*> parents;
    void dfs(TreeNode* node, TreeNode* par)
    {
        if (node)
        {
            parents[node] = par;
            dfs(node->left, node);
            dfs(node->right, node);
        }
    }
    
    vector<int> levelorder(TreeNode* target, int K)
    {
        queue<TreeNode*> queue;
        queue.push(target);
        unordered_set<TreeNode*> seen;
        seen.insert(target);
        int dist = 0;
        vector<int> res;
        
        while (!queue.empty())
        {
            if (dist == K)
            {
                while (!queue.empty())
                {
                    res.push_back(queue.front()->val);
                    queue.pop();
                }
                return res;
            }
            int nodeCount = queue.size();
            dist++;
            while (nodeCount != 0)
            {
                TreeNode* node = queue.front();
                if (node->left)
                {
                    if (seen.find(node->left) == seen.end())
                    {
                        seen.insert(node->left);
                        queue.push(node->left);
                    }
                }
                if (node->right)
                {
                    if (seen.find(node->right) == seen.end())
                    {
                        seen.insert(node->right);
                        queue.push(node->right);
                    }
                }
                TreeNode* parent = parents[node];
                if (parent)
                {
                    if (seen.find(parent) == seen.end())
                    {
                        seen.insert(parent);
                        queue.push(parent);
                    }
                }
                queue.pop();
                nodeCount--;

            }
        }
        
        return res;
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int K) {
        dfs(root, nullptr);
        return levelorder(target, K);
    }
};