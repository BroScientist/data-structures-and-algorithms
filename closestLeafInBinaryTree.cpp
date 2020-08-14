#include <iostream>
#include <unordered_map>
#include <queue>
#include <list>
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
    unordered_map<TreeNode*, list<TreeNode*>> graph;

    void dfs(TreeNode* node, TreeNode* parent)
    {
        // convert binary tree to graph
        if (node)
        {
            if (graph.find(node) == graph.end())
                graph[node] = list<TreeNode*>();
            if (graph.find(parent) == graph.end())
                graph[parent] = list<TreeNode*>();
            graph[node].push_back(parent);
            graph[parent].push_back(node);
            dfs(node->left, node);
            dfs(node->right, node);
        }
    }
    
    int findClosestLeaf(TreeNode* root, int k) {
        dfs(root, nullptr);
        
        queue<TreeNode*> queue;
        unordered_set<TreeNode*> seen;
        
        for (auto& item : graph)
        {
            if (item.first != nullptr && item.first->val == k)
            {
                queue.push(item.first);
                seen.insert(item.first);
                break;
            }
        }
        
        while (!queue.empty())
        {
            TreeNode* node = queue.front();
            queue.pop();
            if (node)
            {
                if (graph[node].size() <= 1)
                    return node->val;
                for (TreeNode* neighbor : graph[node])
                {
                    if (seen.find(neighbor) == seen.end())
                    {
                        seen.insert(neighbor);
                        queue.push(neighbor);
                    }
                }
            }
        }
        return 0;
    }
};
