#include <iostream>
#include <vector>
#include <string>
#include <stack>
using namespace std;

class Solution {
public:
    string reverseParentheses(string s) {
        string res = "";
        stack<char> stack;
        vector<int> tmp;
        for (char& c : s)
        {
            if (!stack.empty() && c == ')')
            {
                for (;;)
                {
                    if (stack.top() == '(')
                    {
                        stack.pop();
                        break;
                    }
                    tmp.push_back(stack.top());
                    stack.pop();
                }
                for (int& n : tmp)
                    stack.push(n);
                tmp.clear();
            }
            else
                stack.push(c);
        }
        while (!stack.empty())
        {
            res += stack.top();
            stack.pop();
        }
        reverse(begin(res), end(res));
        return res;
    }
};
