/**
 * Definition for a Node.
 * struct Node {
 *     int val;
 *     Node *left;
 *     Node *right;
 *     Node *random;
 *     Node() : val(0), left(nullptr), right(nullptr), random(nullptr) {}
 *     Node(int x) : val(x), left(nullptr), right(nullptr), random(nullptr) {}
 *     Node(int x, Node *left, Node *right, Node *random) : val(x), left(left), right(right), random(random) {}
 * };
 */

class Solution {
public:
    unordered_map<Node*, NodeCopy*> hashtable;
    
    // create skelton node copies that only contain value
    void preorder(Node* node)
    {
        if (node)
        {
            hashtable[node] = new NodeCopy(node->val);
            preorder(node->left);
            preorder(node->right);
        }
    }
    
    void construct(Node* node)
    {
        if (node)
        {
            hashtable[node]->random = hashtable[node->random];
            hashtable[node]->left = hashtable[node->left];
            hashtable[node]->right = hashtable[node->right];
            construct(node->left);
            construct(node->right);
        }
    }
    
    NodeCopy* copyRandomBinaryTree(Node* root) {
        preorder(root);
        construct(root);
        return hashtable[root];
    }
};


