/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    
    vector<vector<int>> levelOrder(Node* root) {
        vector<vector<int>> res;
        if (!root)
            return res;
        vector<int> level;
        
        queue<Node*> q;
        q.push(root);
        
        while (!q.empty())
        {
            int nodeCount = q.size();
            while (nodeCount != 0)
            {
                Node* tmp = q.front();
                // cout << tmp->val << endl;
                level.push_back(tmp->val);
                q.pop();
                for (Node* kid : tmp->children)
                    q.push(kid);
                nodeCount--;
            }
            res.push_back(level);
            level.clear();
            // cout << endl;
        }
        return res;
    }
};