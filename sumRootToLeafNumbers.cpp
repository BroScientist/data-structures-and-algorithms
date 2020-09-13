/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int sum = 0;
    string curr = "";
    void preorder(TreeNode* node)
    {
        if (node)
        {
            curr += to_string(node->val);
            if (!node->left && !node->right)
            {
                sum += stoi(curr);
                curr.pop_back();
                return;
            }
            preorder(node->left);
            preorder(node->right);
            // if this line is reached, it means the current subtree has been completely processed
            // therefore, we pop back again
            curr.pop_back(); 
        }
    }
    
    int sumNumbers(TreeNode* root) {
        preorder(root);
        return sum;
    }
};