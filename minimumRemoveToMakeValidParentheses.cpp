#include <iostream>
#include <vector>
#include <stack>
#include <string>
using namespace std;

class Solution {
public:
    string minRemoveToMakeValid(string s) {
        // parenthesis and its index in s
        stack<pair<char,int>> stack;
        for (int i = 0; i < s.size(); i++)
        {
            char c = s[i];
            // if a matching bracket is found, pop it off the stack
            if (!stack.empty() && c == ')' && stack.top().first == '(')
                stack.pop();
            // otherwise, push the current char and its index in the string onto stack
            else if (c == ')' || c == '(')
                stack.push(make_pair(c, i));
        }
        
        // for those unmatched brackets, set their value in the original string to a char not included in the input string (such as '!')
        while (!stack.empty())
        {
            s[stack.top().second] = '!';
            stack.pop();
        }
        
        // remove all occurences of these chars to obtain the final valid string
        s.erase(remove(s.begin(), s.end(), '!'), s.end());
        return s;
    }
};
