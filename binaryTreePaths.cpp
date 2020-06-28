#include <iostream>
#include <vector>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    vector<int> s;
    vector<string> result;
    string str;

    void preorder(TreeNode* root)
    {
        if (root == nullptr)
            return;
        s.push_back(root->val);    

        if (root->left == nullptr && root->right == nullptr)
        {
            for (int i = 0; i < s.size() - 1; i++)
            {
                str += to_string(s[i]);
                str += "->";
            }
            str += to_string(s[s.size() - 1]);
            result.push_back(str);
            str = "";
            // cout << str << endl;   
            s.pop_back();
            return; 
        }
        preorder(root->left);                                                                                                                     
        preorder(root->right);
        s.pop_back();
    }
    
    vector<string> binaryTreePaths(TreeNode* root) {
        preorder(root);
        return result;
    }
};