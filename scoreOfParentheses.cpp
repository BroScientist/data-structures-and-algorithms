#include <iostream>
#include <vector>
#include <stack>
#include <string>
using namespace std;

class Solution {
public:
    int scoreOfParentheses(string S) {
        stack<string> stack;
        for (char& c : S)
        {
            if (c == ')')
            {
                if (stack.top() == "(")
                {
                    // a matching bracket () is equivalent to integer value 1
                    stack.pop();
                    int tmp = 1;
                    
                    // repeatedly pop the stack if the top is a number
                    while (!stack.empty() && stack.top() != ")" && stack.top() != "(")
                    {
                        tmp += stoi(stack.top());
                        stack.pop();
                    }
                    
                    // push the end result of these operations
                    stack.push(to_string(tmp));
                }
                else if (stack.top() != "(" && stack.top() != ")")
                {
                    // if top of the stack is a number and we encountered a closing bracket, this number must be doubled
                    int tmp = stoi(stack.top());
                    
                    // pop twice to pop the number and it's opening bracket
                    stack.pop();
                    stack.pop();
                    tmp *= 2;
                    
                    while (!stack.empty() && stack.top() != ")" && stack.top() != "(")
                    {
                        tmp += stoi(stack.top());
                        stack.pop();
                    }
                    stack.push(to_string(tmp));
                }
            }
            // otherwise, simply convert the character to string and push
            else
                stack.push(string(1, c));
        }
        
        // there will be a single value remaining in the stack afterward, so return the integer form of it
        return stoi(stack.top());
    }
};