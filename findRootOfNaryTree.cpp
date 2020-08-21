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
    Node* findRoot(vector<Node*> tree) {
        // no need to use DFS or indegree. Simply add all childs in all node->children to a set
        // the node that was not added to the set is the root node
        unordered_set<Node*> kids;
        for (Node* node : tree)
        {
            for (Node* child : node->children)
                kids.insert(child);
        }
        for (Node* node : tree)
        {
            if (kids.find(node) == kids.end())
                return node;
        }
        return nullptr;
    }
};