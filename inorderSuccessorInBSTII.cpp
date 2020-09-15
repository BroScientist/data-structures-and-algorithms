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
    Node* res = nullptr;
    bool found = false, done = false;
    
    void inorder(Node* node, Node* target)
    {
        if (node)
        {
            inorder(node->left, target);
            if (done)
                return;
            if (found)
            {
                res = node;
                done = true;
                return;
            }
            if (node == target)
                found = true;
            inorder(node->right, target);
        }
    }
    
    Node* inorderSuccessor(Node* node) {
        Node* target = node;
        while (node->parent)
            node = node->parent;
        inorder(node, target);
        return res;
    }
};