/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    unordered_map<int, Node*> graph;
    unordered_set<int> visited;
    Node* getNode(Node* node)
    {
        if (graph.find(node->val) != graph.end())
            return graph[node->val];
        Node* newNode = new Node(node->val);
        graph[node->val] = newNode;
        return newNode;
    }
    
    void dfs(Node* node)
    {
        // cout << node->val << endl;
        for (Node* nei : node->neighbors)
        {
            graph[node->val]->neighbors.push_back(getNode(nei));
            if (visited.find(nei->val) == visited.end())
            {
                visited.insert(nei->val);
                dfs(nei);
            }
        }
    }
    Node* cloneGraph(Node* node) {
        // create empty head node with val of 1
        // for every neighbor of node, call getClonedNode 
        // getClonedNode takes a int value and does look up in hashtable, if val is found, 
        if (!node)
            return nullptr;
        Node* curr = node;
        int currVal = node->val;
        graph[currVal] = new Node(currVal);
        visited.insert(currVal);
        dfs(node);
        return graph[node->val];
    }
};