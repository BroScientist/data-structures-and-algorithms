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
    unordered_map<Node*, Node*> hashtable;
    void preorder(Node* node)
    {
        hashtable[node] = new Node(node->val, vector<Node*>());
        for (Node* child : node->children)
            preorder(child);
    }
    
    void dfs(Node* node)
    {
        // hashtable[node]->children = node->children;
        if (node->children.size() == 0)
            return;
        for (Node* child : node->children)
        {
            hashtable[node]->children.push_back(hashtable[child]);
            dfs(child);
        }
    }
    
    Node* cloneTree(Node* root) 
    {
        if (!root)
            return nullptr;
        preorder(root);
        dfs(root);
        return hashtable[root];
    }
};