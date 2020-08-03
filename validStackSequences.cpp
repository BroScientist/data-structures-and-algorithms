#include <iostream>
#include <vector>
#include <stack>
using namespace std;

class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        stack<int> s, s2;
        for (int i = popped.size() - 1; i > -1; i--)
            s2.push(popped[i]);
        for (int& num : pushed)
        {
            s.push(num);
            while (!s.empty() && s.top() == s2.top())
            {
                s.pop();
                s2.pop();
            }
        }
        return s.empty();
    }
};
