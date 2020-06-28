#include <iostream>
#include <vector>
#include <math.h>
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
    vector<int> sequence;
    int totalSum = 0;
    int evaluateBinary(vector<int> s)
    {
        int sum = 0;
        int index = s.size() - 1;
        for (int& num : s)
        {
            if (num == 1)
                sum += pow(2, index);
            index--;
        }
        return sum;
    }
    void preorder(TreeNode* root)
    {
        if (root == nullptr)
            return;
        sequence.push_back(root->val);    
        if (root->left == nullptr && root->right == nullptr)
        {
            totalSum += evaluateBinary(sequence);
            sequence.pop_back();
            return; 
        }
        preorder(root->left);                                                                                                                     
        preorder(root->right);
        sequence.pop_back();
    }
    
    int sumRootToLeaf(TreeNode* root) {
        preorder(root);
        return totalSum;
    }
};