/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    unordered_map<Node*, Node*> visited;
    Node* getClone(Node* node)
    {
        if (node)
        {
            // if node has already been visited, simply return the its corresponding cloned node
            if (visited.find(node) != visited.end())
                return visited[node];
            // otherwise, create a clone based on the current node's value, and inserted into the hashtable
            visited[node] = new Node(node->val);
            return visited[node];
        }
        return nullptr;
    }
    
    Node* copyRandomList(Node* head) {
        if (!head)
            return nullptr;
        Node* oldNode = head;
        Node* newNode = new Node(head->val);
        visited[oldNode] = newNode;
        while (oldNode)
        {
            // call the getClone function to populate the random and next pointers of newNode
            newNode->random = getClone(oldNode->random);
            newNode->next = getClone(oldNode->next);
            // move the list forward
            oldNode = oldNode->next;
            newNode = newNode->next;
        }
        return visited[head];
    }
};