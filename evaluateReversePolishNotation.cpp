#include <iostream>
#include <vector>
#include <stack>
#include <string>

using namespace std;

class Solution {
public:
    int eval(int num1, int num2, string op)
    {
        if (op == "+")
            return num1 + num2;
        if (op == "-")
            return num1 - num2;
        if (op == "*")
            return num1 * num2;
        if (op == "/")
            return num1 / num2;
        return -1;
    }
    
    int evalRPN(vector<string>& tokens) {
        stack<string> stack;
        for (string& op : tokens)
        {
            if (op == "+" || op == "-" || op == "*" || op == "/")
            {
                int n1 = stoi(stack.top()); stack.pop();
                int n2 = stoi(stack.top()); stack.pop();
                int res = eval(n2, n1, op);
                stack.push(to_string(res));
            }
            else
                stack.push(op);
        }
        return stoi(stack.top());
    }
};

