#include <iostream>
#include <vector>
#include <map>
#include <stack>

using namespace std;

class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        stack<int> stack;
        map<int, int> hashtable;
        vector<int> res;
        for (int& num : nums2)
        {
            while (!stack.empty() && num > stack.top())
            {
                hashtable.insert(make_pair(stack.top(), num));
                stack.pop();
            }
            stack.push(num);
        }
        while (!stack.empty())
        {
            hashtable.insert(make_pair(stack.top(), -1));
            stack.pop();
        }
        // for (auto& item : hashtable)
        //  cout << item.first << " " << item.second << endl;
        for (int& n : nums1)
            res.push_back(hashtable[n]);
        return res;
    }
};

int main() {

    return 0;
}