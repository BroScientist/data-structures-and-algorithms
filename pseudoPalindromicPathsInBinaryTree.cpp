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
    bool isPalindromePermu(unordered_map<int,int>& freq)
    {
        if (freq.size() == 1)
            return true;
        bool flag = false;
        for (auto& item : freq)
        {
            if (flag && item.second % 2 != 0)
                return false;
            if (item.second % 2 != 0)
                flag = true;
        }
        return true;
    }
    
    int count = 0;
    string path = "";
    unordered_map<int,int> freq;
    void preorder(TreeNode* node)
    {
        if (node)
        {
            path += to_string(node->val);
            if (!node->left && !node->right)
            {
                for (char& c : path)
                    freq[c]++;
                if (isPalindromePermu(freq))
                    count++;
                freq.clear();
                path.pop_back();
                return;
            }
            preorder(node->left);
            preorder(node->right);
            path.pop_back();
        }
    }
    
    int pseudoPalindromicPaths (TreeNode* root) {
        preorder(root);
        return count;
    }
};