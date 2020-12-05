/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* parent;
};
*/

class Solution {
public:
    unordered_set<int> seen;
    Node* res;
    bool found = false;
    
    // travel back from p to root, storing nodes seen along the way
    void findPathToRoot(Node* p)
    {
        if (p)
        {
            seen.insert(p->val);
            findPathToRoot(p->parent);
        }
    }
    
    // travel back from q to root, the first node along the path that is in the path of p is the answer
    void findAncestor(Node* q)
    {
        if (found)
            return;
        if (q)
        {
            if (seen.find(q->val) != seen.end())
            {
                found = true;
                res = q;
                return;
            }
            findAncestor(q->parent);
        }
        
    }
    Node* lowestCommonAncestor(Node* p, Node * q) {
        findPathToRoot(p);
        findAncestor(q);
        return res;
    }
};